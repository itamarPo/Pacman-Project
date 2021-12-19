#pragma once
#include "GameObject.h"
#include "PacmanClass.h"
#include <queue>

using namespace std;
const int StartGhostRow = 7;
const int StartGhostCol = 54;
//enum GhostDirection{Up_G, Down_G, Left_G, Right_G};
const char Ghost_sign = '$';
extern bool Color;
class Ghost : public GameObject
{
public:
	Ghost();
	~Ghost();

	void SetPosition(const int row, const int col);
	Direction GetDirection();

	void Print()const;
	virtual void UpdateMove(const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board , Pacman & pacman);
	virtual Direction SmartMove(const int& maxRow, const int& maxCol,Pacman &pacman, vector<vector<GameBoard>> board) = 0;
	
	//GhostDirection SetMove(GameBoard board[][SizeCol]);
	//void Movement(vector<vector<GameBoard>> board);
	//bool Obstacle(const int& x, const int& y, GameBoard board[][SizeCol], GhostDirection direction) const;
	

private:
	int move_counter;
};

class Qitem
{
public:
	Position _pos;
	Direction _direction;
	Qitem(Position& pos, Direction dir) : _pos(pos)
	{
		_direction = dir;
	}

};