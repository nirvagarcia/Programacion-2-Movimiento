#include "ArrVirus.h"
//desaparece los virus presionando sus numeros en el teclado
int main() {
	Console::CursorVisible = false;
	srand(time(NULL));
	ArrVirus* arrVirus = new ArrVirus();
	arrVirus->jugar();
	_getch();
	return 0;
}
