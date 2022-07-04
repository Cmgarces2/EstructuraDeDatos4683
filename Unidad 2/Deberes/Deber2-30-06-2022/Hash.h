#ifndef HASH_H
#define HASH_H
#include <iostream>
#define tam  5 
//crecion de la clase 
using namespace std;
class Hash
{
	private:
		int datos;
		Hash *siguiente;
		Hash *cadena[tam+1];
	public:
		void inicio();
		void ingreso(int valor);
		int busqueda(int valor);
		int eliminar(int valor);
		void impresion();
};

#endif 
