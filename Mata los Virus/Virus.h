#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;

class Virus {
private:
	int x;
	int y;
	int dx;
	int dy;
	int ancho; 
	int alto;
	char letalidad;

public:
	Virus() {

	}
	Virus(int x, int y) {
		int aux = rand() % 2;
		if (aux == 0) dx = dy = 1;
		else dx = dy = 2;
		if (x % 2 != 0) x = x + 1;
		if (y % 2 != 0) y = y + 1;
		ancho = 9;
		alto = 5;
		this->x = x;
		this->y = y;
		letalidad = rand() % 5 + 49;
	}
	~Virus() {

	}
	void dibujar() {
		Console::SetCursorPosition(x, y);		cout << "    q    ";
		Console::SetCursorPosition(x, y + 1);	cout << "  o-o-o  ";
		Console::SetCursorPosition(x, y + 2);	cout << "o-(o" << letalidad << "o)-o";
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
		if (x <= 0 || x + ancho + dx >= 100)
			dx *= -1;
		if (y <= 0 || y + alto + dy >= 30)
			dy *= -1;
		x += dx;
		y += dy;
		dibujar();
	}

	int getX() { return this->x; }
	int getY() { return this->y; }
	int getDx() { return this->dx; }
	int getDy() { return this->dy; }
	int getAncho() { return this->ancho; }
	int getAlto() { return this->alto; }
	int getLetalidad() { return this->letalidad; }

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setDx(int dx) { this->dx = dx; }
	void setDy(int dy) { this->dy = dy; }
	void setAncho(int ancho) { this->ancho = ancho; }
	void setAlto(int alto) { this->alto = alto; }
};
