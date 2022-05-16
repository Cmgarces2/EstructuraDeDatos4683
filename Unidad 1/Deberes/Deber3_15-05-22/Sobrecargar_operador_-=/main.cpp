/*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

Programa para Sobrecargar la funcion -=

Autores: Christian Garces
		 luciana Guerra

Fecha de Creacion:  15 de mayo del 2022

Version del programa: Version 1.0

Materia: Estructuras de datos

Nrc: 4683
*/
#include <iostream>

using namespace std;

class Numeros{
	
	public:
		int numero;
		Numeros(){
			numero=0;
		}
		Numeros(int m){
			numero=m;
		}
		void Imprimir(){
			cout<<"el numero es: "<<numero<<endl;
		}
		void operator -= (int bonusnumero){
			numero = numero - bonusnumero;
		}

};


int main(int argc, char** argv) {
	Numeros numeroIngresado(45);
	numeroIngresado.Imprimir();
	
	int x=10;
	numeroIngresado -= x;
	numeroIngresado.Imprimir();
	numeroIngresado -= x;
	numeroIngresado.Imprimir();
		
	return 0;
}

