#include <iostream>
using namespace std;

class ArbolABB {
  private:
   // Clase local de Lista para Nodo de ArbolBinario:
   class Nodo {
     public:
      // Constructor:
      Nodo(const int dat, Nodo *izq=NULL, Nodo *der=NULL) :
        dato(dat), izquierdo(izq), derecho(der) {}
      // Miembros:
      int dato;
      Nodo *izquierdo;
      Nodo *derecho;
   };

   // Punteros de la lista, para cabeza y nodo actual:
   Nodo *raiz;
   Nodo *actual;
   int contador;
   int altura;

  public:
   // Constructor y destructor bÃ¡sicos:
   ArbolABB() : raiz(NULL), actual(NULL) {}
   ~ArbolABB() { Podar(raiz); }
   // Insertar en Ã¡rbol ordenado:
   void Insertar(const int dat);
   // Borrar un elemento del Ã¡rbol:
   void Borrar(const int dat);
   // FunciÃ³n de bÃºsqueda:
   bool Buscar(const int dat);
   // Comprobar si el Ã¡rbol estÃ¡ vacÃ­o:
   bool Vacio(Nodo *r) { return r==NULL; }
   // Comprobar si es un nodo hoja:
   bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
   // Contar nÃºmero de nodos:
   const int NumeroNodos();
   const int AlturaArbol();
   // Calcular altura de un int:
   int Altura(const int dat);
   // Devolver referencia al int del nodo actual:
   int &ValorActual() { return actual->dato; }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
   // Aplicar una funciÃ³n a cada elemento del Ã¡rbol:
   void InOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
   void PreOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
   void PostOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
  
  private:
   // Funciones auxiliares
   void Podar(Nodo* &);
   void auxContador(Nodo*);
   void auxAltura(Nodo*, int);
};


// Insertar un int en el Ã¡rbol ABB
void ArbolABB::Insertar(const int dat)
{

}

// Eliminar un elemento de un Ã¡rbol ABB
void ArbolABB::Borrar(const int dat)
{
   Nodo *padre = NULL;
   Nodo *nodo;
   int aux;
}


void ArbolABB::InOrden(void (*func)(int&) , Nodo *nodo, bool r)
{

void ArbolABB::PreOrden(void (*func)(int&), Nodo *nodo, bool r)
{
}

void ArbolABB::PostOrden(void (*func)(int&), Nodo *nodo, bool r)
{
}

// Buscar un valor en el Ã¡rbol
bool ArbolABB::Buscar(const int dat)
{
   actual = raiz;
}

// Calcular la altura del nodo que contiene el int dat
int ArbolABB::Altura(const int dat)
{
   int altura = 0;
}
// Contar el nÃºmero de nodos
const int ArbolABB::NumeroNodos(){
   contador = 0;
   auxContador(raiz); // FUnciÃ³n auxiliar
   return contador;
}

// FunciÃ³n auxiliar para contar nodos. FunciÃ³n recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ArbolABB::auxContador(Nodo *nodo){
}

// Calcular la altura del Ã¡rbol, que es la altura del nodo de mayor altura.
const int ArbolABB::AlturaArbol(){
}

void ArbolABB::auxAltura(Nodo *nodo, int a){
}
// Poda: borrar todos los nodos a partir de uno, incluido
void ArbolABB::Podar(Nodo* &nodo){
}