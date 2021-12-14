#pragma once
#include "Position.h"
#include "GotoXY.h"
#include "GameBoard.h"
enum class Direction { Up, Down, Left, Right };
class GameObject 
{
public:
	void SetPosition(const int row, const int col);

	bool CheckWall(const int& row, const int& col, vector<vector<GameBoard>> board);
	bool CheckTunnel(const int& row, const int& col, vector<vector<GameBoard>> board);
	bool Obstacle(const int& row, const int& col, vector<vector<GameBoard>> board, Direction direction);
	Direction SetMove(GameBoard board[][SizeCol]);

	int getRow();
	int getCol();

protected:
	Position _pos;
};

