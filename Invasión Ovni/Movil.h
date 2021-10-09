#pragma once
#include <string>
#include <iostream>
using namespace std;
using namespace System;

class Movil {

protected:

	int x, y, ancho, alto, dy;
	string* dibujo;

public:

	Movil() {
		//el resto depende de cada uno
		dy = 1;
		y = 2;
	}

	~Movil() { delete[] dibujo; }


	void borrar() {

		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				Console::SetCursorPosition(x + j, y + i);
				cout << " ";
			}
		}
	}

	void mover() {

		if (y + dy < 0 || y + dy+alto>29) {
			dy = -dy;
		}
		y += dy;

	}

	void dibujar() {

		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				Console::SetCursorPosition(x , y + i);
				cout << dibujo[i];
			}
		}
	}
};
