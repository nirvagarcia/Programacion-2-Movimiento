#pragma once
#include "Figura.h"

class Sapo : public Figura {
private:
	int salto;
	bool madera;
public:
	Sapo() {

	}
	Sapo(int x, int y) :Figura(x, y) {
		dx = 1;
		dy = 1;
		salto = 5;
		ancho = 8;
		alto = 4;
		madera = false;
	}
	~Sapo() {

	}
	void dibujar() {
		Console::SetCursorPosition(x, y);		cout << "  @..@  ";
		Console::SetCursorPosition(x, y + 1);	cout << " (----) ";
		Console::SetCursorPosition(x, y + 2);	cout << "< I  I >";
		Console::SetCursorPosition(x, y + 3);	cout << "  \"  \"  ";
	}
	void borrar() {
		Console::SetCursorPosition(x, y);		cout << "        ";
		Console::SetCursorPosition(x, y + 1);	cout << "        ";
		Console::SetCursorPosition(x, y + 2);	cout << "        ";
		Console::SetCursorPosition(x, y + 3);	cout << "        ";
	}
	void mover(char tecla) {
		borrar();
		switch (tecla) {
		case 'A':
			if (x - dx != 0)
				x -= dx;
			break;
		case 'D':
			if (x + ancho + dx != 100)
				x += dx;
			break;
		case 'S':
			y -= salto;
			break;
		case 'B':
			y -= dy;
			break;
		}
		dibujar();
	}
	void mover_autonomo() {
		borrar();
		if (x + dx == 0 || x + ancho + dx == 100)
			dx *= -1;
		x += dx;
		dibujar();
	}

	bool getMadera() { return this->madera; }
	void setMadera(bool madera) { this->madera = madera; }
};
