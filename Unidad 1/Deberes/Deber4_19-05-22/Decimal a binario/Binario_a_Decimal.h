#include<stdio.h>
#include<iostream>

using namespace std;

class Binario_a_Decimal{
	private:
		int numero;
	public:
		int binario_a_decimal(int n);
		void IngresarValores();
		int getNumero1();
};

int Binario_a_Decimal::binario_a_decimal(int n)
{
    if(n==0)
        return 0;
    else
        return (n % 10 + 2* binario_a_decimal(n / 10));
}

void Binario_a_Decimal::IngresarValores(){
	cout<<"Ingrese el numero a convertir:"<<endl;
	cin>>numero;
}

int Binario_a_Decimal::getNumero1(){
	return numero;
}
