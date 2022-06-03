#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <iostream>
#include<stdlib.h>

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
			Nodito nuevo;
			Nodito actual;
			nuevo=(Nodito)malloc(sizeof(Nodito));
			nuevo->valor=v;
			actual=*lista;
			if(actual) while(actual->anterior)actual=actual->anterior;
			if(!actual||actual->valor>v){
				nuevo->siguiente=actual;
				nuevo->anterior=NULL;
				if(actual)actual->anterior=nuevo;
				if(!*lista)*lista=nuevo;
			}
			else{
				while(actual->siguiente && actual->siguiente->valor<=v)
				actual=actual->siguiente;
				nuevo->siguiente=actual->siguiente;
				actual->siguiente=nuevo;
				nuevo->anterior=actual;
				if(nuevo->siguiente)
				nuevo->siguiente->anterior=nuevo;
			}
		}
		void MostrarEnOrdenAscendente(Nodito *lista){
			Nodito nodo;
			nodo = *lista;
			if(nodo == NULL){
				cout <<  "LISTA VACIA ";
			}else{
				while(nodo){
				cout << nodo->valor << "-> ";
        		nodo = nodo->siguiente;
			}
				
			}	
		}
		
		void Borrar(Nodito *lista, int v) { 
			Nodito nodo; 
			nodo = *lista;
			if(nodo == NULL){
				cout <<  "\nLISTA VACIA ";
			}else{  
			while(nodo && nodo->valor < v) 
				nodo = nodo->siguiente; 
			while(nodo && nodo->valor > v) 
				nodo = nodo->anterior; 
			if(!nodo || nodo->valor != v)
				cout << v << "No se encuentra en la lista"; 
				return; 
				
			 
			
			if(nodo->anterior) // no es el primer elemento 
				nodo->anterior->siguiente = nodo->siguiente; 
			if(nodo->siguiente) // no el el último nodo 
				nodo->siguiente->anterior = nodo->anterior; 
			delete nodo; 
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
				<<"4. Imprimir la lista en orden ascendenteo"<<endl
				<<"0. Salir"<<endl
				<<"\nEscoja una opcion: ";
			cin>>opc;
			return opc;	
		}


