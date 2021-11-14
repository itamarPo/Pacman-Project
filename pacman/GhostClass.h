#pragma once
#include <iostream>
#include "Position.h"
#include "GotoXY.h"
#include "Game.h"
using namespace std;
const int StartGhostRow = 7;
const int StartGhostCol = 54;
enum GhostDirection{Up_G, Down_G, Left_G, Right_G};
class Ghost
{
public:
	Ghost();
//positions are going to be decided in the future.
	~Ghost();


	void SetPosition(const int x, const int y);

	int getGhostX();
	int getGhostY();
	GhostDirection GetDirection();

	void Print();
	void UpdateMove(GameBoard board[][SizeCol]);
	GhostDirection SetMove(GameBoard board[][SizeCol]);
	void Movement(GameBoard board[][SizeCol]);
	bool GhostObstacle(const int& x, const int& y, GameBoard board[][SizeCol], GhostDirection direction) const;

private:
	Position _pos;
	int move_counter;
	GhostDirection direction;
	//add direction
};

