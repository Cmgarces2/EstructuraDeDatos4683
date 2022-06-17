#include <iostream>
#include <string>
#include "Nodo.h"
using namespace std;
// Pila
class Pila
{
	public: Nodo *top;
	int size;
	Pila()
	{
		this->top = NULL;
		this->size = 0;
	}
	// Puss anadira un nodo en la parte superior de la pila 
	void push(char elemento)
	{
		this->top = new Nodo(elemento, this->top);
		this->size++;
	}
	//Comprueba si esta vacio
	bool vacia()
	{
		if (this->size > 0 && this->top != NULL)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	// Eliminar un elemento de la pila 
	void pop()
	{
		if (this->size > 0 && this->top != NULL)
		{
			Nodo *temp = this->top;
			// Se cambia el elemento superior en la pila
			this->top = temp->siguiente;
			this->size--;
		}
	}
	// Funcion para devolver el elemeto superior de la pila 
	char mostrarElemento()
	{
		if (this->top == NULL)
		{
			return ' ';
		}
		return this->top->elemento;
	}
};
