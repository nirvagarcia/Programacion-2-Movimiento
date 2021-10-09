#pragma once
#include "Movil.h"


class Alfa: public Movil {

public:

	Alfa() {
		
		x = rand() % (30 - 1 + 1) + 1; //posicionado aleatoreamente en la izquierda
		alto = 5;
		ancho = 19;		
		dibujo = new string[alto];
		
		dibujo[0] = "      _.---._ 		";
		dibujo[1] = "    .'       '.	";
		dibujo[2] = "_.-~===========~-._";
		dibujo[3] = "(_________________)";
		dibujo[4] = "     \_______/     ";		
	}

	~Alfa() {  }
};
