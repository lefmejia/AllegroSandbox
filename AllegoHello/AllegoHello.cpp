#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "Rueda.h"

/*Nota:
    1- Las esctuturas estan al principio y el main al final.
    2- Se cambiaron algunas variable a globales para reciclar.
    3- Al hacer el cambio de pantalla mover el mouse
*/

using namespace std;
//variables globales
ALLEGRO_COLOR azul = al_map_rgba_f(0, 0, 0.5, 0.5);
ALLEGRO_COLOR rojo = al_map_rgba_f(0.5, 0, 0, 0.5);

ALLEGRO_EVENT event;
ALLEGRO_EVENT_QUEUE* queue;

//explicacion pendiente
int cargar;

//Declarar funciones
void cambioMap(ALLEGRO_FONT*, ALLEGRO_COLOR, ALLEGRO_BITMAP*, int);
bool entrarNivel1(ALLEGRO_FONT*, ALLEGRO_COLOR, ALLEGRO_BITMAP*, int);
bool entrarNivel2(ALLEGRO_FONT*, ALLEGRO_COLOR, ALLEGRO_BITMAP*, int);
bool entrarNivel3(ALLEGRO_FONT*, ALLEGRO_COLOR, ALLEGRO_BITMAP*, int);

void must_init(bool test, const char* description)
{
    if (test) return;
    printf("couldn't initialize %s\n", description);
    exit(1);
}

//aqui cargamos el texto y el boton de salir 

void boton1(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background)
{
    al_draw_text(font, al_map_rgb(0, 0, 0), 300, 0, 0, "Filosofia");
    al_draw_filled_rectangle(300, 350, 500, 400, color);
    al_draw_text(font, al_map_rgb(0, 0, 0), 340, 350, 0, "Salir");
    al_flip_display();
}

void boton2(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background)
{
    al_draw_filled_rectangle(200, 300, 600, 250, color);
    al_draw_text(font, al_map_rgb(0, 0, 0), 250, 250, 0, "Puntuaciones");
    al_flip_display();
}

void boton3(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background)
{
    al_draw_filled_rectangle(300, 200, 500, 135, color);
    al_draw_text(font, al_map_rgb(0, 0, 0), 340, 150, 0, "Mapa");
    al_flip_display();
}

//estructura boton volver de las pantallas
void botonVolver(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background)
{
    al_draw_filled_rectangle(670, 0, 800, 60, color);
    al_draw_text(font, al_map_rgb(0, 0, 0), 675, 5, 0, "Salir");
    al_flip_display();
}
//Esctructura de la pantallas
bool estruPunt(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background)
{
    //pantalla de puntuacion
    queue = al_create_event_queue();
    must_init(queue, "queue");
    must_init(al_init_image_addon(), "image");
    must_init(al_install_mouse(), "mouse");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());

    bool done = false;
    //Cargar imagen y posicionar (Correr una vez)
    background = al_load_bitmap("puntuacion.jpeg");;
    al_draw_bitmap(background, 0, 0, 0);
    al_draw_text(font, al_map_rgb(0, 0, 0), 200, 0, 0, "Puntuaciones");

    while (true) {
        color = azul;
        al_wait_for_event(queue, &event);
        switch (event.type)
        {
        case ALLEGRO_EVENT_MOUSE_AXES:
            //pasa por cierto rango cambia de color
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 60) {
                color = rojo;
                botonVolver(font, color, background);
            }
            else {
                color = azul;
                botonVolver(font, color, background);
            }
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            //al precionar el boton sale
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 100) {
                done = true;
                color = azul;
            }
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                //al precionar esc vuelve al inicio
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    //imprimir en pantalla para comprobar que se preciono la tecla
                    std::cout << "ESCAPE, SALIENDO...\n";
                    done = true;
                    color = azul;
                    break;
                }
            }
            break;
        }

        if (done) {
            cargar = 0;
            return true;
        }
    }
}

bool estruMap(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background)
{
    
    int currentMap = 1;
    //pantalla de mapa
    //Registro de mouse y teclado
    queue = al_create_event_queue();
    must_init(queue, "queue");
    must_init(al_init_image_addon(), "image");
    must_init(al_install_mouse(), "mouse");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());

    bool done = false;
    //Cargar imagen y posicionar (Correr una vez)
    //imagen temporal
    background = al_load_bitmap("mapa.jpg");;
    al_draw_bitmap(background, 0, 0, 0);
    al_draw_text(font, al_map_rgb(0, 0, 0), 300, 0, 0, "Mapa");
    al_draw_filled_rectangle(150, 50, 170, 100, al_map_rgb(255, 0, 0));
    al_draw_filled_triangle(140, 100, 180, 100, 160, 130, al_map_rgb(255, 0, 0));

    //bool refresh es para cargar el mapa nuevamente cuando se regresa de un nivel
    bool refresh = true;
    while (true) {
        color = azul;
        if (refresh) {
            refresh = false;
            cambioMap(font, color, background, currentMap);
        }
        al_wait_for_event(queue, &event);
        
        switch (event.type)
        {
        case ALLEGRO_EVENT_MOUSE_AXES:
            //pasa por cierto rango cambia de color
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 60) {
                color = rojo;
                botonVolver(font, color, background);
            }
            else {
                color = azul;
                botonVolver(font, color, background);
            }
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            //al precionar el boton sale
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 100) {
                done = true;
                color = azul;
            }
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                //al precionar esc vuelve al inicio
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    //imprimir en pantalla para comprobar que se preciono la tecla
                    std::cout << "ESCAPE, SALIENDO...\n";
                    done = true;
                    color = azul;
                    break;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                    if (currentMap == 1) {
                        currentMap = 2;
                    }
                    else if (currentMap == 2) {
                        currentMap = 3;
                    }
                    cambioMap(font, color, background, currentMap);
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                    if (currentMap == 3) {
                        currentMap = 2;

                    }
                    else if (currentMap == 2) {
                        currentMap = 1;
                    }
                    cambioMap(font, color, background, currentMap);
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_ENTER) {
                    if (currentMap == 1)
                    {
                        entrarNivel1(font, color, background, currentMap);
                    }
                    else if (currentMap == 2)
                    {
                        entrarNivel2(font, color, background, currentMap);
                    }
                    else if (currentMap == 3)
                    {
                        entrarNivel3(font, color, background, currentMap);
                    }
                    refresh = true;
                }
            }
            break;
        }

        if (done) {
            cargar = 0;
            return true;
        }
    }
}

void cambioMap(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background, int currentMap) {
    //al_destroy_bitmap(background);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    background = al_load_bitmap("mapa.jpg");
    al_draw_bitmap(background, 0, 0, 0);
    al_draw_text(font, al_map_rgb(0, 0, 0), 300, 0, 0, "Mapa");
    botonVolver(font, color, background);

    if (currentMap == 1)
    {
        al_draw_filled_rectangle(150, 50, 170, 100, al_map_rgb(255, 0, 0));
        al_draw_filled_triangle(140, 100, 180, 100, 160, 130, al_map_rgb(255, 0, 0));
    }
    else if (currentMap == 2)
    {
        al_draw_filled_rectangle(390, 300, 410, 350, al_map_rgb(255, 0, 0));
        al_draw_filled_triangle(380, 350, 420, 350, 400, 380, al_map_rgb(255, 0, 0));
    }
    else if (currentMap == 3)
    {
        al_draw_filled_rectangle(550, 50, 570, 100, al_map_rgb(255, 0, 0));
        al_draw_filled_triangle(540, 100, 580, 100, 560, 130, al_map_rgb(255, 0, 0));
    }
    al_flip_display();
}

//Nivel 1, 2 y 3 temporal, copia de estruMap solo tiene el boton de regresar

bool entrarNivel1(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background, int currentMap) {

    al_clear_to_color(al_map_rgb(0, 0, 0));
    queue = al_create_event_queue();
    must_init(queue, "queue");
    must_init(al_init_image_addon(), "image");
    must_init(al_install_mouse(), "mouse");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool done = false;

    background = al_load_bitmap("nivel1.jpg");;
    al_draw_bitmap(background, 0, 0, 0);
    al_draw_text(font, al_map_rgb(0, 0, 0), 300, 0, 0, "Nivel 1");
    //botonVolver(font, color, background);
    Rueda rueda(0);
    al_start_timer(timer);
    while (true) {
        color = azul;
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_bitmap(background, 0, 0, 0);
        al_draw_text(font, al_map_rgb(0, 0, 0), 300, 0, 0, "Nivel 1");
        //botonVolver(font, color, background);
        rueda.Draw();
        al_flip_display();
        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_MOUSE_AXES:
            //pasa por cierto rango cambia de color
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 60) {
                color = rojo;
                //botonVolver(font, color, background);
                
            }
            else {
                color = azul;
                //botonVolver(font, color, background);
            }
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 100) {
                done = true;
                color = azul;
            }
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    done = true;
                    color = azul;
                    break;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_G) {
                    rueda.setTargetF(3);
                    break;
                }
                else if (event.keyboard.keycode == ALLEGRO_KEY_R) {
                    rueda.setTargetF(0);
                    rueda.setAngulo(0);
                    break;
                }
               
            }
            break;

        case ALLEGRO_EVENT_TIMER:
            break;
        }
        if (done) {
            cargar = 0;
            return true;
        }
    }
}

bool entrarNivel2(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background, int currentMap) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    queue = al_create_event_queue();
    must_init(queue, "queue");
    must_init(al_init_image_addon(), "image");
    must_init(al_install_mouse(), "mouse");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());

    bool done = false;

    background = al_load_bitmap("nivel2.jpg");;
    al_draw_bitmap(background, 0, 0, 0);
    al_draw_text(font, al_map_rgb(0, 0, 0), 300, 0, 0, "Nivel 2");
    botonVolver(font, color, background);
    while (true) {
        color = azul;

        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_MOUSE_AXES:
            //pasa por cierto rango cambia de color
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 60) {
                color = rojo;
                botonVolver(font, color, background);
            }
            else {
                color = azul;
                botonVolver(font, color, background);
            }
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 100) {
                done = true;
                color = azul;
            }
            break;
            
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    done = true;
                    color = azul;
                    break;
                }

            }
            break;
        }

        if (done) {
            cargar = 0;
            return true;
        }
    }
}

bool entrarNivel3(ALLEGRO_FONT* font, ALLEGRO_COLOR color, ALLEGRO_BITMAP* background, int currentMap) {
    al_clear_to_color(al_map_rgb(0, 0, 0));
    queue = al_create_event_queue();
    must_init(queue, "queue");
    must_init(al_init_image_addon(), "image");
    must_init(al_install_mouse(), "mouse");
    must_init(al_install_keyboard(), "keyboard");
    must_init(al_init_primitives_addon(), "primitives");
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_keyboard_event_source());

    bool done = false;

    background = al_load_bitmap("nivel3.jpg");;
    al_draw_bitmap(background, 0, 0, 0);
    al_draw_text(font, al_map_rgb(0, 0, 0), 300, 0, 0, "Nivel 3");
    botonVolver(font, color, background);
    while (true) {
        color = azul;

        al_wait_for_event(queue, &event);

        switch (event.type)
        {
        case ALLEGRO_EVENT_MOUSE_AXES:
            //pasa por cierto rango cambia de color
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 60) {
                color = rojo;
                botonVolver(font, color, background);
            }
            else {
                color = azul;
                botonVolver(font, color, background);
            }
            break;

        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (event.mouse.x > 670 && event.mouse.x < 800 && event.mouse.y>0 && event.mouse.y < 100) {
                done = true;
                color = azul;
            }
            break;
        case ALLEGRO_EVENT_KEY_DOWN:
            if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    done = true;
                    color = azul;
                    break;
                }

            }
            break;
        }

        if (done) {
            cargar = 0;
            return true;
        }
    }
}

//Must init que atrapa cualquier error
int main()
{
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_DISPLAY* display = al_create_display(800, 450);
    must_init(display, "display");

    ALLEGRO_FONT* font = al_load_ttf_font("YARDSALE.ttf", 64, 0);
    ALLEGRO_FONT* font2 = al_load_ttf_font("YARDSALE.ttf", 36, 0);

    queue = al_create_event_queue();
    must_init(queue, "queue");

    must_init(al_init_image_addon(), "filo_background");

    must_init(al_install_mouse(), "mouse");

    must_init(al_init_primitives_addon(), "primitives");

    ALLEGRO_BITMAP* background = al_load_bitmap("filo_background.jpeg");
    if (!background)
    {
        printf("No se cargo el background\n");
        return 1;
    }

    al_register_event_source(queue, al_get_mouse_event_source());

    bool done = false;

    cargar = 0;

    while (true) {
        if (cargar == 0) {
            cargar = 1;
            //Correr una vez
            al_clear_to_color(al_map_rgb(255, 255, 255));

            al_draw_bitmap(background, 0, 0, 0);
            al_draw_text(font2, al_map_rgb(0, 0, 0), 300, 0, 0, "Filosofia");

            al_draw_filled_rectangle(300, 200, 500, 135, azul);
            al_draw_text(font2, al_map_rgb(0, 0, 0), 340, 150, 0, "Mapa");
            al_flip_display();

            al_draw_filled_rectangle(200, 300, 600, 250, azul);
            al_draw_text(font2, al_map_rgb(0, 0, 0), 250, 250, 0, "Puntuaciones");
            al_flip_display();

            al_draw_filled_rectangle(300, 350, 500, 400, azul);
            al_draw_text(font2, al_map_rgb(0, 0, 0), 340, 350, 0, "Salir");
            al_flip_display();
        }
        ALLEGRO_COLOR color = azul;
        al_wait_for_event(queue, &event);
        //Rango de cambio de colores para salir
        bool over_salir = event.mouse.x > 300 && event.mouse.x < 500 && event.mouse.y>350 && event.mouse.y < 400;
        //Rango de cambio de colores para puntuaciones
        bool over_points = event.mouse.x > 200 && event.mouse.x < 600 && event.mouse.y>250 && event.mouse.y < 300;
        //Rango de cambio de colores para mapa
        bool over_map = event.mouse.x > 300 && event.mouse.x < 500 && event.mouse.y>100 && event.mouse.y < 200;

        switch (event.type)
        {
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
            if (over_salir) {
                done = true;
                color = azul;
                boton1(font2, color, background);
            }
            else if (over_points) {
                color = azul;
                boton2(font2, color, background);
                //pantalla puntuacion
                estruPunt(font2, color, background);
            }
            else if (over_map) {
                color = azul;
                boton3(font2, color, background);
                //pantalla mapa
                estruMap(font2, color, background);
            }
            break;

        case ALLEGRO_EVENT_MOUSE_AXES:
            if (event.mouse.x > 300 && event.mouse.x < 500 && event.mouse.y>350 && event.mouse.y < 400) {
                color = rojo;
                boton1(font2, color, background);

                color = azul;
                boton2(font2, color, background);
                boton3(font2, color, background);

            }
            else if (over_points)
            {
                color = rojo;
                boton2(font2, color, background);

                color = azul;
                boton1(font2, color, background);
                boton3(font2, color, background);

            }
            else if (over_map) {
                color = rojo;
                boton3(font2, color, background);
                color = azul;
                boton1(font2, color, background);
                boton2(font2, color, background);
            }

            else {
                color = azul;
                boton1(font2, color, background);
                boton2(font2, color, background);
                boton3(font2, color, background);
            }
            break;
        }

        if (done)
            break;

    }

    al_destroy_bitmap(background);
    al_destroy_display(display);
    al_destroy_event_queue(queue);
    al_destroy_font(font);
    al_destroy_font(font2);

    return 0;
}
//Proyecto 