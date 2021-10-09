#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Llanta {

private:
	int x;
	int y;

public:

	Llanta(int X, int Y) {

		x = X;
		y = Y;
	}
	
	~Llanta() {};

	void borrar(){
		Console::SetCursorPosition(x, y); 
		cout << " "; //nos ubicamos donde está el carro y borramos
	}
	void mover() { //como solo se mueven a la derecha
		
		x++; //aumentamos el horizontal 1+1 pq solo va a derecha

	}

	void dibujar() {
		Console::SetCursorPosition(x, y);
		cout << "▄";
	}


};
