#pragma once
#include <iostream>
#include "GotoXY.h"
#include "Position.h"
#include "Game.h"
const char UP = 'w';
const char DOWN = 'x';
const char RIGHT = 'd';
const char LEFT = 'a';
const char PAUSE = 27;
const char STAY = 's';
const int StartRow = 12;
const int StartCol = 30;
const int StartScore = 0;
const int StartLives = 3;

//pacman starts in 30,10
//update ctor to const values, add const to start pacman location
class Pacman
{
private:
	Position _pos;
	int _score;
	int _remaininglives;
	char _direction;
public:
	Pacman(const int row = StartRow, const int col = StartCol, const int score = StartScore, const int Lives = StartLives, const char direction = STAY);
	~Pacman();
	void setPacmanPosition();
	void setPacmanScore(int bonus = 1);
	void setPacmanLives(int minus = 1);
	void setPacmanDirection(const char direction);
	void printPacman();
	int getPacmanRow();
	int getPacmanCol();
	int getPacmanScore()const;
	int getPacmanLives()const;
	void ResetPos();
	char getPacmanDirection()const;
	bool CheckIfPacmanHitWall(GameBoard board[][SizeCol]);


};