#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Chassi {

private:
	int x;
	int y;
	int ancho; //pq es mas grande puem

public:

	Chassi(int Y) {
		x = 3;
		y = Y;
		ancho = 9;
	}

	~Chassi() {};

	void borrar() {
		//usamos un for para borrar todo el ancho del chasi, caracter por caracter
		for (int i = 0; i < ancho; i++) {
			Console::SetCursorPosition(x+i, y);
			cout << " ";
		}				
	}

	void mover() { //como solo se mueven a la derecha

		x++; //aumentamos el horizontal 1+1 pq solo va a derecha

	}

	void dibujar() {
		//usamos un for para dibujar todo el ancho del chasi, pixel por pixel
		for (int i = 0; i < ancho; i++) {
			Console::SetCursorPosition(x + i, y);
			cout << "█";
		}
		
	}


	int getpunta() { return x + ancho; } //esto nos dirá la posicion donde termina la naircita del carro, sería x(el inicio)+ ancho=el pixel final

};
