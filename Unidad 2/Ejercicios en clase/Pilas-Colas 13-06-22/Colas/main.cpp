#include <iostream>
#include <stdlib.h> 
#include "Colas.h"
 
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

int main() { 
	cola Cola; 
	Cola.push(anadir());
	Cola.push(anadir());
	Cola.push(anadir());
	Cola.push(anadir());
	Cola.push(anadir());
	Cola.push(anadir()); 
	Cola.MostrarInicio();
	cout << "pop: " << Cola.pop() << endl;
	Cola.MostrarInicio();
	return 0; 
}



