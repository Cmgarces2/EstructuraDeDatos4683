#include "Ingresar.h"
#include <string.h>
#include <iostream>
#include <conio.h>
	string *Ingresar::ingresar(string *msj){
		string dato;
		cin.getline(dato,10,'\n');
		return dato;
	}
	
