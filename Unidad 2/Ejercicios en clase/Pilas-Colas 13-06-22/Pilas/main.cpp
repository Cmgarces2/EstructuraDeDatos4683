#include <iostream>
#include <stdlib.h> 
#include "PilaClases.h"
 
using namespace std;

int anadir(){
	int x;
	cout<<"Ingrese el elemento a agregar a la cola: "<<endl;
	while(!(cin>>x)){
		cout<<"Ingreso no valido ingrese nuevamente un numero entero: ";
		cin.clear();
		cin.ignore(123, '\n');
	}
	return x;
}

int main(){ 
	pila Pila; 
	Pila.Push(anadir());
	Pila.Push(anadir());
	Pila.Push(anadir());
	Pila.Push(anadir());
	Pila.Push(anadir());
	Pila.MostrarInicio();
	cout << "Pop() = " << Pila.Pop() << endl;
	Pila.MostrarInicio();
	
	system("PAUSE"); 
	return 0; 
}
