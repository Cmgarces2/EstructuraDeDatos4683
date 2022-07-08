#include <iostream>
using namespace std;

class ArbolABB {
  private:
   //// Clase local de Lista para Nodo de ArbolBinario:
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

// Poda: borrar todos los nodos a partir de uno, incluido
void ArbolABB::Podar(Nodo* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->izquierdo); // Podar izquierdo
      Podar(nodo->derecho);   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un int en el Ã¡rbol ABB
void ArbolABB::Insertar(const int dat)
{
   Nodo *padre = NULL;

   actual = raiz;
   // Buscar el int en el Ã¡rbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat > actual->dato) actual = actual->derecho;
      else if(dat < actual->dato) actual = actual->izquierdo;
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el Ã¡rbol estaba vacÃ­o, el nuevo nodo serÃ¡
   // el nodo raiz
   if(Vacio(padre)) raiz = new Nodo(dat);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat < padre->dato) padre->izquierdo = new Nodo(dat);
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat > padre->dato) padre->derecho = new Nodo(dat);
}

// Eliminar un elemento de un Ã¡rbol ABB
void ArbolABB::Borrar(const int dat)
{
   Nodo *padre = NULL;
   Nodo *nodo;
   int aux;

   actual = raiz;
   // Mientras sea posible que el valor estÃ© en el Ã¡rbol
   while(!Vacio(actual)) {
      if(dat == actual->dato) { // Si el valor estÃ¡ en el nodo actual
         if(EsHoja(actual)) { // Y si ademÃ¡s es un nodo hoja: lo borramos
            if(padre) // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->derecho == actual) padre->derecho = NULL;
               else if(padre->izquierdo == actual) padre->izquierdo = NULL;
            delete actual; // Borrar el nodo
            actual = NULL;
            return;
         }
         else { // Si el valor estÃ¡ en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo mÃ¡s izquierdo de rama derecha
            if(actual->derecho) {
               nodo = actual->derecho;
               while(nodo->izquierdo) {
                  padre = nodo;
                  nodo = nodo->izquierdo;
               }
            }
            // O buscar nodo mÃ¡s derecho de rama izquierda
            else {
               nodo = actual->izquierdo;
               while(nodo->derecho) {
                  padre = nodo;
                  nodo = nodo->derecho;
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por quÃ© ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sÃ³lo se eliminan nodos hoja.
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else { // TodavÃ­a no hemos encontrado el valor, seguir buscÃ¡ndolo
         padre = actual;
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
}

// Recorrido de Ã¡rbol en inorden, aplicamos la funciÃ³n func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::InOrden(void (*func)(int&) , Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) InOrden(func, nodo->izquierdo, false);
   func(nodo->dato);
   if(nodo->derecho) InOrden(func, nodo->derecho, false);
}

// Recorrido de Ã¡rbol en preorden, aplicamos la funciÃ³n func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PreOrden(void (*func)(int&), Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   func(nodo->dato);
   if(nodo->izquierdo) PreOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PreOrden(func, nodo->derecho, false);
}

// Recorrido de Ã¡rbol en postorden, aplicamos la funciÃ³n func, que tiene
// el prototipo:
// void func(int&);
void ArbolABB::PostOrden(void (*func)(int&), Nodo *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->izquierdo) PostOrden(func, nodo->izquierdo, false);
   if(nodo->derecho) PostOrden(func, nodo->derecho, false);
   func(nodo->dato);
}

// Buscar un valor en el Ã¡rbol
bool ArbolABB::Buscar(const int dat)
{
   actual = raiz;

   // TodavÃ­a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return true; // int encontrado
      else if(dat > actual->dato) actual = actual->derecho; // Seguir
      else if(dat < actual->dato) actual = actual->izquierdo;
   }
   return false; // No estÃ¡ en Ã¡rbol
}

// Calcular la altura del nodo que contiene el int dat
int ArbolABB::Altura(const int dat)
{
   int altura = 0;
   actual = raiz;

   // TodavÃ­a puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat > actual->dato) actual = actual->derecho;
         else if(dat < actual->dato) actual = actual->izquierdo;
      }
   }
   return -1; // No estÃ¡ en Ã¡rbol
}

// Contar el nÃºmero de nodos
const int ArbolABB::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnciÃ³n auxiliar
   return contador;
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

// Calcular la altura del Ã¡rbol, que es la altura del nodo de mayor altura.
const int ArbolABB::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // FunciÃ³n auxiliar
   return altura;
}

// FunciÃ³n auxiliar para calcular altura. FunciÃ³n recursiva de recorrido en
// postorden, el proceso es actualizar la altura sÃ³lo en nodos hojas de mayor
// altura de la mÃ¡xima actual
void ArbolABB::auxAltura(Nodo *nodo, int a)
{
   // Recorrido postorden
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // Ã¡rbol, actualizamos la altura actual del Ã¡rbol
   if(EsHoja(nodo) && a > altura) altura = a;
}

// FunciÃ³n de prueba para recorridos del Ã¡rbol
void Mostrar(int &d)
{
   cout << d << ",";
}