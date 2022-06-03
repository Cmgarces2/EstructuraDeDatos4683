#pragma once
#include <iostream>

class Nodo2{
	private:
		int Valor;
		Nodo2 *Siguiente;
	public:
		Nodo2(int v, Nodo2*sig=NULL){
			this->Valor = v;
			this->Siguiente = sig;
		}
	friend class Lista;
};
