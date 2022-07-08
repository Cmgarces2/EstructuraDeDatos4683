#include <iostream>
#include "ABB.h"
#include "Validacion.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu();
int main()
{
   // Un Ã¡rbol de enteros
   ArbolABB ArbolInt;
   Validacion v;
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
        		ArbolInt.Insertar(dim);
				break;
			}
			case 2:{
				char* mensaje = (char*) "\nIngrese un valor a buscar: ";
				strcpy(val,v.ingresarDato(mensaje));
        		dim=atoi(val);
				if(ArbolInt.Buscar(dim)==false){
					cout<<"elemeno no encontrado"<<endl;
				}else{
					cout<<"elemeno encontrado"<<endl;
				}		            
				break;
			}
			case 3:{
				char* mensaje = (char*) "\nIngrese un valor a eliminar: ";
				strcpy(val,v.ingresarDato(mensaje));
        		dim=atoi(val);
        		if(ArbolInt.Buscar(dim)==false){
					cout<<"elemeno no encontrado"<<endl;
				}else{
					cout<<"elemeno encontrado, borrando!!"<<endl;
					ArbolInt.Borrar(dim);
				}
						            
				break;
			}
			case 4:{
				cout << "InOrden: ";
			    ArbolInt.InOrden(Mostrar);
			    cout << endl;			            
				break;
			}
			case 5:{
				cout << "PreOrden: ";
				ArbolInt.PreOrden(Mostrar);
				cout << endl;			            
				break;
			}
			case 6:{
				cout << "PostOrden: ";
				ArbolInt.PostOrden(Mostrar);
				cout << endl;			            
				break;
			}
			case 7:{
				cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;			            
				break;
			}
			case 8:{
				char* mensaje = (char*) "\nIngrese un valor: ";
				strcpy(val,v.ingresarDato(mensaje));
        		dim=atoi(val);	
				ArbolInt.Altura(dim);		            
				break;
			}
			case 9:{
				cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;			            
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

   // InserciÃ³n de nodos en Ã¡rbol:
   /*
   ArbolInt.Insertar(10);
   ArbolInt.Insertar(5);
   ArbolInt.Insertar(12);
   ArbolInt.Insertar(4);
   ArbolInt.Insertar(7);
   ArbolInt.Insertar(3);
   ArbolInt.Insertar(6);
   ArbolInt.Insertar(9);
   ArbolInt.Insertar(8);
   ArbolInt.Insertar(11);
   ArbolInt.Insertar(14);
   ArbolInt.Insertar(13);
   ArbolInt.Insertar(2);
   ArbolInt.Insertar(1);
   ArbolInt.Insertar(15);
   ArbolInt.Insertar(10);
   ArbolInt.Insertar(17);
   ArbolInt.Insertar(18);
   ArbolInt.Insertar(16);

   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;

   // Mostrar el Ã¡rbol en tres ordenes distintos:
   cout << "InOrden: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   cout << "PreOrden: ";
   ArbolInt.PreOrden(Mostrar);
   cout << endl;
   cout << "PostOrden: ";
   ArbolInt.PostOrden(Mostrar);
   cout << endl;

   // Borraremos algunos elementos:
   cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
   ArbolInt.Borrar(5);
   cout << "Borrar   5: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(8);
   cout << "Borrar   8: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(15);
   cout << "Borrar  15: ";
   ArbolInt.InOrden(Mostrar);

   cout << endl;
   ArbolInt.Borrar(245);
   cout << "Borrar 245: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;
   ArbolInt.Borrar(4);
   cout << "Borrar   4: ";
   ArbolInt.InOrden(Mostrar);
   ArbolInt.Borrar(17);
   cout << endl;
   cout << "Borrar  17: ";
   ArbolInt.InOrden(Mostrar);
   cout << endl;

   // Veamos algunos parÃ¡metros
   cout << "N nodos: " << ArbolInt.NumeroNodos() << endl;
   cout << "Altura de 1 " << ArbolInt.Altura(1) << endl;
   cout << "Altura de 10 " << ArbolInt.Altura(10) << endl;
   cout << "Altura de arbol " << ArbolInt.AlturaArbol() << endl;
	
   cin.get();*/
   return 0;
}

int menu()
		{
			int opc;
			cout<<"\n****************************MENU****************************\n"<<endl
				<<"1. Ingresar un elemento al arbol"<<endl
				<<"2. Buscar un elemento en arbol"<<endl
				<<"3. Eliminar un elemento del arbol"<<endl
				<<"4. Imprimir Arbol Inorden"<<endl
				<<"5. Imprimir Arbol Preorden"<<endl
				<<"6. Imprimir Arbol Postorden"<<endl
				<<"7. Numero de nodos del arbol"<<endl
				<<"8. Altura de un nodo"<<endl
				<<"9. Altura del arbol"<<endl
				<<"0. Salir"<<endl
				<<"\nEscoja una opcion: ";
			cin>>opc;
			return opc;
		}