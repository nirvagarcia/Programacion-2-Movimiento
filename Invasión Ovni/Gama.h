#pragma once
#include "Movil.h"


class Gamma : public Movil {

public:

	Gamma() {

		x = rand() % (90 - 60 + 1) + 60; //posicionado aleatoreamente en la izquierda
		alto = 10;
		ancho = 19;		
		dibujo = new string[alto];		
		dibujo[0] = "          .            ";
		dibujo[1] = " 	       |            ";
		dibujo[2] = " 	   .-' ^ '-.     ";
		dibujo[3] = " 	  /_......._\\       ";
		dibujo[4] = "  .-'`         `'-. ";
		dibujo[5] = " ( ooo   ooo   ooo )  ";
		dibujo[6] = "  '-.,_________,.-'   ";
		dibujo[7] = "     /         \\     ";
		dibujo[8] = "   _/           \\_   ";
		dibujo[9] = "  `'`           `'` ";		
	}

	~Gamma() {  }
};
