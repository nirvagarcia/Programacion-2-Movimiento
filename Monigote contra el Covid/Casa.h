#pragma once
#include "Figura.h"

class Casa : public Figura {
private:

public:
	Casa() {

	}
	Casa(int x, int y) :Figura(x, y) {
		dx = dy = 0;
		alto = 4;
		ancho = 13;
	}
	~Casa() {

	}
	void dibujar() {
		Console::SetCursorPosition(x, y);		cout << "   ___I_    ";
		Console::SetCursorPosition(x, y + 1);	cout << "  /\\-_--\\ ";
		Console::SetCursorPosition(x, y + 2);	cout << " /  \\_-__\\";
		Console::SetCursorPosition(x, y + 3);	cout << " |[]| [] |  ";
	}

	System::Drawing::Rectangle getRectangle() {
		return System::Drawing::Rectangle(x, y, ancho, alto);
	}
};
