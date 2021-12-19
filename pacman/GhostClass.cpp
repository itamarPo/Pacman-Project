#include "GhostClass.h"


Ghost::Ghost()
{
	_pos.SetRow(0);
	_pos.SetCol(0);
	move_counter = 0;
	direction = Direction(rand() % 4);
	_startPos.SetRow(0);
	_startPos.SetCol(0);
}

Ghost::~Ghost()
{

}


void Ghost::SetPosition(const int row, const int col)
{
	_pos.SetRow(row);
	_pos.SetCol(col);
}



void Ghost::Print()const
{
	gotoxy(_pos.getRow(), _pos.getCol());
	if (Color)
	{
		cout << CYAN << "$" << RESET;
	}
	else
		cout << "$";

}


void Ghost::UpdateMove(const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board, Pacman & pacman)
{
	if (move_counter == 20 || Obstacle(_pos.getRow(), _pos.getCol(), maxRow, maxCol, board, direction))
	{
		direction = SetMove(maxRow, maxCol, board);
		move_counter = 0;
	}
	Movement(board);
	move_counter++;
}

/*
GhostDirection Ghost::SetMove(GameBoard board[][SizeCol])
{
	int random_move, row = _pos.getRow(), col = _pos.getCol(); 
	while(true)
	{
		random_move = rand() % 4;
		switch (random_move)
		{
		case Up_G: if (!Obstacle(row, col, board, Up_G))
		{
			return Up_G;
		}
				 break;
		case Down_G: if (!Obstacle(row, col, board, Down_G))
		{
			return Down_G;
		}
				 break;
		case Left_G: if (!Obstacle(row, col, board, Left_G))
		{
			return Left_G;
		}
				 break;
		case Right_G: if (!Obstacle(row, col, board, Right_G))
		{
			return Right_G;
		}
				  break;
		default:
			break;
		}
	}
	
	
}
*/
/*update the ghost position and prints the position of the older board piece it has overwritten*/
/*
void Ghost::Movement(GameBoard board[][SizeCol])
{
	int row = _pos.getRow(), col = _pos.getCol();

	switch (direction)
	{
	case Up_G: SetPosition(row - 1, col);
		board[row][col].printPiece(row, col);
		break;
	case Down_G: SetPosition(row + 1, col);
		board[row][col].printPiece(row, col);
		break;
	case Left_G: SetPosition(row, col - 1);
		board[row][col].printPiece(row, col);
		break;
	case Right_G: SetPosition(row, col + 1);
		board[row][col].printPiece(row, col);
		break;
	default: 
		break;
	}
}
*/

Direction Ghost::GetDirection()
{
	return direction;
}
/*
bool Ghost::Obstacle(const int& row, const int& col, GameBoard board[][SizeCol], GhostDirection direction) const
{
	switch (direction)
	{
	case Up_G: if (Game::CheckWall(row - 1, col, board) || Game::CheckTunnel(row - 1, col, board))
		return true;
		break;
	case Down_G: if (Game::CheckWall(row + 1, col, board) || Game::CheckTunnel(row+1, col, board))
		return true;
		break;
	case Left_G: if (Game::CheckWall(row, col - 1, board) || Game::CheckTunnel(row, col - 1, board))
		return true;
		break;
	case Right_G: if (Game::CheckWall(row, col + 1, board) || Game::CheckTunnel(row, col + 1, board))
		return true;
		break;
	}	
	return false;
}
*/