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

