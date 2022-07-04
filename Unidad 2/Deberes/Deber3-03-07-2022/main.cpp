#include <iostream>
#include "ABB.h"
#include "Validacion.h"


/*
               UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

Programa para ingresar elementos en un arbol

Autores: Christian Garces
		 luciana Guerra

Fecha de Creacion:  3 de julio del 2022

Version del programa: Version 2

Materia: Estructuras de datos

Nrc: 4683
*/

int main()
{
   // Un Arbol de enteros
   ArbolABB ArbolInt;
   Validacion v;
   int dim, i;
   char val[10];
   
   for(i=0;i<10;i++){
   	char* mensaje = (char*) "\nIngrese un valor: ";
	strcpy(val,v.ingresarDato(mensaje));
    dim=atoi(val);
    ArbolInt.Insertar(dim);
   }
   

   cout <<endl;
   cout << "InOrden: ";
   ArbolInt.InOrden(Mostrar);

  // cin.get();
   return 0;
}