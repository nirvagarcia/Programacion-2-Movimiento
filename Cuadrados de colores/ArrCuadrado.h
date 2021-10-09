#pragma once
#include <iostream>
#include "Cuadrado.h"

using namespace std;
using namespace System;

class ArrCuadrado {

private:

	Cuadrado** arr;
	int n;


public:

	ArrCuadrado() {		
		n = 0;
		arr = new Cuadrado * [n];				
	}

	~ArrCuadrado() {};

	void dibujar() {

		
		for (int i=0; i < n; i++) {
			arr[i]->dibujar();
		}
	}

	void mover() {
	
		for (int i = 0; i < n; i++) {
			arr[i]->mover();
		}
		
	}

	void borrar() {

		for (int i = 0; i < n; i++) {
			arr[i]->borrar();
		}
	}

	void addCuadrado() {
		
		Cuadrado* C = new Cuadrado();
		Cuadrado** aux = new Cuadrado * [n + 1]; 
	
		for (int i = 0; i < n; i++) {
			aux[i] = arr[i]; 
		}

		aux[n] = C; 
		n++;
		arr = aux; 
	}

	void borrarCuadrado() {
		
		Cuadrado** aux = new Cuadrado * [n - 1]; 

		for (int i = 0; i < n; i++) {

			aux[i] = arr[i]; 
		}
		n--; 
		arr = aux;
		
	}

	void cambiarColor() {

		for (int i = 0; i < n; i++) {

			arr[i]->cambiarcolor(); 
		}
	}
};
