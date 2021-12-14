#pragma once
#include <iostream>
#include "GotoXY.h"
#include "Position.h"
#include "Game.h"
#include "GameObject.h"
const char Pacman_sign = '@';
const char UP = 'w';
const char UPW = 'W';
const char DOWN= 'x';
const char DOWNX = 'X';
const char RIGHT = 'd';
const char RIGHTD = 'D';
const char LEFT = 'a';
const char LEFTA = 'A';
const char PAUSE = 27;
const char STAY = 's';
const char STAYS = 'S';
const int StartRow = 10;
const int StartCol = 30;
const int StartScore = 0;
const int StartLives = 3;
extern bool Color;

class Pacman : public GameObject
{
private:
	Position _pos;
	Position _startPos;
	int _score;
	int _remaininglives;
	char _direction;

public:
	Pacman(const int row = 0, const int col = 0, const int score = StartScore, const int Lives = StartLives, const char direction = STAY);
	~Pacman();
	void setPacmanPosition();
	void setPacmanStartPosition(const int& row, const int& col);
	void setPacmanScore(int bonus = 1);
	void setPacmanLives(int minus = 1);
	void setPacmanDirection(const char& direction);
	void setPacmanIfTunnel(const int row, const int col);
	void printPacman() const; 
	int getPacmanRow();
	int getPacmanCol();
	int getPacmanScore() const;
	int getPacmanLives() const;
	void ResetPos();
	char getPacmanDirection()const;
	bool CheckIfPacmanHitWall(vector<vector<GameBoard>> board); // add parameters


};
