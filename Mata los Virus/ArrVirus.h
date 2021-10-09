#pragma once
#include "Virus.h"

#include <vector>

class ArrVirus {
private:
	vector<Virus*> virus;
	int letalidad1;
	int letalidad2;
	int letalidad3;
	int letalidad4;
	int letalidad5;
	bool acabo;
public:
	ArrVirus() {
		letalidad1 = 0;
		letalidad2 = 0;
		letalidad3 = 0;
		letalidad4 = 0;
		letalidad5 = 0;
		acabo = false;
	}
	~ArrVirus() {

	}
	void jugar() {
		int auxx;
		int auxy;
		char tecla;
		
		clock_t inicio = clock();
		while (true) {
			if (((clock() - inicio) / CLOCKS_PER_SEC) == 2) {
				auxx = rand() % 55 + 1;
				auxy = rand() % 15 + 1;
				virus.push_back(new Virus(auxx, auxy));
				inicio = clock();
			}
			if (_kbhit()) {
				tecla = _getch();
				tecla = toupper(tecla);
				eliminar_por_letalidad(tecla);
			}
			for (int i = 0; i < virus.size(); i++) {
				virus.at(i)->mover();
				if (virus.at(i)->getLetalidad() == '5' &&
					virus.at(i)->getX()  + virus.at(i)->getAncho() >= 90) acabo = true;
			}
			if (acabo) break;
			_sleep(250);
		}
		Console::Clear();
		cout << "Cantidad de 1s eliminados: " << letalidad1 << endl;
		cout << "Cantidad de 2s eliminados: " << letalidad2 << endl;
		cout << "Cantidad de 3s eliminados: " << letalidad3 << endl;
		cout << "Cantidad de 4s eliminados: " << letalidad4 << endl;
		cout << "Cantidad de 5s eliminados: " << letalidad5 << endl;

	}
	void eliminar_por_letalidad(char letalidad) {
		for (int i = 0; i < virus.size(); i++) {
			if (virus.at(i)->getLetalidad() == letalidad) {
				virus.at(i)->borrar();
				switch (virus.at(i)->getLetalidad()) {
				case '1':
					letalidad1++;
					break;
				case '2':
					letalidad2++;
					break;
				case '3':
					letalidad3++;
					break;
				case '4':
					letalidad4++;
					break;
				case '5':
					letalidad5++;
					break;
				}
				virus.erase(virus.begin() + i);
			}
		}
	}
};
