/*UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

Programa para ingresar un binario y despues tranformarlo a decimal

Autores: Christian Garces
		 luciana Guerra

Fecha de Creacion:  19 de mayo del 2022

Version del programa: Version 1

Materia: Estructuras de datos

Nrc: 4683
*/

#include<stdio.h>
#include<iostream>
#include "Binario_a_Decimal.h"

using namespace std;


int main()
{
    Binario_a_Decimal binario_a_Decimal;
    int NumeroBinario;
    
    binario_a_Decimal.IngresarValores();
    NumeroBinario = binario_a_Decimal.getNumero1();
    cout <<"El numero " << NumeroBinario << " transformado a decimal es: " <<binario_a_Decimal.binario_a_decimal(NumeroBinario);

    
}
