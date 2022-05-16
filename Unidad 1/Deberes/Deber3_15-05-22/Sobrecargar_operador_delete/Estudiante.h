#include<iostream>
#include<stdlib.h>
using namespace std;

class estudiante{
	string nombre;
	int edad;
	
	public:
		estudiante(){
			cout<<"llamada al constructor \n";
		}
		
		estudiante(string nombre, int edad)
		{
			this-> nombre = nombre;
			this -> edad = edad;
		}
		
		void mostrar()
		{
		cout<< "Nombre:" << nombre << endl;
        cout<< "Edad:" << edad << endl;
		}

 
	     void * operator new(size_t size)   //recibe el tamaño de tipo de memoria que espesifica cuantos bytes se asignaran.
		{
			cout<< "sobrecargando el operador new tamanio: " << size << endl;
       		 void * p = :: new estudiante(size);   // sobrecarga de operador global 
        //void * p = malloc(size);
       		 return p;  //devuelve un puntero 
    	}
        void operator delete(void * p){
        	cout<<"sobrecargando el operador delete"<<endl;
        	free(p);
		}
};
