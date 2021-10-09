#pragma once
#include "Figura.h"

class Vacuna : public Figura {
private:
	int dir;
public:
	Vacuna() {

	}
	Vacuna(int x, int y) :Figura(x, y) {
		ancho = 4;
		alto = 1; 
		dir = rand() % 2;
		if (dir == 0) {
			dx = 1;
			dy = 0;
		}
		else {
			dy = 1; 
			dx = 0;
		}
	}
	~Vacuna() {

	}
	void dibujar() {
		Console::SetCursorPosition(x, y); cout << "|->|";
	}
	void borrar() {
		Console::SetCursorPosition(x, y); cout << "    ";
	}
	void mover() {
		borrar();
		if (x + dx == 0 || x + dx + ancho == 100)
			dx *= -1;
		if (y + dy == 0 || y + dy + alto == 30)
			dy *= -1;
		x += dx;
		y += dy;
		dibujar();
	}

	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x, y, ancho, alto);
	}
};
