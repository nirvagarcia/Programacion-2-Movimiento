#include "pch.h"
#include <iostream>
#include <conio.h>
#include "ArrCuadrado.h"
#include "Cuadrado.h"

using namespace std;
using namespace System;
//version que deja un cadaver
void main() {

    Console::CursorVisible = false; 
    srand(time(NULL));

    ArrCuadrado* arrcuadrado = new ArrCuadrado();
    char tecla; 

    while (1) {

        arrcuadrado->borrar();
        arrcuadrado->mover();
        arrcuadrado->dibujar();


        if (_kbhit()) {

            tecla = _getch();
            tecla = toupper(tecla); 
            if (tecla == 'A') { arrcuadrado->addCuadrado(); } 
            if (tecla == 'D') { arrcuadrado->borrarCuadrado(); }
            if (tecla == 'C') { arrcuadrado->cambiarColor(); }
        }
        _sleep(75); //impresion fotogramas por segundo
    }
  _getch();
}
