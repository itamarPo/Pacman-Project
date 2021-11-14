#pragma once
#include <iostream>
const int SizeRow = 20;
const int SizeCol = 60;
const char FOOD = 248;
#include "GotoXY.h"
#include "Position.h"


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





