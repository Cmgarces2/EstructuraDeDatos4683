#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;

void LoginU()
{
        int count;
        string Usuario,Contrasenia,x,y;
        system("cls");
        cout<<"ingrese la siguiente informacion"<<endl;
        cout<<"Nombre de Usuario :";
        cin>>Usuario;
        cout<<"Contrasenia :";
        cin>>Contrasenia;

        ifstream inyut("base_de_datos.txt");
        while(inyut>>x>>y)
        {
                if(x==Usuario && y==Contrasenia)

                {
                        count=1;
                        system("cls");
                }
        }
        inyut.close();
        if(count==1)
        
        {
                cout<<"\n Bienvenido\n"<<Usuario<<"Gracias por iniciar Sesion\n";
                cin.get();
                cin.get();
                char dato[10];
   int c;
   ListaCircularDoble *CDLL = new ListaCircularDoble();
   int opc;
	do{
		system("cls");
		opc=CDLL->menu();
		switch(opc)
		{
			case 1:{
				CDLL -> insertar_inicio(new Nodo());
				break;
			}
			case 2:{
				CDLL -> insertar_final(new Nodo());	            
				break;
			}
			case 3:{
				CDLL -> insertar_posicion(new Nodo());     
				break;
			}
			case 4:{
				CDLL -> eliminar_posicion();
				break;
			}
			case 5:{
				CDLL -> actualizar();			            
				break;
			}
			case 6:{
				CDLL -> buscar();			            
				break;
			}
			case 7:{
				CDLL -> mostrar();			            
				break;
			}
			case 8:{
				CDLL -> guardar();			            
				break;
			}
			case 0:{
				int a=0, b=56, c=0, n=0;
				char t[40] ="Adios, gracias por usar el programa :D ";
				do
				{
					for (a=1;a<=56;a++)
					{
						system("cls");
						gotoxy(a,1);
						cout<<t;
						Sleep (50);
					}
					for (b=56;b>=1;b--)
					{
					system("cls");
					gotoxy(b,1);
					cout<<t;
					Sleep (50);
					}
				}while (c=1);
				getch ();
					cout<<"\n"<<endl;
				break;
			}
			default:{
				cout<<"\nError. Opcion incorrecta"<<endl;
				break;
			}
		}
		system("pause");
	}while(opc!=0);

        }
        else
        {
                cout<<"\nError, compruebe su usuario y contraseña\n";

        }
}
void registro()
{

        string regUsuario,regContrasenia;
        system("cls");
        regUsuario=ingresarDatosCHAR("\nIngrese el nombre de Usario : \n");
		regContrasenia=ingresarDatosCHAR("\nIngrese la contrasenia : \n");

        ofstream reg("base_de_datos.txt",ios::app);
        reg<<regUsuario<<' '<<regContrasenia<<endl;
        system("cls");
        cout<<"\n El registro fue Exitoso\n";



}

int menu2()
{
	int opc;
		cout<<"\n\n";
	    cout<<"                 Registgro de vehiculos                              \n\n";
	    cout<<"                          MENU        \n\n";
	    cout<<"1.Inicial Sesion\n";
	    cout<<"2.Registarse\n";
	    cout<<"3.Exit\n";
	opc=TransformaraInt(ingresarDatos("\nIngrese una opcion: "));
			return opc;	        
}	



