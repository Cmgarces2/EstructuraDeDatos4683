/*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

Programa para ingresar una cadena de caracteres y determinar si es string float, entero o string

Autores: Christian Garces
		 luciana Guerra

Fecha de Creacion:  12 de mayo del 2022

Version del programa: Version 2.0

Materia: Estructuras de datos

Nrc: 4683
*/

#include "Proceso.h"
#include <iostream>

using namespace std;


int main(int argc, char** argv) {
	char dato[10];
	Proceso p1 = strcpy(dato,ingresarDatos("Ingrese el valor numerico entero "));
	Trycatch(*dato);
	return 0;
}


