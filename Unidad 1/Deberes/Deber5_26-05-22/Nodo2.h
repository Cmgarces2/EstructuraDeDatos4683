/***********************************************************************
 * Module:  Nodo2.h
 * Author:  Luci
 * Modified: jueves, 26 de mayo de 2022 23:05:04
 * Purpose: Declaration of the class Nodo2
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Nodo2_h)
#define __Class_Diagram_1_Nodo2_h

class Nodo2
{
public:
   void Insertar(void);
   void Buscar(void);
   void Imprimir_Cola(void);
   void Imprimir_Cabeza(void);
   void Eliminar(void);
   Nodo2();
   ~Nodo2();
   int getValor(void);
   void setValor(int newValor);

protected:
private:
   int valor;
   void* siguiente;


};

#endif