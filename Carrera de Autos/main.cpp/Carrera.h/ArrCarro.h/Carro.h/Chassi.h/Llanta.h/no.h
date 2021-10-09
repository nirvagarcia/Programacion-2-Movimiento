#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Chassi {

private:
	int x;
	int y;
	int ancho; 
public:

	Chassi(int Y) {
		x = 3;
		y = Y;
		ancho = 9;
	}

	~Chassi() {};

	void borrar() {
		
		for (int i = 0; i < ancho; i++) {
			Console::SetCursorPosition(x+i, y);
			cout << " ";
		}				
	}

	void mover() { 

		x++; 

	}

	void dibujar() {
		
		for (int i = 0; i < ancho; i++) {
			Console::SetCursorPosition(x + i, y);
			cout << "█";
		}
		
	}


	int getpunta() { return x + ancho; } 
};
