#include <iostream>
#include "ABB.h"
#include "val.h"


/*
               UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

Programa para ingresar elementos en un arbol

Autores: Christian Garces
		 luciana Guerra

Fecha de Creacion:  3 de julio del 2022

Version del programa: Version 2

Materia: Estructuras de datos

Nrc: 4683
*/

/*int main()
{
   // Un Arbol de enteros
   ArbolABB ArbolInt;
   Validacion v;
   int dim, i;
   char val[10];
   
   for(i=0;i<10;i++){
   	char* mensaje = (char*) "\nIngrese un valor: ";
	strcpy(val,v.ingresarDato(mensaje));
    dim=atoi(val);
    ArbolInt.Insertar(dim);
   }
   

   cout <<endl;
   cout << "InOrden: ";
   ArbolInt.InOrden(Mostrar);

  // cin.get();
   return 0;
}*/
int main()
{
	ArbolABB ArbolInt;
  // val v;
   //int dim;
  // char val[10];
    int opcion, tamanio = 0;
     bool repetir = true;
    do {
        system("cls");
        printf("\t\t===================================\n");
        printf("\t\t\tMENU DE OPCIONES\n");
        printf("\t\t===================================\n");
        cout << "\t\t [1] Insertar" << endl;
        cout << "\t\t [2] Borrar" << endl;
        cout << "\t\t [3] Buscar" << endl;
        cout << "\t\t [4] Mostrar " << endl;
        cout << "\t\t [5] Altura del Arbol" << endl;
        cout << "\t\t [0] SALIR" << endl;
        printf("\t\t===================================\n");
        int opcion = val::leerNumero("\n\t\tIngrese una opcion [0-5]: ");
        printf("\n\t\t===================================\n");
 
        switch (opcion) {
   if (opcion > 6 || opcion < 0) {         
          repetir = true;
            }
        case 1:
            rewind(stdin);
             //arreglo.encerar();
            do {
                float n = val::leerNumero("ingrese un numero: ");
               ArbolInt.Insertar(n);
            } while (val::confirmar("Desea agregar otro numero?"));

            ArbolInt.InOrden(Mostrar);
       

            system("pause>nul"); // Pausa
            fflush(stdin);
            break;
            
        case 2:
            rewind(stdin);
            //arreglo.encerar();
            do {
                float n = val::leerNumero("ingrese un numero que desea eliminar : ");
                ArbolInt.Borrar(n);
            } while (val::confirmar("Desea eliminar otro numero?"));

       		ArbolInt.InOrden(Mostrar);

            system("pause>nul"); // Pausa
            fflush(stdin);
            break;

        case 3:           

			cout<< "Aun no funciona";
           /* rewind(stdin);
           // arreglo.encerar();
            do {
                float n = val::leerNumero("ingrese un numero que desea buscar: ");
                arreglo.agregar(n);
            } while (val::confirmar("Desea agregar otro numero?"));

*/
            system("pause>nul"); // Pausa
            fflush(stdin);
            break;

        case 4:
            // Lista de instrucciones ShellSort  
            rewind(stdin);
            
           		cout << "InOrden: ";
			   ArbolInt.InOrden(Mostrar);
			   cout << endl;
			   cout << "PreOrden: ";
			   ArbolInt.PreOrden(Mostrar);
			   cout << endl;
			   cout << "PostOrden: ";
			   ArbolInt.PostOrden(Mostrar);
			   cout << endl;
			   
			   system("pause>nul"); // Pausa
            fflush(stdin);
            break;
			   
			   
	     case 5:
            
                cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;                                      
				    system("pause>nul"); // Pausa
				   fflush(stdin);
				   
            break;
            
        case 0:
            repetir = false;
            break;
        }

    } while (repetir);

    return 0;
}