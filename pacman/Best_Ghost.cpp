#include "Best_Ghost.h"
/*needs to return Direction*/
void Best_Ghost::UpdateMove(const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board, Pacman& pacman)
{
	direction = SmartMove(maxRow, maxCol, pacman, board);
	Movement(board);
}
