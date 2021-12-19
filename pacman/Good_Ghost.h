#pragma once
#include "GhostClass.h"
class Good_Ghost : public Ghost
{
private:
	bool smart = false;

public:
	virtual void UpdateMove(const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board , Pacman & pacman);
};

