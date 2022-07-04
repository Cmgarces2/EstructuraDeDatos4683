#include <iostream>
#include "ABB.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	 ArbolABB ArbolInt;

   // Insertar de nodos en Arbol:
   ArbolInt.Insertar();
   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

   // Mostrar el Arbol en tres ordenes distintos:
   cout << "InOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   // Borraremos algunos elementos:
   cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
   ArbolInt.Borrar(;
   cout << "Borrar: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   // Veamos algunos parametros
   cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
   cout << "Altura " << ArbolInt.Altura(1) << endl;
   cout << "Altura " << ArbolInt.Altura(10) << endl;
   cout << "Altura " << ArbolInt.AlturaArbol() << endl;

   cin.get();	
	return 0;
}