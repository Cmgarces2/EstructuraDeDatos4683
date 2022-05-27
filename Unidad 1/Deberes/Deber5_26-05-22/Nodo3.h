/***********************************************************************
 * Module:  Nodo3.h
 * Author:  Luci
 * Modified: jueves, 26 de mayo de 2022 23:10:16
 * Purpose: Declaration of the class Nodo3
 ***********************************************************************/

#if !defined(__Class_Diagram_1_Nodo3_h)
#define __Class_Diagram_1_Nodo3_h

class Nodo3
{
public:
   virtual void Insertar(void)=0;
   virtual void Buscar(void)=0;
   virtual void Imprimir_Cola(void)=0;
   virtual void Imprimir_Cabeza(void)=0;
   virtual void Eliminar(void)=0;

protected:
private:

};

#endif