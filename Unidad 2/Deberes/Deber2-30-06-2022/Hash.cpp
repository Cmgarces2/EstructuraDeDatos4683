#include "Hash.h"
//#define tam  5 
#define buck  2
#define desbordamiento  7

void Hash::inicio() {
	int i;
	for (i = 0; i < tam+1; i++) {
		cadena[i] = nullptr;
	}
}

void  Hash::ingreso(int valor) {

	// Creacion de un nuevo nodo con el valor
	int cont=1;
	int cont2=1;
	Hash* nuevoNodo = new Hash();
	nuevoNodo->datos = valor;
	nuevoNodo->siguiente = nullptr;

	// Calculo clave
	int clave = valor % tam;

	// Comprueba si la cadena [clave] esta vacia
	if (cadena[clave] == nullptr) {
		cadena[clave] = nuevoNodo;
		
		//Ccolision
	}
	else {
		// Agregar el nodo al final de la cadena [clave]
		Hash* temp = cadena[clave];
		while (temp->siguiente) {
			temp = temp->siguiente;
			cont=cont+1;
			
		}
		if((cont)==buck){
			cout<<"no se puede ingresar mas alementos en esa clave"<<endl;
			Hash* temp = cadena[tam+1];
			if(cont2!=desbordamiento){
				if (cadena[tam+1] == nullptr){
					cadena[tam+1] = nuevoNodo;

				//Ccolision
				}else{
					// Agregar el nodo al final de la cadena [clave]d
					Hash* temp = cadena[tam+1];
					while (temp->siguiente) {
						temp = temp->siguiente;
						cont2=cont2+1;
					}
			
					temp->siguiente = nuevoNodo;
			
				}
				
				
			}else{
				
				cout<<"no se puede ingresar mas alementos el desbordamiento esta lleno"<<endl;
			}
		}else{
			temp->siguiente = nuevoNodo;
		}
		

	}

}

int Hash::busqueda(int valor){
    int clave = valor%tam;
    Hash* temp=cadena[clave];
    while(temp){
        if(temp->datos==valor){
            return 1;
    }
    temp=temp->siguiente;
    }
    return 0;
}

int  Hash::eliminar(int valor) {
	int clave = valor % tam;
	Hash* temp = cadena[clave], * nuevo;
	if (temp != nullptr) {
		if (temp->datos == valor) {
			nuevo = temp;
			temp = temp->siguiente;
			free(nuevo);
			return 1;
		}
		else {
			while (temp->siguiente) {
				if (temp->siguiente->datos == valor) {
					nuevo = temp->siguiente;
					temp->siguiente = temp->siguiente->siguiente;
					//free(nuevo);
					return 1;
				}
				temp = temp->siguiente;
			}
		}
	}
	return 0;
}


void  Hash::impresion() {
	int i;
	for (i = 0; i < tam+1; i++) {
		if(i!=tam){
			Hash* temp = cadena[i];
			cout << "cadena ["<< i << "] -> ";
			while (temp) {
				cout <<  temp->datos << " -> ";
				temp = temp->siguiente;
			}
			cout << "NULL  "<<endl;
		}else{
			Hash* temp = cadena[i];
			cout << "cadena [desbordamiento] -> ";
			while (temp) {
				cout <<  temp->datos << " -> ";
				temp = temp->siguiente;
			}
			cout << "NULL  "<<endl;
		}
		
	}
}
