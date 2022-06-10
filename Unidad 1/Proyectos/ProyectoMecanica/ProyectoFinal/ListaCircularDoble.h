#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<istream>
#include<fstream>
#include "Nodo.h"



using namespace std;

class ListaCircularDoble
{
public:
    Nodo *primero;
    Nodo *ultimo;
    ListaCircularDoble();
    bool vacio();
    void insertar_inicio(Nodo *x);
	void insertar_final(Nodo *x);
    void insertar_posicion(Nodo *t);
    void eliminar_posicion();
    void buscar();
    void actualizar();
    void mostrar();
    void guardar();
    int menu();
	int menu2();    

};

ListaCircularDoble::ListaCircularDoble()
{
    this -> primero = NULL;
    this -> ultimo = NULL;
}

bool ListaCircularDoble::vacio()
{
    return (this -> primero == NULL);
}


int count = 0;

void ListaCircularDoble::insertar_inicio(Nodo *t)
{
    if (primero == ultimo && primero == NULL) {
      cout<<"Cliente agreegado al registro vacio"<<endl;
      primero = ultimo = t;
      primero->siguiente = ultimo->siguiente = NULL;
      primero->anterior = ultimo->anterior = NULL;
      count++;
   } else {
      t->siguiente = primero;
      primero->anterior = t;
      primero = t;
      primero->anterior = ultimo;
      ultimo->siguiente = primero;
      cout<<"Cliente Registrado"<<endl;
      count++;
   }
}

void ListaCircularDoble::insertar_final(Nodo *t)
{
	if (primero == ultimo && primero == NULL) {
      cout<<"Cliente agreegado al registro vacio"<<endl;
      primero = ultimo = t;
      primero->siguiente= ultimo->siguiente = NULL;
      primero->anterior = ultimo->anterior= NULL;
      count++;
   } else {
      ultimo->siguiente= t;
      t->anterior= ultimo;
      ultimo = t;
      primero->anterior = ultimo;
      ultimo->siguiente= primero;
      count++;
   }
}

void ListaCircularDoble::insertar_posicion(Nodo *t)
{	
	int v, pos, i;
	Nodo *s;
	Nodo *ptr;

   cout<<endl<<"Ingresar la pocicion el la cual se desea ingresar al cliente: ";
   pos=TransformaraInt(ingresarDatos("\nIngrese la Cedula: \n"));
   if (primero == ultimo && primero == NULL) {
      if (pos == 1) {
         primero = ultimo = t;
         primero->siguiente = ultimo->siguiente = NULL;
         primero->anterior = ultimo->anterior = NULL;
         count++;
      } else {
         cout<<"Posicion fuera del rango"<<endl;
         count--;
         return;
      }
   } else {
      if (count < pos) {
         cout<<"Posicion fuera del rango"<<endl;
         count--;
         return;
      }
      s = primero;
      for (i = 1;i <= count;i++) {
         ptr = s;
         s = s->siguiente;
         if (i == pos - 1) {
            ptr->siguiente = t;
            t->anterior= ptr;
            t->siguiente= s;
            s->anterior = t;
            cout<<"Cliente Registrado"<<endl;
            count++;
            break;
         }
      }
   }
}

void ListaCircularDoble::eliminar_posicion()
{
   int pos, i;
   Nodo *ptr, *s;
   if (primero == ultimo && primero == NULL) {
      cout<<"Registro vacio nada que borrar"<<endl;
      return;
   }
   cout<<endl<<"Ingresar la pocicicion del Cliente que desea borrar";
   cin>>pos;
   if (count < pos) {
      cout<<"Posicion fuera del rango"<<endl;
      return;
   }
   s = primero;
   if(pos == 1) {
      count--;
      ultimo->siguiente = s->siguiente;
      s->siguiente->anterior = ultimo;
      primero = s->siguiente;
      free(s);
      cout<<"Cliente Eliminado"<<endl;
      return;
   }
   for (i = 0;i < pos - 1;i++ ) {
      s = s->siguiente;
      ptr = s->anterior;
   }
   ptr->siguiente = s->siguiente;
   s->siguiente->anterior = ptr;
   if (pos == count) {
      ultimo = ptr;
   }
   count--;
   free(s);
   cout<<"Cliente Eliminado"<<endl;
}

void ListaCircularDoble::actualizar() {
   int v, i, pos;
   if (primero == ultimo && primero == NULL) {
      cout<<"Registro vacio nada que actualizar"<<endl;
      return;
   }
   cout<<endl<<"Ingresar la pocicicion del Cliente que desea borrar";
   cin>>pos;
   /*cout<<"Enter the new value: ";
   cin>>v;*/
   Nodo *s;
   if (count < pos) {
      cout<<"Posicion fuera del rango"<<endl;
      return;
   }
   s = primero;
   if (pos == 1) {
      s -> valor->SetNombre(ingresarDatosCHAR("\nIngrese el Nombre: "));
	  s -> valor->SetApellido(ingresarDatosCHAR("\nIngrese Apellido: "));
	  s -> valor->SetCedula(TransformaraInt(ingresarDatos("\nIngrese la Cedula: ")));
	  s -> valor->SetTipo_de_Auto(ingresarDatosCHAR("\nIngrese el tipo de auto: "));
	  s -> valor->SetPlaca(ingresarDatosCHAR("\nIngrese la Placa del veiculo: "));
	  s -> valor->SetColor(ingresarDatosCHAR("\nIngrese el color del veiculo:  "));
	  s -> valor->SetMarca(ingresarDatosCHAR("\nIngrese la marca del vaiculo: "));
	  s -> valor->obtener_id();
      cout<<"Registro Actualizado"<<endl;
      return;
   }
   for (i=0;i < pos - 1;i++) {
      s = s->siguiente;
   }
   s -> valor->SetNombre(ingresarDatosCHAR("\nIngrese el Nombre: \n"));
   s -> valor->SetApellido(ingresarDatosCHAR("\nIngrese Apellido: \n"));
   s -> valor->SetCedula(TransformaraInt(ingresarDatos("\nIngrese la Cedula: \n")));
   s -> valor->SetTipo_de_Auto(ingresarDatosCHAR("\nIngrese el tipo de auto: \n"));
   s -> valor->SetPlaca(ingresarDatosCHAR("\nIngrese la Placa del veiculo: \n"));
   s -> valor->SetColor(ingresarDatosCHAR("\nIngrese el color del veiculo:  \n"));
   s -> valor->SetMarca(ingresarDatosCHAR("\nIngrese la marca del vaiculo: \n"));
   s -> valor->obtener_id();
   cout<<"Registro Actualizado"<<endl;
}

void ListaCircularDoble::buscar() {
   int pos = 0, i;
   string v;
   bool flag = false;
   Nodo *s;
   if (primero == ultimo && primero == NULL) {
      cout<<"Registro vacio nada que buscar"<<endl;
      return;
   }
   cout<<endl<<"Ingrese el ide que desea buscar";
   v = ingresarDatosCHAR("Ingrese el id: ");
   s = primero;
   for (i = 0;i < count;i++) {
      pos++;
      if (s->valor->Getid() == v) {
         cout<<"id "<<v<<" encontrado en la posicion: "<<pos<<endl;
         flag = true;
      }
      s = s->siguiente;
   }
   if (!flag)
      cout<<"id no encontrada en el registro"<<endl;
}
void ListaCircularDoble::mostrar() {
   int i;
   Nodo *s;
   if (primero == ultimo && primero == NULL) {
      cout<<"el registro esta vacio"<<endl;
      return;
   }
   s = primero;
   for (i = 0;i < count-1;i++) {
      cout<<"---------------------"<<endl<<"Nombre: "<<s->valor->GetNombre()<<endl<<"Apellido: "<<s->valor->GetApellido()<<endl<<"Cedula: "<<s->valor->GetCedula()<<endl<<"Tipo de auto: "<<s->valor->GetTipo_de_Auto()<<endl<<"Placa: "<<s->valor->GetPlaca()<<endl<<"Color: "<<s->valor->GetColor()<<endl<<"Marca: "<<s->valor->GetMarca()<<endl<<"id: "<<s->valor->Getid()<<endl<<"---------------------"<<endl;
      s = s->siguiente;
   }
   cout<<"---------------------"<<endl<<"Nombre: "<<s->valor->GetNombre()<<endl<<"Apellido: "<<s->valor->GetApellido()<<endl<<"Cedula: "<<s->valor->GetCedula()<<endl<<"Tipo de auto: "<<s->valor->GetTipo_de_Auto()<<endl<<"Placa: "<<s->valor->GetPlaca()<<endl<<"Color: "<<s->valor->GetColor()<<endl<<"Marca: "<<s->valor->GetMarca()<<endl<<"id: "<<s->valor->Getid()<<endl<<"---------------------"<<endl;
}

void ListaCircularDoble::guardar() {
   int i;
   Nodo *s;
   if (primero == ultimo && primero == NULL) {
      cout<<"el registro esta vacio"<<endl;
      return;
   }
   s = primero;
   for (i = 0;i < count-1;i++) {
   		ofstream regis("Registro.txt",ios::app);
        regis<<"---------------------"<<endl<<"Nombre: "<<s->valor->GetNombre()<<endl<<"Apellido: "<<s->valor->GetApellido()<<endl<<"Cedula: "<<s->valor->GetCedula()<<endl<<"Tipo de auto: "<<s->valor->GetTipo_de_Auto()<<endl<<"Placa: "<<s->valor->GetPlaca()<<endl<<"Color: "<<s->valor->GetColor()<<endl<<"Marca: "<<s->valor->GetMarca()<<endl<<"id: "<<s->valor->Getid()<<endl<<"---------------------"<<endl;
        system("cls");
        cout<<"\n El registro fue Exitoso\n";
      s = s->siguiente;
   }
   ofstream regis("Registro.txt",ios::app);
   regis<<"---------------------"<<endl<<"Nombre: "<<s->valor->GetNombre()<<endl<<"Apellido: "<<s->valor->GetApellido()<<endl<<"Cedula: "<<s->valor->GetCedula()<<endl<<"Tipo de auto: "<<s->valor->GetTipo_de_Auto()<<endl<<"Placa: "<<s->valor->GetPlaca()<<endl<<"Color: "<<s->valor->GetColor()<<endl<<"Marca: "<<s->valor->GetMarca()<<endl<<"id: "<<s->valor->Getid()<<endl<<"---------------------"<<endl;
   system("cls");
   cout<<"\n El registro fue Exitoso\n";
}

int ListaCircularDoble::menu()
		{
			int opc;
			cout<<"\n****************************MENU****************************\n"<<endl
				<<"1. Ingresar un cliente prioritario a la lista"<<endl
				<<"2. Ingresar un cliente a la lista"<<endl
				<<"3. Ingresar un cliente a la lista en una posicion determinada"<<endl
				<<"4. Eliminar cliente del registro"<<endl
				<<"5. Actualizar un cliente del registro"<<endl
				<<"6. Buscar un cliente del registro mediante id"<<endl
				<<"7. Mostrar el registro"<<endl
				<<"8. Guardar el registro"<<endl
				<<"0. Salir"<<endl;
				
			opc=TransformaraInt(ingresarDatos("\nIngrese una opcion: "));
			return opc;	
		}
		
	
