#pragma once
#include "Carro.h"

class ArrCarro {

private:

	int n;
	Carro** arr; //creamos el arreglo derivado a carros


public:

	ArrCarro() {
		n = 0;
		arr = new Carro * [n];
	}

	~ArrCarro() {};

	void agregarCarro(Carro* dato) {

		Carro** aux = new Carro * [n + 1];
		for (int i = 0; i < n; i++) {

			aux[i] = arr[i];
		}

		aux[n] = dato;
		delete[] arr;
		arr = aux;
		aux = nullptr;
		delete aux;
		n++;

	}


	void eliminarCarro(int pos) {

		Carro** aux = new Carro * [n - 1];

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

	Carro* at(int pos) { return arr[pos]; }

	int size() { return n; }

};
