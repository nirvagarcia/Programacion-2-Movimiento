#pragma once //mi hijo
#include "Movil.h"

class Bici :public Movil {

private:

public:

	
	Bici() {
		
		dx = (rand() % 2) * (2) - 1; //esto me dará un numero positivo o negativo, osea izquierda o derecha
		ancho = 6;
		alto = 2;			 
		dibujo.push_back(".._\\");//push back es agregar al final
		dibujo.push_back("(o)(o)");//vemos que esta es la linea mas larga, con 6 de ancho


	}

	~Bici() {}


	bool colision(Rectangle rec) { return false; } //su colicion es que si choca no hay consecuencias, es la bici




};
