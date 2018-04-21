#include "UI.h"

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void textcolor(int x)
{
	HANDLE color;
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, x);
}


void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void UI() {
	textcolor(3);
	gotoxy(27, 1);
	cout << "##      ## ######## ##        ######   #######  ##     ## ######## " << endl;
	textcolor(3);
	gotoxy(27, 2);
	cout << "##  ##  ## ##       ##       ##    ## ##     ## ###   ### ##       " << endl;
	textcolor(3);
	gotoxy(27, 3);
	cout << "##  ##  ## ##       ##       ##       ##     ## #### #### ##       " << endl;
	textcolor(3);
	gotoxy(27, 4);
	cout << "##  ##  ## ######   ##       ##       ##     ## ## ### ## ######   " << endl;
	textcolor(3);
	gotoxy(27, 5);
	cout << "##  ##  ## ##       ##       ##       ##     ## ##     ## ##       " << endl;
	textcolor(3);
	gotoxy(27, 6);
	cout << "##  ##  ## ##       ##       ##    ## ##     ## ##     ## ##       " << endl;
	textcolor(3);
	gotoxy(27, 7);
	cout << " ###  ###  ######## ########  ######   #######  ##     ## ######## " << endl;
}