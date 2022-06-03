#include <iostream>
#include "ListaD.h"
#include "Ingreso.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	typedef ListasDobles *Nodito;
	char dato[10];
	ListasDobles lst;
	Nodito lista=NULL;
	Nodito p;
	int opc;
	do{
		system("cls");
		opc=menu();
		switch(opc)
		{
			case 1:{
				lst.insertar(&lista,TransformaraInt(strcpy(dato,ingresarDatos("Ingrese el valor numerico entero "))));	
				break;
			}
			case 2:{
				lst.Buscar(&lista,TransformaraInt(strcpy(dato,ingresarDatos("Ingrese el valor numerico entero a Buscar"))));			            
				break;
			}
			case 3:{
				lst.Borrar(&lista,TransformaraInt(strcpy(dato,ingresarDatos("Ingrese el valor numerico entero a Eliminar"))));			            
				break;
			}
			case 4:{
				lst.MostrarEnOrdenAscendente(&lista);			            
				break;
			}
			case 0:{
				cout<<"\nAdios, gracias por usar el programa :D "<<endl;
				break;
			}
			default:{
				cout<<"\nError. Opcion incorrecta"<<endl;
				break;
			}
		}
		system("pause");
	}while(opc!=0);

	return 0;
}
