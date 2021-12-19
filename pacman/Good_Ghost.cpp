#include "Good_Ghost.h"

void Good_Ghost::UpdateMove(const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board, Pacman& pacman)
{
	
	if (!smart)
	{
		if (move_counter == 5)
		{
			move_counter = 0;
			smart = true;
			direction = SmartMove(maxRow, maxCol, pacman, board);
		}
		else
		{
			direction = SetMove(maxRow, maxCol, board);
		}
	}
	else
	{
		if (move_counter == randMove)
		{
			randMove = RandomizeMove();
			smart = false;
			move_counter = 0;
			direction = SetMove(maxRow, maxCol, board);
		}
		else
			direction = SmartMove(maxRow, maxCol, pacman, board);
	}

	Movement(board);
	move_counter++;
	
}

Good_Ghost::Good_Ghost()
{
	smart = true;
	randMove = 20;
}

int Good_Ghost::RandomizeMove()
{
	return 19 + rand() % 2;
}
