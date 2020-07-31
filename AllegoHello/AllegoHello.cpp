

#include <iostream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

using namespace std;


void must_init(bool test, const char* description)
{
    if (test) return;

    printf("couldn't initialize %s\n", description);
    exit(1);
}

void boton(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* imagen)
{
    al_clear_to_color(al_map_rgb(255, 255, 255));


    al_draw_bitmap(imagen, 0, 0, 0);
    al_draw_text(font, al_map_rgb(0, 0, 0), 0, 0, 0, "Hola Mundo");

    al_draw_filled_rectangle(520, 0, 640, 60, color);
    al_draw_text(font, al_map_rgb(0, 0, 0), 525, 5, 0, "Salir");
    al_flip_display();
}

int main()
{
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_DISPLAY* disp = al_create_display(640, 480);
    must_init(disp, "display");

    ALLEGRO_FONT* font = al_load_ttf_font("YARDSALE.ttf", 64, 0);
    ALLEGRO_FONT* font2 = al_load_ttf_font("YARDSALE.ttf", 36, 0);

    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 30.0);
    must_init(timer, "timer");

    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    must_init(queue, "queue");


    must_init(al_init_image_addon(), "image");

    must_init(al_install_mouse(), "mouse");

    must_init(al_init_primitives_addon(), "primitives");

    ALLEGRO_BITMAP* imagen = al_load_bitmap("background.jpg");
    if (!imagen)
    {
        printf("no se cargo el background\n");
        return 1;
    }

    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_mouse_event_source());

    bool done = false;
    ALLEGRO_EVENT event;

    ALLEGRO_COLOR azul = al_map_rgba_f(0, 0, 0.5, 0.5);
    ALLEGRO_COLOR rojo = al_map_rgba_f(0.5, 0, 0, 0.5);

    //Correr una vez
    al_clear_to_color(al_map_rgb(255, 255, 255));


    al_draw_bitmap(imagen, 0, 0, 0);
    al_draw_text(font, al_map_rgb(0, 0, 0), 0, 0, 0, "Hola Mundo");

    al_draw_filled_rectangle(520, 0, 640, 60, azul);
    al_draw_text(font2, al_map_rgb(0, 0, 0), 525, 5, 0, "Salir");
    al_flip_display();

    while (true) {
        ALLEGRO_COLOR color = azul;
        

        al_wait_for_event(queue, &event);
        

        switch (event.type)
        {
        case ALLEGRO_EVENT_MOUSE_AXES:
            if (event.mouse.x >= 525 && event.mouse.y <= 60) {
                color = rojo;
                boton(font2, color, imagen);
            }
            else {
                color = azul;
                boton(font2, color, imagen);
            }
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if ((event.mouse.x >= 525 && event.mouse.y <= 60)) {
                done = true;
            }
            break;

        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;
        }

        if (done)
            break;

    }

    al_destroy_bitmap(imagen);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_font(font);
    al_destroy_font(font2);

    return 0;
}

