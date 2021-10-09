#include "ArrVirus.h"

int main() {
	Console::CursorVisible = false;
	srand(time(NULL));
	ArrVirus* arrVirus = new ArrVirus();
	arrVirus->jugar();
	_getch();
	return 0;
}
