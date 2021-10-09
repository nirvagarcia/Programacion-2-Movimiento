#pragma once
#include "Casa.h"
#include "Monigote.h"
#include "Vacuna.h"
#include "Virus.h"

#include <vector>

class Juego {
private:
	Monigote* monigote;
	Casa* casa;
	vector<Vacuna*> vacunas;
	vector<Virus*> virus;
	int pasos;
	int cantVirus;
public:
	Juego() {
		int auxx;
		int auxy;
		monigote = new Monigote(2, 2);
		casa = new Casa(98, 24);
		cantVirus = 1;
		pasos = 0;
		for (int i = 0; i < cantVirus; i++) {
			auxx = rand() % 55 + 1;
			auxy = rand() % 15 + 1;
			virus.push_back(new Virus(auxx, auxy));
		}
	}
	~Juego() {

	}
	void jugar() {
		int contVacuna = 0;
		int contPasosInmunes = 0;
		clock_t inicio = clock();
		int auxx;
		int auxy;
		char tecla;
		casa->dibujar();

		while (true) {
			Console::SetCursorPosition(0, 0);
			cout << "Vidas" << monigote->getVidas();
			monigote->dibujar();
			
			if (((clock() - inicio) / CLOCKS_PER_SEC) == 2 && contVacuna < 5) {
				auxx = rand() % 55 + 1;
				auxy = rand() % 15 + 1;
				vacunas.push_back(new Vacuna(auxx, auxy));
				contVacuna++;
				inicio = clock();
			}
			if (kbhit()) {
				tecla = _getch();
				tecla = toupper(tecla);
				monigote->mover(tecla);
				pasos++;
				if (monigote->getInmunidad() == true) contPasosInmunes++;
			}
			for (int i = 0; i < virus.size(); i++) {
				virus.at(i)->mover();
			}
			for (int i = 0; i < vacunas.size(); i++) {
				vacunas.at(i)->mover();
			}
			if (colision_monigote_casa()) break;

			if (colision_monigote_virus() && monigote->getInmunidad() == false) {
				monigote->setVidas(monigote->getVidas() - 1);
				if (monigote->getVidas() == 0) {
					break;
				}
				else {
					monigote->setX(2);
					monigote->setY(2);
				}
				Console::SetCursorPosition(0, 0);
				cout << "Vidas" << monigote->getVidas();
			}
			if (colision_monigote_vacuna()) {
				monigote->setInmunidad(true);
			}
			if (contPasosInmunes == 10) {
				monigote->setInmunidad(false);

			}
			_sleep(25);
		}
		if (monigote->getVidas() == 0) {
			Console::Clear();
			cout << "Fin del Juego" << endl;
		}
		else {
			Console::Clear();
			cout << "Cantidad de pasos: " << pasos << endl;
		}

	}

	void agregar_vacuna() {
		int auxx = rand() % 70 + 1;
		int auxy = rand() % 20 + 1;
		vacunas.push_back(new Vacuna(auxx, auxy));
	}

	bool colision_monigote_casa() {
		return monigote->getRectangle().IntersectsWith(casa->getRectangle());
	}
	bool colision_monigote_virus() {
		for (int i = 0; i < virus.size(); i++) {
			if (monigote->getRectangle().IntersectsWith(virus.at(i)->getRectangle())) return true;
		}
		return false;
	}
	bool colision_monigote_vacuna() {
		for (int i = 0; i < vacunas.size(); i++) {
			if (monigote->getRectangle().IntersectsWith(vacunas.at(i)->getRectangle())) {
				vacunas.at(i)->borrar();
				vacunas.erase(vacunas.begin() + i);
				return true;
			}
		}
		return false;
	}
};
