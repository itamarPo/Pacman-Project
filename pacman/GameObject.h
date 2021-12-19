#pragma once
#include "Position.h"
#include "GameBoard.h"
#include <vector>
enum class Direction { Up, Down, Left, Right, Stay };
class GameObject 
{
protected:
	Position _pos;
	Position _startPos;
	Direction direction = Direction::Stay;
public:
	void SetPosition(const int row, const int col);

	bool CheckWall(const int& row, const int& col, const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board);
	virtual bool CheckTunnel(const int& row, const int& col, const int& maxRow,const int& maxCol, vector<vector<GameBoard>> board);
	bool Obstacle(const int& row, const int& col, const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board, Direction direction);
	Direction SetMove(const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board);
	void Movement(vector<vector<GameBoard>> board);
	void setStartPosition(const int& row, const int& col);
	
	
	int getStartRow() const;
	int getStartCol() const;
	int getRow() const;
	int getCol() const;


};

