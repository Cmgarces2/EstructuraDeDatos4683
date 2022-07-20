#include <iostream>
#include "Nodo.h"
#include "Validacion.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int menu();

int main(int argc, char** argv) {
	
	Validacion v;
	Node nod;
	Node* root = NULL;
	int opc, dim, i;
	char val[10];
	do{
		system("cls");
		opc=menu();
		switch(opc)
		{
			case 1:{
				char* mensaje = (char*) "\nIngrese el valor de codificacion: ";
				strcpy(val,v.ingresarDato(mensaje));
        		dim=atoi(val);

				break;
			}
			case 2:{
				if(dim==0){
					cout << "\nNo se a ingresado un valor para realizar la codificacion. INGRESE UNO\n";
					break;
				}
				char* mensaje = (char*) "\nIngrese una palabra: ";
				strcpy(val,v.ingresarDatoCC(mensaje,dim));
				//cout<<strlen(val);
				insert(&root, val);	
				cout<<endl;
				break;
			}
			case 3:{
				char* mensaje = (char*) "\nIngrese la palabra que desea buscar: ";
				strcpy(val,v.ingresarDatoC(mensaje));
        		searchTST(root, val) ? cout << "Found\n"
                                      : cout << "Not Found\n";
			}
			case 4:{
				cout<<"\nPalabras dentro del arbol"<<endl;
				traverseTSTDeco(root,dim);			            
				break;
			}
			case 5:{
				cout<<"\nPalabras dentro del arbol"<<endl;
				traverseTST(root);			            
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
	
	/*Node* root = NULL;
    char cat[] = "cat";
    char cats[] = "cats";
    char up[] = "up";
    char bug[] = "bug";
    char bu[] = "bu";
    insert(&root, cat);
    insert(&root, cats);
    insert(&root, up);
    insert(&root, bug);
 
    cout << "Following is traversal of ternary search "
            "tree\n";
    traverseTST(root);
 
    cout << "\nFollowing are search results for cats, bu "
            "and cat respectively\n";
    searchTST(root, cats) ? cout << "Found\n"
                          : cout << "Not Found\n";
    searchTST(root, bu) ? cout << "Found\n"
                        : cout << "Not Found\n";
    searchTST(root, cat) ? cout << "Found\n"
                         : cout << "Not Found\n";*/
 
    return 0;
}

int menu()
		{
			int opc;
			char val[10];
			Validacion v;
			cout<<"\n****************************MENU****************************\n"<<endl
				<<"1. Ingresar el numero de desplazamiento"<<endl
				<<"2. ingresar una palabra al arbol"<<endl
				<<"3. buscar una palara en el arbol"<<endl
				<<"4. Imprimir arbol descodificado"<<endl
				<<"5. Imprimir arbol codificado"<<endl
				<<"0. Salir"<<endl;
			char* mensaje = (char*) "\nEscoja una opcion: ";
			strcpy(val,v.ingresarDato(mensaje));
        	opc=atoi(val);
			return opc;
		}