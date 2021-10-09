#pragma once
#include <iostream>

using namespace std;
using namespace System;

class Cuadrado {
private:
	int x;
	int y;
	int dx; //desplazamiento horizontal
	int dy; //desplazamiento vertical (pq queremos que el cuadrado se mueva)	
	int rgb; //capricho de colores
public:

	Cuadrado() {
		x = 1; //el num nos define donde inicia el spameo
		y = 1; //el num nos define donde inicia el spameo
		dx = 3; //el num nos define velocidad del desplazamiento
		dy = 3;
		rgb = rand() % 5; //entre 5 colores jiji
	}

	~Cuadrado() {};

	void borrar() { //position para ubicarnos en la posicion donde está, espacio en blanco para borrar pq es un caracter
		
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void mover() {
		if (y <= 1) x += dx; //cuando y está en su punto incial (1), avanza para la derecha en horizontal (x)
		if (x >= 114) y += dy; //cuando x llega a 114 (limite que haz puesto), mi desplazamiento será para abajo en y
		if ( y >= 27) x -= dx; // si y que es mi carrito bajando llega a 27 (limite de abajo), que vaya para la izq en x
		if (x <= 1) y -= dy; //si x llega a su posicion incial estando abajo, que suba en y
	}

	void dibujar() {

		switch (rgb)
		{
		case 0:
			Console::ForegroundColor = ConsoleColor::Cyan; break;
		case 1:
			Console::ForegroundColor = ConsoleColor::Yellow; break;
		case 2:
			Console::ForegroundColor = ConsoleColor::Green; break;
		case 3:
			Console::ForegroundColor = ConsoleColor::Magenta; break;
		case 4:
			Console::ForegroundColor = ConsoleColor::Red; break;
		}		
		Console::SetCursorPosition(x, y); cout << "█"; //dibujamos en la coordenada de inicio a nuestro cuadrado
	}
		
	//nos servirá para switchear colores con tecla "C"
	void cambiarcolor() {

		rgb = rand() % 5;

	}


};
