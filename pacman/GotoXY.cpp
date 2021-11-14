#include "GotoXY.h"
///***************************************
//  Credit for finding this code goes to:
//          Yoav  Aharoni
//      [yoav_ah@netvision.net.il]
//***************************************/
//

//

//
/*
int main()
{
//write text in 4 corners of the screen
	clrscr(); // function call
	gotoxy(10,10); // function call
	cout << "at 10,10";
	gotoxy(10,20); // function call
	cout << "at 10,20";
	gotoxy(20,10); // function call
	cout << "at 20,10";
	gotoxy(20,20); // function call
	cout << "at 20,20";
	return 0;
}*/
//
//// function definition -- requires windows.h
void gotoxy(const int& row,const int& col)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = col;
	dwCursorPosition.Y = row;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}

//// function definition -- requires process.h
void clrscr()
{
	system("cls");
}

int getKey()
{
	char KeyStroke = _getch();
	if (KeyStroke == 0 || KeyStroke == -32)
		KeyStroke = _getch();
	return (KeyStroke);
}