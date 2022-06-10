#include <iostream>
#include "ListaCircularDoble.h"
#include "marquesina.h"
#include "Login.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
               UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

Programa para Registrar clientes de una mecanica

Autores: Christian Garces
		 luciana Guerra

Fecha de Creacion:  10 de junio del 2022

Version del programa: Version 2

Materia: Estructuras de datos

Nrc: 4683
*/

int main(int argc, char** argv) {

    int opc;
	do{
		system("cls");
		opc=menu2();
		switch(opc)
		{
			case 1:{
				LoginU();
				break;
			}
            case 2:{
            	registro();
				break;
			}
            case 3:{
            	int a=0, b=56, c=0, n=0;
				char t[40] ="Adios, gracias por usar el programa :D ";
				do
				{
					for (a=1;a<=56;a++)
					{
						system("cls");
						gotoxy(a,1);
						cout<<t;
						Sleep (50);
					}
					for (b=56;b>=1;b--)
					{
					system("cls");
					gotoxy(b,1);
					cout<<t;
					Sleep (50);
					}
				}while (c=1);
				getch ();
					cout<<"\n"<<endl;
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
