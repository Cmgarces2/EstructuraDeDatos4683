/***********************************************************************
 * Module:  Nodo.cpp
 * Author:  Luci
 * Modified: jueves, 26 de mayo de 2022 22:22:26
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getSiguiente()
// Purpose:    Implementation of Nodo::getSiguiente()
// Return:     void*
////////////////////////////////////////////////////////////////////////

void* Nodo::getSiguiente(void)
{
   return siguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setSiguiente(void* newSiguiente)
// Purpose:    Implementation of Nodo::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setSiguiente(void* newSiguiente)
{
   siguiente = newSiguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getValor()
// Purpose:    Implementation of Nodo::getValor()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Nodo::getValor(void)
{
   return valor;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setValor(int newValor)
// Purpose:    Implementation of Nodo::setValor()
// Parameters:
// - newValor
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setValor(int newValor)
{
   valor = newValor;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::Nodo(int _valor, Nodo _siguiente)
// Purpose:    Implementation of Nodo::Nodo()
// Parameters:
// - _valor
// - _siguiente
// Return:     
////////////////////////////////////////////////////////////////////////

Nodo::Nodo(int _valor, Nodo _siguiente)
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::~Nodo()
// Purpose:    Implementation of Nodo::~Nodo()
// Return:     
////////////////////////////////////////////////////////////////////////

Nodo::~Nodo()
{
   // TODO : implement
}