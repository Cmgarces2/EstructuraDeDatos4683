#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <iostream>
#include<stdlib.h>
#define ASCENDENTE 1
#define DESCENDENTE 0

using namespace std;

class ListasDobles{
	typedef ListasDobles *Nodito;
	private:
		int valor;
		ListasDobles *siguiente;
		ListasDobles *anterior;
		
	public:
		
		ListasDobles a(){
			this->siguiente=NULL;
			this->anterior=NULL;
		}
		
		void insertar(Nodito *lista,int v){
			Nodito nuevo, actual;
			/* Crear un nodo nuevo */
			nuevo = (Nodito)malloc(sizeof(Nodito));
			
			//nuevo = new Nodito;
			nuevo->valor = v;
			/* Colocamos actual en la primera posición de la lista */
			actual = *lista;
			if(actual) while(actual->anterior) actual = actual->anterior;
			/* Si la lista está vacía o el primer miembro es mayor que el nuevo */
			if(!actual || actual->valor > v) {
				/* Añadimos la lista a continuación del nuevo nodo */
				nuevo->siguiente = actual;
				nuevo->anterior = NULL;
				if(actual) actual->anterior = nuevo;
				if(!*lista) *lista = nuevo;
			}
			else {
					/* Avanzamos hasta el último elemento o hasta que el siguiente tenga
					un valor mayor que v */
					while(actual->siguiente &&actual->siguiente->valor <= v)
					actual = actual->siguiente;
					/* Insertamos el nuevo nodo después del nodo anterior */
					nuevo->siguiente = actual->siguiente;
					actual->siguiente = nuevo;
					nuevo->anterior = actual;
					if(nuevo->siguiente) 
					nuevo->siguiente->anterior = nuevo;
				}
		}
		
		void MostrarEnOrdenAscendente(Nodito *lista, int orden){
			
			Nodito nodo;
			nodo = *lista;
			if(nodo==NULL){
				cout << "\n lista vacia";
			}else{
			if(!nodo) printf("lista vacía");
			nodo = nodo;
			if(orden == ASCENDENTE) {
			while(nodo->anterior) 
			nodo = nodo->anterior;
			printf("Orden ascendente: ");
			while(nodo) {
			printf("%d -> ", nodo->valor);
			nodo = nodo->siguiente;
			}
			}
			else
			{
				while(nodo->siguiente)
				 nodo = nodo->siguiente;
				printf("Orden descendente: ");
				while(nodo)
				{
					printf("%d -> ", nodo->valor);
					nodo = nodo->anterior;
				}
			}
			printf("\n");
		}
		}
		
		void Borrar(Nodito *lista, int v) { 
			Nodito nodo;
			/* Buscar el nodo de valor v */
			nodo = *lista;
			if(nodo==NULL){
				cout << "\n lista vacia";
			}else{
			while(nodo && nodo->valor < v) 
			nodo = nodo->siguiente;
			while(nodo && nodo->valor > v) 
			nodo = nodo->anterior;
			/* El valor v no está en la lista */
			if(!nodo || nodo->valor != v) 
			return;
			/* Borrar el nodo */
			/* Si lista apunta al nodo que queremos borrar, apuntar a otro */
			if(nodo == *lista)
			if(nodo->anterior) 
			*lista = nodo->anterior;
			else *lista = nodo->siguiente;
			if(nodo->anterior) /* no es el primer elemento */
			nodo->anterior->siguiente = nodo->siguiente;
			if(nodo->siguiente) /* no es el último nodo */
			nodo->siguiente->anterior = nodo->anterior;
			free(nodo);
		}
		} 
		
		void Buscar(Nodito *lista, int v){
			Nodito nodo;
			nodo = *lista;
			int existe=0;
			if(nodo == NULL){
				cout <<  "\nLISTA VACIA ";
			}else{
				while(nodo){
					if(nodo->valor==v){
					cout << v << "\n Si se encuentras en el arreglo";
					existe=1;
					}
					nodo = nodo->siguiente;	
				}
				if(existe==0){
				cout << v << "\n No se encuentras en el arreglo";
				}	
			}	
		} 
		
		
		
};

int menu()
		{
			int opc;
			cout<<"\n****************************MENU****************************\n"<<endl
				<<"1. Ingresar elemento a la lista"<<endl
				<<"2. Buscar un elemneto en la lista"<<endl
				<<"3. Eliminar un elemento en la lista"<<endl
				<<"4. Imprimir la lista en orden ascendente"<<endl
				<<"5. Imprimir la lista en orden descendente"<<endl
				<<"0. Salir"<<endl
				<<"\nEscoja una opcion: ";
			cin>>opc;
			return opc;	
		}


