#pragma once
#include "Position.h"
#include "GotoXY.h"
#include "GameBoard.h"
enum class Direction { Up, Down, Left, Right };
class GameObject
{
public:
	void SetPosition(const int row, const int col);

	bool CheckWall(const int& x, const int& y, GameBoard board[][SizeCol]);
	bool CheckTunnel(const int& row, const int& col, GameBoard board[][SizeCol]);
	bool Obstacle(const int& x, const int& y, GameBoard board[][SizeCol], Direction direction);
	Direction SetMove(GameBoard board[][SizeCol]);

	int getRow();
	int getCol();

protected:
	Position _pos;
};

