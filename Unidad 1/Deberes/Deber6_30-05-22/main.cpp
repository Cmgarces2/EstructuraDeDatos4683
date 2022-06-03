#include <iostream>
#include "Lista.h"
#include "Ingreso.h"
using namespace std;
int main(int argc, char** argv) {
	char dato[10];
	Lista lst;
	int opc;
	do{
		system("cls");
		opc=menu();
		switch(opc)
		{
			case 1:{
				lst.Insertar(TransformaraInt(strcpy(dato,ingresarDatos("Ingrese el valor numerico entero "))));
				/*lst.Insertar(3);
				lst.Insertar(100);
				lst.Insertar(5);
				lst.Insertar(6);*/	
				break;
			}
			case 2:{
				lst.Buscar(TransformaraInt(strcpy(dato,ingresarDatos("Ingrese el valor numerico entero a Buscar"))));			            
				break;
			}
			case 3:{
				lst.eliminar(TransformaraInt(strcpy(dato,ingresarDatos("Ingrese el valor numerico entero a Eliminar"))));			            
				break;
			}
			case 4:{
				lst.MostrarInicio();			            
				break;
			}
			case 5:{
				lst.MostrarFinal();			            
				break;
			}
			case 6:{
				lst.mcd();			            
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
