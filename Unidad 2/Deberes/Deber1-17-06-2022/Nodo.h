#include <iostream>
#include <string>
using namespace std;
// Nodo
class Nodo
{
	public:
	char elemento;
	Nodo *siguiente;
	Nodo(char elemento, Nodo *siguiente)
	{
		this->elemento = elemento;
		this->siguiente = siguiente;
	}
};
