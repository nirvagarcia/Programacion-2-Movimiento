#pragma once //mi hijo
#include "Movil.h"

class Bus :public Movil {

private:

public:


	Bus() {

		dx = (rand() % 2) * (2) - 1; //formulita matematica que te da el maximo o minimo (1-2)
		ancho = 20;
		alto = 4;
		dibujo.push_back("   ________________ ");//push back es agregar al final
		dibujo.push_back(" _/_|[][][][][][][]|");//vemos que esta es la linea mas larga, con 20 de ancho
		dibujo.push_back("(                  |");
		dibujo.push_back(" =--OO---------OO-=");
	}

	~Bus() {}




};
