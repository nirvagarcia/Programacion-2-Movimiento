#pragma once
#include <iostream>
#include <vector> // arreglo dinamico que no tenemos que crear
using namespace std;
using namespace System;
using namespace System::Drawing;
#define anchopantalla 119;
#define altopantalla 29;

class Movil {

protected:
	int x; //coordenadas
	int y; //coordenadas
	int dx;	//que se mueva
	int dy;	//que se mueva
	int ancho;	 //ancho alto de los moviles
	int alto;	 //ancho alto de los moviles
	int aceleracion; //para que tengan velocidades distintas
	int velocidad;	 //para que tengan velocidades distintas
	vector<string> dibujo; //vector por default

public:

	Movil() {
		x = rand() % 80; //que aparezca en cualquier lado
		y = rand() % 24; //que aparezca en cualquier lado
		dx = 0;
		dy = 0;
		aceleracion = 0;
		velocidad = (rand() % 7 + 2) * 10; //velocidad random

	}

	~Movil() {}

	void borrar() { //borramos tooodo el ancho y largo del movil

		for (int i = 0; i < alto; i++) {
			for (int j = 0; j < ancho; j++) {
				Console::SetCursorPosition(x+j, y+i); cout << " ";
			}
		}
	}

	void mover() { //este se adapta a todos mis hijos

		if (x + dx<0 || x + dx + ancho>119) movimientoInvalido(1); //1 significa que choqué en eje x
		else if (y + dy < 0 || y + dy + alto>29) movimientoInvalido(2); //2 es choqué en el eje y
		else {

			if (aceleracion >= velocidad) {
				aceleracion = 0;
				x += dx; y += dy;//chocó con los dos ¡?, esto se ejecuta 1 de cada n veces
			}

			else {
				aceleracion++;
			}			
		} 	
		

	}

	void dibujar() {

		for (int i = 0; i < alto; i++) {			
			Console::SetCursorPosition(x, y + i); 
			cout << dibujo.at(i); // at es reemplazo de [i], aca dice que se dibuje en la posicion i
		}

	}

	virtual void movimientoInvalido(int n) { //validar movimiento en consola (virtual:solo se adapta a algunos o uno, sin eso significa que se adaptará a todos los moviles)

		if (n == 1) dx = -dx; //si llega a los bordes, o sea movimiento invalido, cambie su dirección al otro lado, osea que rebote
		if (n == 2) dx = -dy; // lo mismo en y

	}

	Rectangle getrec() { //para hace colisiones mas sencillas

		return Rectangle(x, y, ancho, alto);
	}

	virtual bool colision(Rectangle rec) { //para hace colisiones mas sencillas

		return rec.IntersectsWith(getrec()); //cuando el rectangulo de acá se choque(IntersecWith) con el rectangulo de arriba, es colicion
	}


};
