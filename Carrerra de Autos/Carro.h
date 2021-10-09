#pragma once
#include <iostream>
#include "Chassi.h"
#include "Llanta.h"
using namespace std;
using namespace System;

class Carro {

private:
	Chassi* cha; //creamos objetos de lo que tendrá el carro
	Llanta* lla1;
	Llanta* lla2; 
	Llanta* lla3; 
	Llanta* lla4;  

public:

	Carro(int Y) {		
		cha = new Chassi(Y); //TODOS con el mismo y pq inician en la misma coordenada de izquierda, pero diferente x
		lla1=new Llanta(3,Y-1); //llanta izquierda abajo
		lla2=new Llanta(3,Y+1);//llanta izquierda arriba
		lla3=new Llanta(8,Y-1);//llanta derecha abajo
		lla4=new Llanta(8,Y+1);//llanta derecha arriba
	}

	~Carro() {};

	void borrar() { //borramos cada parte del carro, osea cada objeto creado arriba
		
		cha	->borrar();
		lla1->borrar();
		lla2->borrar();
		lla3->borrar();
		lla4->borrar();		
	}

	void mover() {

		cha->mover();
		lla1->mover();
		lla2->mover();
		lla3->mover();
		lla4->mover();	
	}

	void dibujar() {
		
		cha->dibujar();
		lla1->dibujar();
		lla2->dibujar();
		lla3->dibujar();
		lla4->dibujar();
	}


	int getpunta() { return cha->getpunta(); } //aca tenemos la coordenada de la punta del carro para ver si llegó

};
