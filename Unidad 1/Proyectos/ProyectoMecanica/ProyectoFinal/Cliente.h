#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;

class Cliente
{
	private:
		string Nombre;
		string Apellido;
		int Cedula;
		string Tipo_de_Auto;
		string placa;
		string color;
		string marca;
		string id;
	public:
		Cliente();
		void SetCliente(string _Nombre,string _Apellido,int _Cedula,string _Tipo_de_Auto,string _placa,string _color,string _marca,string _id);
		void SetNombre(string);
		void SetApellido(string);
		void SetCedula(int);
		void SetTipo_de_Auto(string);
		void SetPlaca(string);
		void SetColor(string);
		void SetMarca(string);
		void Setid(string);
		string GetNombre();
		string GetApellido();
		int GetCedula();
		string GetTipo_de_Auto();
		string GetPlaca();
		string GetColor();
		string GetMarca();
		string Getid();
		void obtener_id();
};

Cliente::Cliente(){
}

void Cliente::SetCliente(string _Nombre,string _Apellido,int _Cedula,string _Tipo_de_Auto,string _placa,string _color,string _marca,string _id){
	
	Nombre = _Nombre;
	Apellido = _Apellido;
	Cedula = _Cedula;
	Tipo_de_Auto = _Tipo_de_Auto;
	placa = _placa;
	color = _color;
	marca = _marca;
	id = _id;
	
}

void Cliente::SetNombre(string _Nombre){
	Nombre = _Nombre;
}

void Cliente::SetApellido(string _Apellido){
	Apellido = _Apellido;
}

void Cliente::SetCedula(int _Cedula){
	Cedula = _Cedula;
}

void Cliente::SetTipo_de_Auto(string _Tipo_de_Auto){
	Tipo_de_Auto = _Tipo_de_Auto;
}

void Cliente::SetColor(string _color){
	color = _color;
}

void Cliente::SetPlaca(string _placa){
	placa = _placa;
}

void Cliente::SetMarca(string _marca){
	marca = _marca;
}

void Cliente::Setid(string _id){
	id = _id;
}

string Cliente::GetNombre(){
	return Nombre;
}

string Cliente::GetApellido(){
	return Apellido;
}

int Cliente::GetCedula(){
	return Cedula;
}

string Cliente::GetTipo_de_Auto(){
	return Tipo_de_Auto;
}

string Cliente::GetColor(){
	return color;
}

string Cliente::GetPlaca(){
	return placa;
}

string Cliente::GetMarca(){
	return marca;
}

string Cliente::Getid(){
	return id;
}

void Cliente::obtener_id(){
	string email;
	string color_letra = GetColor();
	email += GetPlaca();
	email += color_letra[0];
	email += GetMarca();
	Setid(email);
}

