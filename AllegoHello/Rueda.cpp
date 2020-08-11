#include "Rueda.h"
#include <iostream>
#include <string>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

double pi = 2 * acos(0.0);

Rueda::Rueda(int target):angulo(0),vuetas(3),targetF(target),background(al_load_bitmap("RuedaFilo.png"))
{
	background = al_load_bitmap("RuedaFilo.png");
}

void Rueda::Draw() 
{
	Girar(targetF);
	al_draw_rotated_bitmap(background, 201, 195, 250, 225, angulo, 0);
	
}

void Rueda::setTargetF(float target) {
	this->targetF = target;
}

void Rueda::Girar(float target) 
{
	if (target != 0) {

		if(this->vuetas != 0 || angulo < target) {
			angulo += 4*pi/180;
			if (angulo >= 6.2) {
				this->vuetas--;
				angulo = 0;
			}
		}
		
	}
	else if (target >= angulo && vuetas == 0) {
		vuetas = 3;
		setTargetF(0);
		angulo = 0;
	}
}

void Rueda::setAngulo(float _angulo) {
	this->angulo = _angulo;
}