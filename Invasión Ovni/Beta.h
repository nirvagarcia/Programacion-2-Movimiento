#pragma once
#include "Movil.h"


class Beta : public Movil {

public:

	Beta() {

		x = rand() % (60 - 30 + 1) + 30; //posicionado aleatoreamente en la izquierda
		alto = 3;
		ancho = 11;		
		dibujo = new string[alto];	
		dibujo[0] = "   .---.   ";
		dibujo[1] = " _/__~0_\\_ ";
		dibujo[2] = "(_________)";				
	}

	~Beta() {  }
};
