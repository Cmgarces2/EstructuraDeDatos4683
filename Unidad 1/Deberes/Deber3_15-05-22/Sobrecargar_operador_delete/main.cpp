
/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

sobrecarga del operador delete 
Autores: Christian Garces
		 luciana Guerra

Fecha de Creacion:  15 de mayo del 2022

Version del programa: Version 1

Materia: Estructuras de datos

Nrc: 4683
*/
#include <iostream>
#include<stdlib.h>
#include "Estudiante.h"
using namespace std;

int main(int argc, char** argv) {
	estudiante *p= new estudiante("lucas",45);
	
	p->mostrar();
	delete p;
}


















