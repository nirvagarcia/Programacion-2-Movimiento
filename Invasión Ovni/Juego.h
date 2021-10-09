#pragma once
#include "ArrNaves.h"
#include "Alfa.h"
#include "Beta.h"
#include "Gama.h"


class Juego {

private:

	ArrNaves* arr;
	int contA, contB, contGeneral;

public:

	Juego() {
		arr = new ArrNaves();
		contA = 0;
		contB = 0;
		contGeneral = 0;
	}

	~Juego() { delete arr; }

	void tecla() {
		arr->agregar(new Alfa());
		contA++; contGeneral++;
		if (contA % 2 == 0) {
			arr->agregar(new Beta());
			contB++; contGeneral++;
			if (contB % 2 == 0) {
				arr->agregar(new Gamma()); contGeneral++;
			}
		}
		
	}

	bool jugar() {
		Console::SetCursorPosition(1, 1); 
		cout<<"\t| Total Naves: "<<  contGeneral<< " |";
		
		for (int i = 0; i < arr->size(); i++) {
			arr->at(i)->borrar();
			arr->at(i)->mover();
			arr->at(i)->dibujar();
		}

		if (arr->size() >= 20) { return true; }
		return false;
	}

	
	

};
