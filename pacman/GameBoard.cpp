#include "GameBoard.h"


GameBoard::GameBoard()
{
	_sign = 0;
}

GameBoard::~GameBoard()
{
}

void GameBoard::setGamePiece(const char ch)
{
	/*
	_x = x;
	_y = y;
	*/
	_sign = ch;
}

void GameBoard::printPiece(const int& x, const int& y) const
{
			gotoxy(x, y);
			cout << getSignpiece();
}

/*
int GameBoard::getXpiece() const
{
	return _x;
}

int GameBoard::getYpiece() const
{
	return _y;
}
*/
char GameBoard::getSignpiece() const
{
	return _sign;
}
