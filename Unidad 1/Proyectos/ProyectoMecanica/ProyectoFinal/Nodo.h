#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "Ingreso.h"
#include "Cliente.h"


using namespace std;

class Nodo
{
public:
    Cliente *valor;
    Nodo *siguiente;
    Nodo *anterior;
    Nodo();
};

Nodo::Nodo()
{
	valor = new(Cliente);
    this -> valor->SetNombre(ingresarDatosCHAR("Ingrese el Nombre: "));
    this -> valor->SetApellido(ingresarDatosCHAR("\nIngrese Apellido: "));
    this -> valor->SetCedula(TransformaraInt(ingresarDatos("\nIngrese la Cedula: ")));
    this -> valor->SetTipo_de_Auto(ingresarDatosCHAR("\nIngrese el tipo de auto: "));
    this -> valor->SetPlaca(ingresarDatosCHAR("\nIngrese la Placa del veiculo: "));
    this -> valor->SetColor(ingresarDatosCHAR("\nIngrese el color del veiculo:  "));
    this -> valor->SetMarca(ingresarDatosCHAR("\nIngrese la marca del vaiculo: "));
    this -> valor->obtener_id();
    this -> anterior = NULL;
    this -> siguiente = NULL;
}
