#pragma once
#include "Madera.h"
#include "Piedra.h"
#include "Sapo.h"

#include <vector>

class Juego {
private:
	Sapo* sapo;
	vector <Madera*> maderas;
	vector <Piedra*> piedras;
	bool gano;
public:
	Juego() {
		gano = false;
		sapo = new Sapo(45, 25);
		for (int i = 0; i < 5; i++) {
			maderas.push_back(new Madera());
			piedras.push_back(new Piedra());
		}
	}
	~Juego() {

	}
	void jugar() {
		bool termino = false;
		char tecla;
		sapo->dibujar();
	
		while (1) {
			if (_kbhit()) {
				tecla = _getch();
				tecla = toupper(tecla);
				sapo->mover(tecla);
				if (colisionMaderas() == false && colisionPiedras() == false && 
					(tecla == 'S' || tecla =='B')) {
					termino = true;
					gano = false;
				}
				for (int i = 0; i < piedras.size(); i++) {
					if (colision(sapo->getRectangle(), piedras.at(i)->getRectangle())) {
						sapo->borrar();
						sapo->setY(piedras.at(i)->getY() - sapo->getAlto());
						sapo->dibujar();
						sapo->setMadera(false);
					}
				}
				for (int i = 0; i < piedras.size(); i++) {
					if (colision(sapo->getRectangle(), maderas.at(i)->getRectangle())) {
						sapo->borrar();
						sapo->setY(maderas.at(i)->getY() - sapo->getAlto());
						sapo->setDx(maderas.at(i)->getDx());
						sapo->setMadera(true);
						sapo->dibujar();
					}
				}
			}
			if (sapo->getMadera() && (sapo->getX() + sapo->getDx() == 0 
				|| sapo->getX() + sapo->getAncho() + sapo->getDx() == 100)) {
				termino = true;
			}
			if (sapo->getMadera()) {
				sapo->mover_autonomo();
			}
			for (int i = 0; i < maderas.size(); i++)
				maderas.at(i)->mover();
			for (int i = 0; i < piedras.size(); i++) 
				piedras.at(i)->dibujar();
			
			
		
			if (sapo->getY() - sapo->getAlto() <= 0) {
				termino = true;
				gano = true;
			}
			if (termino) break;
			_sleep(40);
		}
		Console::Clear();
		if (gano) {
			cout << "Gano! C: ";
		}
		else {
			cout << "Game over :C";
		}
	}
	bool colision(Rectangle r1, Rectangle r2) {
		if (r1.IntersectsWith(r2)) return true;
		else return false;
	}

	bool colisionMaderas() {
		for (int i = 0; i < maderas.size(); i++) {
			if (sapo->getRectangle().IntersectsWith(maderas.at(i)->getRectangle()))return true;
		}
		return false;
	}
	bool colisionPiedras() {
		for (int i = 0; i < piedras.size(); i++) {
			if (sapo->getRectangle().IntersectsWith(piedras.at(i)->getRectangle()))return true;
		}
		return false;
	}
};
