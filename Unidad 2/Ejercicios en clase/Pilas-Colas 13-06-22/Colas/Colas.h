#include <iostream>
#include <stdlib.h> 

using namespace std;

class nodo { 
	public: 
		nodo(int v, nodo *sig = NULL) { 
			valor = v; 
			siguiente = sig; 
		} 
	private: 
		int valor; 
		nodo *siguiente; 
	
	friend class cola; 
}; 
 
typedef nodo *pnodo; 
 
class cola { 
	public: 
		cola() : ultimo(NULL), primero(NULL) {} 
		~cola(); 
		
		void push(int v); 
		int pop(); 
		void MostrarInicio();
		
	private: 
		pnodo primero, ultimo; 
}; 
 
cola::~cola() { 
	while(primero) 
	pop(); 
} 

void cola::push(int v) { 
	pnodo nuevo; 
	
	/* Crear un nodo nuevo */  
	nuevo = new nodo(v); 
	/* Si la cola no estaba vacía, añadimos el nuevo a continuación 
	de ultimo */ 
	if(ultimo) 
		ultimo->siguiente = nuevo; 
	/* Ahora, el último elemento de la cola es el nuevo nodo */ 
	ultimo = nuevo; 
	/* Si primero es NULL, la cola estaba vacía, ahora primero 
	apuntará también al nuevo nodo */ 
	if(!primero) 
		primero = nuevo; 
} 

int cola::pop() { 
	pnodo nodo; /* variable auxiliar para manipular nodo */ 
	int v; /* variable auxiliar para retorno */ 
	
	/* Nodo apunta al primer elemento de la pila */ 
	nodo = primero; 
	if(!nodo) 
		return 0; /* Si no hay nodos en la pila retornamos 0 
	*/ 
	/* Asignamos a primero la dirección del segundo nodo */ 
	primero = nodo->siguiente; 
	/* Guardamos el valor de retorno */ 
	v = nodo->valor; 
	/* Borrar el nodo */ 
	delete nodo; 
	/* Si la cola quedó vacía, ultimo debe ser NULL también*/ 
	if(!primero) 
		ultimo = NULL; 
	return v; 
} 

void cola::MostrarInicio(){
	pnodo nodo;
	if (nodo){
		nodo = this ->primero;
		while (nodo){
			cout << nodo->valor << "--->";
			nodo = nodo->siguiente;		
		}
		cout << "NULL\n";
	}else{
		cout << "La lista esta vacia"<<endl;
	}			
}
