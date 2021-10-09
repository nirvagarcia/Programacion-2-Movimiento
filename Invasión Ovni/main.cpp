#include "pch.h"
#include "Juego.h"
#include <conio.h>
#include <time.h>

void main() {

	srand(time(NULL));
	Juego* obj = new Juego();
	char tecla;
	Console::CursorVisible = false;
	Console::ForegroundColor = ConsoleColor::Cyan; 
	Console::SetCursorPosition(45, 14); cout << "   QUE COMIENCE LA INVASION";
	Console::SetCursorPosition(45, 15); cout << "Presione 'A' para agregar nave";	
	system("pause>0"); Console::Clear();
	
	while (true) {
		Console::ForegroundColor = ConsoleColor::DarkYellow;
		if (obj->jugar()) {	break; }

		if (kbhit()) {
			tecla = _getch();
			tecla = toupper(tecla);
			if (tecla == 'A') { obj->tecla(); }			
		
		}		
	}
	Console::ForegroundColor = ConsoleColor::Red; Console::SetCursorPosition(65, 14);
	cout << "Hemos sido INVADIDOS";
	_getch();
}
