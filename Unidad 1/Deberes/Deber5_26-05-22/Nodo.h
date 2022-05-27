/***********************************************************************
 * Module:  Nodo.h
 * Author:  Luci
 * Modified: jueves, 26 de mayo de 2022 22:22:26
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Nodo_h)
#define __Class_Diagram_1_Nodo_h

class Nodo
{
public:
   void* getSiguiente(void);
   void setSiguiente(void* newSiguiente);
   int getValor(void);
   void setValor(int newValor);
   Nodo(int _valor, Nodo _siguiente);
   ~Nodo();

protected:
private:
   int valor;
   void* siguiente;


};

#endif