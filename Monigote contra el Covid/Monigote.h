#pragma once
#include "Figura.h"

class Monigote : public Figura {
private:
	int vidas;
	bool inmunidad;
public:
	Monigote() {

	}
	Monigote(int x, int y): Figura(x,y) {
		vidas = 3;
		ancho = 1;
		alto = 2;
		dx = dy = 1;
		inmunidad = false;
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);		cout << char(48);
		Console::SetCursorPosition(x, y + 1);	cout << char(197);
	}
	void borrar() {
		Console::SetCursorPosition(x, y);		cout << " ";
		Console::SetCursorPosition(x, y + 1);	cout << " ";
	}
	void mover(char tecla) {
		borrar();
		switch (tecla) {
		case 'A':
			if (x - dx != 0)
				x -= dx;
			break;
		case 'D':
			if (x + dx != 110)
				x += dx;
			break;
		case 'W':
			if (y - dy != 0)
				y -= dy;
			break;
		case 'S':
			if (y + dy + alto != 35)
				y += dy;
			break;
		}
		dibujar();
	}
	int getVidas() { return this->vidas; }
	void setVidas(int vidas) { this->vidas = vidas; }
	
	bool getInmunidad() { return this->inmunidad; }
	void setInmunidad(bool inmunidad) { this->inmunidad = inmunidad; }

	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x, y, ancho, alto);
	}
};
