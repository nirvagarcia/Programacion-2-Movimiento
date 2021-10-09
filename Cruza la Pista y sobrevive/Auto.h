#pragma once //mi hijo
#include "Movil.h"

class Auto :public Movil {

private:

public:


	Auto() {

		dx = (rand() % 2) * (2) - 1; //formulita matematica que te da el maximo o minimo (1-2)
		ancho = 8;
		alto = 3;
		dibujo.push_back("____|~\_ ");//push back es agregar al final
		dibujo.push_back("[___|_|- ");//vemos que esta es la linea mas larga, con 8 de ancho
		dibujo.push_back("(_) (_) ");

	}

	~Auto() {}




};
