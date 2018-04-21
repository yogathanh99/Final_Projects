/*
Header for UI more attractive
*/

#ifndef UI_H
#define UI_H

#include <iostream> 
#include <conio.h>
#include <Windows.h>
using namespace std;

//Resize Console
void resizeConsole(int width, int height);

//Change color text
void textcolor(int x);

//Go to (x,y)
void gotoxy(int x, int y);

void UI();
#endif // !UI_H