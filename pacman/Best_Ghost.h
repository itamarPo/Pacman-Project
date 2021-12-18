#include "GhostClass.h"
#pragma once
class Best_Ghost :  public Ghost
{
public:
	Direction SetMove(const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board, Pacman & pacman);
};

