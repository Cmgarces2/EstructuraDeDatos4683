/*          UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE

Programa para calcular las posibles posiciones de un alfil e imprimir por consola

Autores: Christian Garces

Fecha de Creacion:  4 de agosto del 2022

Version del programa: Version 2.0

Materia: Estructuras de datos

Nrc: 4683
*/

#include <iostream>
#include <fstream>
using namespace std;
class Alfil{
	public:
		bool **validar;
		char **tablero;
		fstream archivo;
		int contador;
		int n;
		void encerarTablero(){
			for(int i=0;i<n;i++){
				validar[i]=new bool[n];
				tablero[i]=new char[n];
				for(int j=0;j<n;j++){
					*(*(validar+i)+j)=false;
					*(*(tablero+i)+j)='*';
				}
			}
		}
	void crearArchivo(){
		archivo.open("exaustivo.txt",fstream::out);
		archivo<<"solucion"<<n<<"*"<<n<<endl<<endl;
		contador=0;
	}
	Alfil(int n1){
		n=n1;
		validar=new bool *[n];
		tablero=new char *[n];
		encerarTablero();
		crearArchivo();
	}
	void bloquear(int x, int y){
		int aux1,aux2;
		aux2=y;//diagonal
		aux1=x;
		while(aux1>0&&aux2>0){
			aux1--;
			aux2--;
		}
		aux2=y;
		aux1=x;
		while(aux1<n && aux2>0){
			aux1++;
			aux2--;
		}
		aux1--;
		aux2++;
		while(aux1>=0 && aux2<n){
			*(*(validar+aux1)+aux2)=true;
			aux1--;
			aux2++;
		}
	}
	void mostrar(){
		contador++;
		cout<<"solucion N "<<contador <<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<*(*(tablero+i)+j)<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	void quitarRelleno(int x, int y){
		*(*(tablero +x)+y)='*';
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				*(*(validar +i)+j)=false;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(*(*(tablero +i)+j)=='A')
				bloquear(i,j);
			}	
		}
	}

	
	void solucion(int x, int y, int n1){
		*(*(tablero +x)+y)='A';
		bloquear(x,y);
		if(n1==n){
			mostrar();
		}else{
			for(int i=0;i<n;i++){
				if(*(*(validar +i )+ y+1)==false){
					solucion(i,y+1,n1+1);
				}
			}
		}
		quitarRelleno(x,y);
	}
	void solucionReinas(){
		for(int i=0;i<n;i++){
			solucion(i,0,1);
		}
		archivo.close();	
	}
};
int main(int argc, char** argv) {
	int n;
	cout<<"\tIngrese el numero de Alfiles"<<endl;
	cin>>n;
	Alfil *obj=new Alfil(n);
	obj->solucionReinas();
	//cout<<"Se creo el archivo txt"<<endl;
	return 0;
}
