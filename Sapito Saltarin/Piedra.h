#pragma once
#include "Figura.h"

class Piedra : public Figura {
private:
public:
	Piedra() : Figura() {
		dx = 1;
		dy = 0;
		ancho = 7;
		alto = 1;

	}
	~Piedra() {

	}
	void dibujar() {
		Console::SetCursorPosition(x, y); cout << "ooooooo";
	}
};
