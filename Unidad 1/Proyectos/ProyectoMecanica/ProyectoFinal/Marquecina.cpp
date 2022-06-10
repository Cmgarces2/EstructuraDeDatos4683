#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

void gotoxy(int x, int y) 
{ 
    COORD coord;
    coord.X = x; 
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


main ()
{
int a=0, b=56, c=0, n=0;
char t[25] ="Bienvenido";
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
}
