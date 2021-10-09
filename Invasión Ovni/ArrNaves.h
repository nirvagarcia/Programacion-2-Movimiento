#pragma once
#include "Movil.h"

class ArrNaves {

private:
	int n;
	Movil** arr;

public:

	ArrNaves() {
		n = 0;
		arr = new Movil * [n];
	}

	~ArrNaves() { delete[] arr; }

	void agregar(Movil* movil) {

		Movil** aux = new Movil * [n + 1];
		for (int i = 0; i < n; i++) {
			aux[i] = arr[i];
		}

		aux[n] = movil;
		delete[] arr;
		arr = aux;
		aux = nullptr;
		delete aux;
		n++;
	}

	void eliminar(int pos) {
		Movil** aux = new Movil * [n - 1];
		for (int i = 0; i < n - 1; i++) {
			if (i < pos) aux[i] = arr[i];
			else aux[i] = arr[i + 1];
		}
		delete[] arr;
		arr = aux;
		aux = nullptr;
		delete aux;
		n--;
	}


	Movil* at(int pos) { return arr[pos]; }
	int size() { return n; }
	
};
