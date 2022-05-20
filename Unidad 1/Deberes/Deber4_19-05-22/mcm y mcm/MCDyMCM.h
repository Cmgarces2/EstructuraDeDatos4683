#include<iostream>

using namespace std;

class MCDyMCM{
	private:
		int a;
		int b;
	public: 
		int MCD(int a,int b);
		int MCM(int a,int b, int c);
		void IngresarValores();
		int getNumero1();
		int getNumero2();
		
};

void MCDyMCM::IngresarValores(){
	cout<<"Ingrese el primer numero :"<<endl;
	cin>>a;
	cout<<"Ingrese el segundo numero :"<<endl;
	cin>>b;
}

int MCDyMCM::getNumero1(){
	return a;
}

int MCDyMCM::getNumero2(){
	return b;
}

int MCDyMCM::MCD(int a,int b){
 if(a>=b && a%b==0){
 return b;
 }
    else{
 return MCD(b,a%b);
 }
}

int MCDyMCM::MCM(int a,int b, int c){
 return ((a*b)/c);
}
