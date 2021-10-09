#pragma once //mi hijo
#include "Movil.h"

class Jugador :public Movil {

private:

public:

	Jugador() {
		x=119/2; //formulita matematica que te da el maximo o minimo (1-2)
		y = 29 -1;
		ancho = 1;
		alto = 1;
		velocidad = 0;
		dibujo.push_back("■");//vemos que esta es la linea mas larga, con 1 de ancho
		
	}

	~Jugador() {}

	void movimientoInvalido(int n) { dx = 0; dy = 0; }
	void tecla(int edx, int edy) { dx = edx; dy = edy; }

	void reposicionar() {
		x = 119 / 2; //lo colocamos en su posicion inicial
		y = 29 - 1;
	}



};
