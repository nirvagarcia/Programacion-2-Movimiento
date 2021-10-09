#include "Juego.h"

int main() {
	Console::CursorVisible = false;
	srand(time(NULL));
	Juego* juego = new Juego();
	juego->jugar();
	_getch();
	return 0;
}
