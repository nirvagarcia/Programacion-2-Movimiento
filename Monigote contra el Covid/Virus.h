#pragma once
#include "Figura.h"

class Virus : public Figura {
private:
	
public:
	Virus() {

	}
	Virus(int x, int y) :Figura(x, y) {
		int aux = rand() % 2;
		ancho = 9;
		alto = 5;
		if (aux == 0) dy = dx  = 1;
		if (aux == 1) dy = dx = 2;
	}
	void dibujar() {
		Console::SetCursorPosition(x, y);		cout << "    q    ";
		Console::SetCursorPosition(x, y + 1);	cout << "  o-o-o  ";
		Console::SetCursorPosition(x, y + 2);	cout << "o-(ooo)-o";
		Console::SetCursorPosition(x, y + 3);	cout << "  o-o-o  ";
		Console::SetCursorPosition(x, y + 4);	cout << "    b    ";
	}
	void borrar() {
		Console::SetCursorPosition(x, y);		cout << "         ";
		Console::SetCursorPosition(x, y + 1);	cout << "         ";
		Console::SetCursorPosition(x, y + 2);	cout << "         ";
		Console::SetCursorPosition(x, y + 3);	cout << "         ";
		Console::SetCursorPosition(x, y + 4);	cout << "         ";
	}
	void mover() {
		borrar();
		if (x  <= 0 || x  + ancho + dx >= 100) 
			dx *= -1;
		if (y  <= 0 || y  + alto + dy >= 30)
			dy *= -1;
		x += dx;
		y += dy;
		dibujar();
	}
	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x, y, ancho, alto);
	}
};
