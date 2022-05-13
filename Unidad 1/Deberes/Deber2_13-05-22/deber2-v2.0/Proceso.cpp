#include "Proceso.h"

using namespace std;

Proceso::Proceso(char _datos[10]){
	datos = _datos[10]
}

char Proceso::ingresarDatos(char){
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

void Proceso::mostrarAbs(tipod numero){
	cout<<"\nEl valor ingresado es: \n"<<numero;
}

void Proceso::TransformaraFloat(char){
	float valor;
	valor=atof(dato);
	mostrarAbs(valor);
}

void Proceso::TransformaraInt(char){
	int valor;
	valor=atoi(dato);
	mostrarAbs(valor);
}
	
void Proceso::TransformaraString(char){
	char strdato[10];
    strcpy(strdato,dato);
    printf("\nEl valor ingresado es un String:\n%s\n", strdato);
}

void Proceso::Trycatch(char){
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


