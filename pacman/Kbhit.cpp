#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

// function definition -- requires windows.h
/*
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
/*
void main()
{
	system("cls");
	
	_flushall();

	int x=1;
	int y=1;

	// esc (Ascii 27) ends the loop
	while(!_kbhit() || _getch()!=27)
	{
		gotoxy(x,y);
		cout << "*" << endl;
		Sleep(1000);
		gotoxy(x,y);
		cout << " " << endl;
		++x;
		if(x>79) {x=1;}
		++y;
		if(y>20) {y=1;}
	}

}*/

//kbhit - returns nonzero if a char was enterd, 0 otherwise.