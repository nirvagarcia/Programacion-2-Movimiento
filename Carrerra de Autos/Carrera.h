#pragma once
#include "ArrCarro.h"

class Carrera {

private:

	int n;
	ArrCarro* arr; //creamos el arreglo derivado a carros


public:

	Carrera() {
		
		arr = new ArrCarro();
		for (int i = 0; i < 4; i++) {
			arr->agregarCarro(new Carro(i * 4 + 3)); //altura inicial 3, con 4 de distancia entre cada carro
		}

	}

	~Carrera() {};

	bool jugar() {

		bool termino = false;
		int auxi = rand() % arr->size();


		for (int i = 0; i < arr->size(); i++) {

			arr->at(i)->borrar();
			if(i==auxi)
			arr->at(i)->mover();
			arr->at(i)->dibujar();
			if (arr->at(i)->getpunta() > 100) { termino = true; }//si la punta del carro llega a 80, la meta, termino true
		}
		return termino;

	}


};
