/*
               UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

Programa: Implementacion hash

Autores: Todo el curso

Fecha de Creacion:  26 de junio del 2022

Version del programa: Version 2.5

Materia: Estructuras de datos

Nrc: 4683
*/
//Librerías
#include <iostream>
#include "Hash.h"
#include "Validacion.h"


int menu();

int main(int argc, char** argv) {
	
	
	Hash objt;
	Validacion v;
	objt.inicio();
	int opc, dim;
	char val[10];
	do{
		system("cls");
		opc=menu();
		switch(opc)
		{
			case 1:{
				char* mensaje = (char*) "\nIngrese un valor: ";
				strcpy(val,v.ingresarDato(mensaje));
        		dim=atoi(val);
				objt.ingreso(dim);	
				cout<<endl;
				break;
			}
			case 2:{
				char* mensaje = (char*) "\nIngrese el valor que desea buscar: ";
				strcpy(val,v.ingresarDato(mensaje));
        		dim=atoi(val);
        		cout<<endl;
				if (objt.busqueda(dim)){
					cout << "El valor no ha sido encontrado" << endl;
				}
				else {
					cout << "Valor no encontrado" << endl;
				};			            
				break;
			}
			case 3:{
				char* mensaje = (char*) "\nIngrese el valor que desea eliminar: ";
				strcpy(val,v.ingresarDato(mensaje));
        		dim=atoi(val);
        		cout<<endl;
				if (objt.eliminar(dim)) {
					cout << "Despues de la eliminacion" << endl;
					objt.impresion();
				}
				else {
					cout << "Valor no encontrado" << endl;
				};			            
				break;
			}
			case 4:{
				objt.impresion();	
				//cout<<tam+1;		            
				break;
			}
			case 0:{
				cout<<"\nAdios, Gracias por usar el programa :D "<<endl;
				break;
			}
			default:{
				cout<<"\nError. Opcion incorrecta"<<endl;
				break;
			}
		}
		system("pause");
	}while(opc!=0);
}

int menu()
		{
			int opc;
			cout<<"\n****************************MENU****************************\n"<<endl
				<<"1. Ingresar un elemento a la tabla"<<endl
				<<"2. Buscar un elemento en la tabla"<<endl
				<<"3. Eliminar un elemento en la tabla"<<endl
				<<"3. imprimir la tabla"<<endl
				<<"0. Salir"<<endl
				<<"\nEscoja una opcion: ";
			cin>>opc;
			return opc;
		}
