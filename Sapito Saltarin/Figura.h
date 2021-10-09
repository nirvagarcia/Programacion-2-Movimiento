#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;
using namespace System::Drawing;

class Figura {
protected:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
public:
	Figura() {
		this->x = rand() % 75 + 5;
		this->y = rand() % 22 + 2;
	}
	Figura(int x, int y) {
		this->x = x;
		this->y = y;
	}
	~Figura() {

	}
	int getX() { return this->x; }
	int getY() { return this->y; }
	int getDx() { return this->dx; }
	int getDy() { return this->dy; }
	int getAncho() { return this->ancho; }
	int getAlto() { return this->alto; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setDx(int dx) { this->dx = dx; }
	void setDy(int dy) { this->dy = dy; }
	void setAncho(int ancho) { this->ancho = ancho; }
	void setAlto(int alto) { this->alto = alto; }

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho, alto);
	}
};
