#pragma once
#include "Auto.h"
#include "Bici.h"
#include "Bus.h"
#include "Jugador.h"

class Juego :public Movil {

private:

	vector<Movil*>vecene; //arreglito hecho de moviles
	Jugador* obj;
	bool victoria;
	int vidas;

public:
	

	Juego() {
		vidas = 3;
		obj = new Jugador();
		victoria = false;
	}

	~Juego() {
	
		delete obj; //borramos el objeto
		while (vecene.size()) { //y todo nuestro arreglo de moviles pq el contenido no se borra solo
			vecene.erase(vecene.begin());
		}
	}

	bool jugar() {

		for (int i = 0; i < vecene.size(); i++) {
			vecene.at(i)->borrar(); //nuestro arreglito de moviles [i] se borra
			vecene.at(i)->mover();
			vecene.at(i)->dibujar();
		}

		obj->borrar();
		obj->mover();
		obj->dibujar();

		if (obj->getrec().Y  < 2) { victoria = true; return true; }


		for (int i = 0; i < vecene.size(); i++) {
			if (vecene.at(i)->colision(obj->getrec())) { 
				vidas--;

				obj->reposicionar();
				while (vecene.size()) { //limpiamos vector, osea toda la pantalla
					vecene.at(0)->borrar();//borrar el rastro
					vecene.erase(vecene.begin());
				}

				if (vidas == 0) {
					return true;
				}
				break;

			} //acabó el juego
		}
		if (rand() % 100 < 5) {
			switch (rand() % 3) {
			case 0: vecene.push_back(new Bus());break; //estamos agregando al azar nuestros moviles en consola
			case 1: vecene.push_back(new Auto());break;
			case 2: vecene.push_back(new Bici());break;
			}
		}
		return false; //el juego continua


	}

	void tecla(char letra) {

		switch (letra){		
		case 'W':obj->tecla(0, -1); break;
		case 'A':obj->tecla(-1, 0); break;
		case 'S':obj->tecla(0, 1); break;
		case 'D':obj->tecla(1, 0); break;
		default:obj->tecla(0, 0); break;		
		}

	}

	bool getvictoria() { return victoria; }


};
