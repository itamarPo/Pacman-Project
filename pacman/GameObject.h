#pragma once
#include "Position.h"
#include "GotoXY.h"
#include "GameBoard.h"
#include <vector>
enum class Direction { Up, Down, Left, Right };
class GameObject 
{
public:
	void SetPosition(const int row, const int col);

	bool CheckWall(const int& row, const int& col, vector<vector<GameBoard>> board);
	bool CheckTunnel(const int& row, const int& col, vector<vector<GameBoard>> board);
	bool Obstacle(const int& row, const int& col, vector<vector<GameBoard>> board, Direction direction);
	Direction SetMove(vector<vector<GameBoard>> board);
	void Movement(vector<vector<GameBoard>> board);

	int getRow();
	int getCol();

protected:
	Position _pos;
	Direction _direction;
};

