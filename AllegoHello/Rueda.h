#pragma once
#ifndef RUEDA_H
#define RUEDA_H
#include <allegro5/allegro.h>
class Rueda {
private:
	float angulo,targetF;
	int vuetas;
	ALLEGRO_BITMAP* background;
public:
	Rueda(int);
	void Draw();
	void setTargetF(float);
	void Girar(float);
	void setAngulo(float);
	float getAngulo();
};
#endif // !RUEDA_H
