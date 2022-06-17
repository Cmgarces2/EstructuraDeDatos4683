#include <bits/stdc++.h>
#include <string.h>
#include <string>
#include "Pila.cpp"
#include <cmath>
#include <cstdlib>
using namespace std;

class Funciones{
	public:
		string Acortarfuncion(string s);
		string DesAcortarfuncion(string s);
		int OrdenDeOperadores(char c);
		string Infija_Posfija(string s);
		bool EsOperador(char x);
		string Obtener_Solucion(string exp);
		string Infija_Prefija(string infix);
};

string Funciones::Acortarfuncion(string s)
{
	string aux;
	for (int i = 0; i < s.length(); i++){
		char c = s[i];
		if(s[i]=='S'||s[i]=='s'){
			if(s[i+1]=='E'||s[i+1]=='e'){
				if(s[i+2]=='N'||s[i+2]=='n'){
					aux += '!';
					i++;
					i++;
				}
			}else if(s[i+1]=='Q'||s[i+1]=='q'){
				if(s[i+2]=='R'||s[i+2]=='r'){
					if(s[i+3]=='T'||s[i+3]=='t'){
						aux += '$';
						i++;
						i++;
						i++;	
					}	
				}
			}else
				aux += c;	
		}else if(s[i]=='C'||s[i]=='c'){
			if(s[i+1]=='O'||s[i+1]=='o'){
				if(s[i+2]=='S'||s[i+2]=='s'){
					aux += '@';
					i++;
					i++;
				}
			}else
				aux += c;	
		}else if(s[i]=='T'||s[i]=='t'){
			if(s[i+1]=='A'||s[i+1]=='a'){
				if(s[i+2]=='N'||s[i+2]=='n'){
					aux += '#';
					i++;
					i++;
				}
			}else
				aux += c;	
		}else{
			aux += c;
		}	
	}
	return aux;
}

string Funciones::DesAcortarfuncion(string s){
	string aux;
	for (int i = 0; i < s.length(); i++){
		char c = s[i];
		if(s[i]=='!'){
			aux += 'S';
			aux += 'e';
			aux += 'n';
		}else if(s[i]=='@'){
			aux += 'C';
			aux += 'o';
			aux += 's';
		}else if(s[i]=='#'){
			aux += 'T';
			aux += 'a';
			aux += 'n';
		}else if(s[i]=='$'){
			aux += 'S';
			aux += 'q';
			aux += 'r';
			aux += 't';
		}else{
			aux += c;
		}
	}
	return aux;
}

int Funciones::OrdenDeOperadores(char c)
{
	if (c == '!')
		return 7;
	else if (c == '@')
		return 6;
	else if (c == '#')
		return 5;
	else if (c == '$')
		return 4;	
	else if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

string Funciones::Infija_Posfija(string s)
{

	Pila *nuevo = new Pila();
	string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0' && c <= '9'))
		{	
				result += c;
		}
		else if (c == '(')
			nuevo->push('(');
		else if (c == ')') {
			while (nuevo->top->elemento != '(') {
				result += nuevo->top->elemento;
				nuevo->pop();
			}
			nuevo->pop();
		}
		else {
			while (!nuevo->vacia()&& OrdenDeOperadores(s[i]) <= OrdenDeOperadores(nuevo->top->elemento)) {
				if (c == '^' && nuevo->top->elemento == '^')
					break;
				else {
					result += nuevo->top->elemento;
					nuevo->pop();
				}
			}
			nuevo->push(c);
		}
	}
	while (!nuevo->vacia()) {
		result += nuevo->top->elemento;
		nuevo->pop();
	}
	return result;
}

bool Funciones::EsOperador(char x)
{
return ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')|| (x >= '0' && x <= '9'));
}

/*string Funciones::Obtener_Solucion(string exp)
{
	Pila *nuevo = new Pila();
	int x; 
	double res;
	for (int i=0; i < exp.length() ; i++)
	{
		if (EsOperador(exp[i]))
		{
		char op = exp[i];
		nuevo->push(op);
		}
		else
		{
			if(exp[i]=='!'){
				char * op2 = new char[1];
				char op1[3];
				*op2 = nuevo->top->elemento;
				nuevo->pop();
				x=atoi(op2);
				res=sin(x);
				op1=ftoa(res);
				nuevo->push(exp[i] + op2 );
			}else if(exp[i]=='@'){
				
			}else if(exp[i]=='#'){
				
			}else if(exp[i]=='$'){
				string op2 = nuevo->top->elemento;
				s.pop();
				nuevo->push(exp[i] + op2 );
			}else{
				string op1 = nuevo->top->elemento;
				s.pop();
				string op2 = nuevo->top->elemento;
				s.pop();
				nuevo->push("(" + op2 + exp[i] + op1 + ")");
			}
			
		}
	}
	return nuevo->top->elemento;
}*/


string Funciones::Infija_Prefija(string infix)
{
	int l = infix.size();
	reverse(infix.begin(), infix.end());
	for (int i = 0; i < l; i++) {

		if (infix[i] == '(') {
			infix[i] = ')';
			i++;
		}
		else if (infix[i] == ')') {
			infix[i] = '(';
			i++;
		}
	}
	string prefix = Infija_Posfija(infix);
	reverse(prefix.begin(), prefix.end());
	return prefix;
}



