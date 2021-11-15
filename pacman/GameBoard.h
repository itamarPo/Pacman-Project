#pragma once
#include <iostream>
const int SizeRow = 20;
const int SizeCol = 60;
const char FOOD = 248;
#include "GotoXY.h"
#include "Position.h"
extern bool Color;
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define WHITE   "\033[37m"      /* White */
#define RESET   "\033[0m"
#define GRAY	"\033[30;1m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"      /* Cyan */
#define FOODCOLOR "\u001b[35;1m"
class GameBoard
{
private:
	//Position pos;
	char _sign;
public:
	GameBoard();
	~GameBoard();
	void setGamePiece(const char ch);
	void printPiece(const int& x, const int& y) const;
	//int getXpiece() const;
	//int getYpiece()const;
	char getSignpiece() const;
	
};





