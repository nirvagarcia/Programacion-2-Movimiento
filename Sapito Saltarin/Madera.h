#pragma once
#include "Figura.h"

class Madera : public Figura {
private:
public:
	Madera() : Figura() {
		dx = 1;
		dy = 0;
		ancho = 9;
		alto = 1;

	}
	~Madera() {

	}
	void dibujar() {
		Console::SetCursorPosition(x, y); cout << "=========";
	}
	void borrar() {
		Console::SetCursorPosition(x, y); cout << "         ";
	}
	void mover() {
		borrar();
		if (x + dx == 0 || x + ancho + dx == 100)
			dx *= -1;
		x += dx;
		dibujar();
	}
};
