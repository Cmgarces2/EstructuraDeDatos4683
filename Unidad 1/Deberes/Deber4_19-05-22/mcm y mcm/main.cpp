/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

Programa para obtener el minimo comun multiplo y
el maximo comun divisor

Autores: Christian Garces
		 luciana Guerra

Fecha de Creacion:  19 de mayo del 2022

Version del programa: Version 1

Materia: Estructuras de datos

Nrc: 4683
*/

#include<iostream>
#include "MCDyMCM.h"

using namespace std;

int main(){
	
	MCDyMCM mcdymcm;
	
	int Numero1, Numero2;
	mcdymcm.IngresarValores();
	Numero1=(mcdymcm.getNumero1());
	Numero2=(mcdymcm.getNumero2());
	cout<<endl<<"El Maximo Comun Divisor es :"<<mcdymcm.MCD(Numero1,Numero2)<<endl;
	cout<<endl<<"El Minimo Comun Multiplo es :"<<mcdymcm.MCM(Numero1,Numero2,mcdymcm.MCD(Numero1,Numero2))<<endl;
	

return 0;

}
