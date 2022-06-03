#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace  std;

class Proceso{
	private:
		char *dato=new char[10];
	public:
		char ingresarDatos(char);
		int TransformaraInt(char);

};

char *ingresarDatos(char *msg){
	char *dato=new char[10];
	char c;
	int i=0;
	printf("%s\n",msg);
	fflush(stdin);
	while((c=getch())!=13){
		if((c>='0')&& (c<='9')){
			printf("%c",c);
			dato[i++]=c;
		}
	}
	dato[i]='\0';
	fflush(stdin);
	return dato;
}

int TransformaraInt(char dato[10]){
	int valor;
	valor=atoi(dato);
	return valor;
}
