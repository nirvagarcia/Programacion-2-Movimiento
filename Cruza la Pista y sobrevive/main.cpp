#include "pch.h"
#include "Juego.h"
#include <time.h>
#include <conio.h>

void main(){

	srand(time(NULL));
	Juego* obj = new Juego();

	while (true) {

		if (obj->jugar())break;

		if (kbhit())obj->tecla(toupper(getch()));
		else obj->tecla(' ');
	}



	if (obj->getvictoria()) cout << "Ganaste";
	else cout << "Perdiste";
	delete obj;
	
	_getch();
	system("pause>nul");
}
