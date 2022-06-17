
#include <iostream>
#include <string>
#include "funciones.h"
using namespace std;

// Driver program to test above functions
int main(int argc, char** argv) {
	Funciones *hacer = new Funciones();
	/*string exp = "a+b+cos(5)";
	//infixToPostfix(exp);
	//cout<<Acortarfuncion(exp);
	hacerInfija_Posfija(Acortarfuncion(exp));
	cout<<DesAcortarfuncion(Infija_Posfija(Acortarfuncion(exp)))<<endl;
	cout << Infija_Prefija(exp)<<endl;
	string exp2 = "ab+5@+";
	cout << DesAcortarfuncion(Obtener_Infija(exp2))<<endl;*/
	cout << "Ingrese una ecuacion" << "\n" ;
	string infijo ;
	getline(cin, infijo);
	cout<<hacer->DesAcortarfuncion(hacer->Infija_Posfija(hacer->Acortarfuncion(infijo)))<<endl;
	cout<<hacer->DesAcortarfuncion(hacer->Infija_Prefija(hacer->Acortarfuncion(infijo)))<<endl;
	return 0;
}

