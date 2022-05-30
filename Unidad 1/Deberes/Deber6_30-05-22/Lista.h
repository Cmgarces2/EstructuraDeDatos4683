#pragma once
#include "Nodo.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;
class Lista{
	private:
		Nodo *primero;
		Nodo *actual;
		char *dato=new char[10];
		bool ListaVacia(){
			return (this->primero == NULL);
		}		
		public:
		 	Lista(){
				this ->primero = NULL;
				this->actual = NULL;				
			}
		void Insertar (int v){
			Nodo *nuevo = new Nodo(v);
			if (ListaVacia()){
				this->primero = nuevo;
			}
			else{
				this->actual->Siguiente  = nuevo;
			}
			this->actual = nuevo;
		}
		
		void MostrarInicio(){
			if (!ListaVacia()){
				Nodo *tmp = this ->primero;
					while (tmp) {
						cout << tmp->Valor << "--->";
						tmp = tmp->Siguiente;		
					}
			cout << "NULL\n";
			}else{
				cout << "La lista esta vacia"<<endl;
			}
			
		}
		
		void Buscar(int x){
			if (!ListaVacia()){
			Nodo *tmp = this ->primero;
			int seencontro=0;
			while (tmp) {
				if(tmp->Valor==x){
					cout << x << " Si se encuentras en el arreglo";
					seencontro=1;
				}
				tmp = tmp->Siguiente;		
			}
			if(seencontro==0){
				cout << x << " No se encuentras en el arreglo";
			}
			}else{
				cout << "La lista esta vacia"<<endl;
			}

			
		}
		
		
		void eliminar(int n){
			if (!ListaVacia()){
				Nodo *aux_borrar;
				Nodo *tmp = this ->primero;
				Nodo *anterior = NULL;
				aux_borrar = tmp;
				while((aux_borrar != NULL)&&(aux_borrar->Valor != n)){
					anterior = aux_borrar;
					aux_borrar = aux_borrar->Siguiente;
				}
				
				if(aux_borrar == NULL){
					cout << "No se encuentra en el arreglo";
				}
				else if(anterior==NULL){
					tmp = tmp->Siguiente;
					delete aux_borrar;
				}
				else{
					anterior->Siguiente = aux_borrar->Siguiente;
					delete aux_borrar;
				}
			}else{
				cout << "La lista esta vacia"<<endl;
			}
		}
		
		void MostrarFinal(){
		if (!ListaVacia()){	
	    	Nodo *tmp = this ->primero;
	        MostrarFinalRecursive(tmp);
	    }else{
	    	cout << "La lista esta vacia"<<endl;
		}
		}
	    
	    void MostrarFinalRecursive(Nodo *n)
	    {
	        if(n) 
			{
	            MostrarFinalRecursive(n->Siguiente);
	            cout << n->Valor << "--->";
				n = n->Siguiente;
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
				<<"4. Imprimir la lista desde el inicio"<<endl
				<<"5. Imprimir la lista desde el final"<<endl
				<<"0. Salir"<<endl
				<<"\nEscoja una opcion: ";
			cin>>opc;
			return opc;	
		}


