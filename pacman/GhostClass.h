#pragma once
#include <iostream>
#include "GameObject.h"
#include "GotoXY.h"
#include "Game.h"
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

	int getGhostRow();
	int getGhostCol();
	GhostDirection GetDirection();

	void Print();
	void UpdateMove(GameBoard board[][SizeCol]);
	GhostDirection SetMove(GameBoard board[][SizeCol]);
	void Movement(GameBoard board[][SizeCol]);
	bool Obstacle(const int& x, const int& y, GameBoard board[][SizeCol], GhostDirection direction) const;

private:
	Position _pos;
	int move_counter;
	GhostDirection direction;
};

