/*        UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

Programa para determinar si la cadena ingresada es un int, float o string

Autores: Christian Garces
		 luciana Guerra

Fecha de Creacion:  12 de mayo del 2022

Version del programa: Version 1

Materia: Estructuras de datos

Nrc: 4683
*/

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

template <class tipod>
void mostrarAbs(tipod numero);
char ingresarDatos(char);
void TransformaraFloat(char);
void TransformaraInt(char);
void TransformaraString(char);
void Trycatch(char);
	
char *ingresarDatos(char *msg){
	char *dato=new char[10];
	char c;
	int i=0;
	printf("%s\n",msg);
	fflush(stdin);
	while((c=getch())!=13){
		if((c>='0')&& (c<='9')||(c='.')){
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	fflush(stdin);
	return dato;
}

void TransformaraFloat(char dato[10]){
	float valor;
	valor=atof(dato);
	mostrarAbs(valor);
}

void TransformaraInt(char dato[10]){
	int valor;
	valor=atoi(dato);
	mostrarAbs(valor);
}

void TransformaraString(char dato[10]){
 	char strdato[10];
    strcpy(strdato,dato);
    printf("\nEl valor ingresado es un String:\n%s\n", strdato);


}

void Trycatch(char dato[10]){
	int contadorpuntos=0;
	try{
		for(int i=0;i<10;i++){
			if(dato[i]=='.')
				contadorpuntos=contadorpuntos+1;
		}
		if(contadorpuntos>2)
		{
			contadorpuntos=0;
			throw dato;
		}	
		if(contadorpuntos==1)
		{
			contadorpuntos=0;
			throw 3;
		}	
		if(contadorpuntos==0)
		{
			contadorpuntos=0;
			throw 6.56;
		}	
    }
	catch(char dato[10]){
		TransformaraString(dato);
	}
	catch(int num){
		TransformaraFloat(dato);
		TransformaraInt(dato);
	}
	catch(double num){
		TransformaraInt(dato);
	}
}

template <class TIPOD>
void mostrarAbs(TIPOD numero){
	cout<<"\nEl valor ingresado es: \n"<<numero;
}

int main(int argc, char** argv) {
	char dato[10];
	strcpy(dato,ingresarDatos("Ingrese el valor numerico entero "));
	Trycatch(dato);

	return 0;
}