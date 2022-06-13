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
	
	friend class pila; 
}; 
 
typedef nodo *pnodo; 
 
class pila { 
	public: 
		pila() : ultimo(NULL) {} 
		~pila(); 
		
		void Push(int v); 
		int Pop();  
		void MostrarInicio();
		
	private: 
		pnodo ultimo; 
}; 
 
pila::~pila() { 
	while(ultimo) Pop(); 
}
 
void pila::Push(int v) { 
	pnodo nuevo; 
	
	/* Crear un nodo nuevo */ 
	nuevo = new nodo(v, ultimo); 
	/* Ahora, el comienzo de nuestra pila es en nuevo nodo */ 
	ultimo = nuevo; 
}
 
int pila::Pop() { 
	pnodo nodo; /* variable auxiliar para manipular nodo */ 
	int v; /* variable auxiliar para retorno */ 
	
	if(!ultimo) 
		return 0; /* Si no hay nodos en la pila retornamos 
	0 */ 
	/* Nodo apunta al primer elemento de la pila */ 
	nodo = ultimo; 
	/* Asignamos a pila toda la pila menos el primer elemento */ 
	ultimo = nodo->siguiente; 
	/* Guardamos el valor de retorno */ 
	v = nodo->valor; 
	/* Borrar el nodo */ 
	delete nodo; 
	return v; 
}

void pila::MostrarInicio(){
	pnodo nodo;
	if (nodo){
		nodo = this ->ultimo;
		while (nodo){
			cout << nodo->valor << "--->";
			nodo = nodo->siguiente;		
		}
		cout << "|\n";
	}else{
		cout << "La lista esta vacia"<<endl;
	}			
}

 
