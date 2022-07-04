#include <iostream>
using namespace std;

class ArbolABB {
  private:
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

   Nodo *raiz;
   Nodo *actual;
   int contador;
   int altura;

  public:
   ArbolABB() : raiz(NULL), actual(NULL) {}
   ~ArbolABB() { Podar(raiz); }
   void Insertar(const int dat);
   void Borrar(const int dat);
   bool Buscar(const int dat);
   bool Vacio(Nodo *r) { return r==NULL; }
   bool EsHoja(Nodo *r) { return !r->derecho && !r->izquierdo; }
   const int NumeroNodos();
   const int AlturaArbol();
   int Altura(const int dat);
   int &ValorActual() { return actual->dato; }
   void Raiz() { actual = raiz; }
   void InOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
   //void PreOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
   //void PostOrden(void (*func)(int&) , Nodo *nodo=NULL, bool r=true);
   
  private:
   void Podar(Nodo* &);
   void auxContador(Nodo*);
   void auxAltura(Nodo*, int);
};


void ArbolABB::Podar(Nodo* &nodo)
{
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

void ArbolABB::Insertar(const int dat)
{
   Nodo *padre = NULL;

   actual = raiz;
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat > actual->dato) actual = actual->derecho;
      else if(dat < actual->dato) actual = actual->izquierdo;
   }
   if(!Vacio(actual)) return;
   if(Vacio(padre)) raiz = new Nodo(dat);
   else if(dat < padre->dato) padre->izquierdo = new Nodo(dat);
   else if(dat > padre->dato) padre->derecho = new Nodo(dat);
}

void ArbolABB::InOrden(void (*func)(int&) , Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}


// FunciÃ³n auxiliar para contar nodos. FunciÃ³n recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void ArbolABB::auxContador(Nodo *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->izquierdo) auxContador(nodo->izquierdo);
   if(nodo->derecho)   auxContador(nodo->derecho);
}


void ArbolABB::auxAltura(Nodo *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // Ã¡rbol, actualizamos la altura actual del Ã¡rbol
   if(EsHoja(nodo) && a > altura) altura = a;
}

void Mostrar(int &d)
{
   cout << d << ",";
}