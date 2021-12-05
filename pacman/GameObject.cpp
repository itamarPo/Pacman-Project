#include "GameObject.h"

void GameObject::SetPosition(const int row, const int col)
{
	_pos.SetRow(row);
	_pos.SetCol(col);
}

bool GameObject::CheckWall(const int& x, const int& y, GameBoard board[][SizeCol])
{
	if (board[x][y].getSignpiece() == WALL)
		return true;
	return false;
}

bool GameObject::CheckTunnel(const int& row, const int& col, GameBoard board[][SizeCol])
{
	if (col == 29)
	{
		if (row == 0 || row == 19)
			return true;
	}
	else if (row == 10)
		if (col == 0 || col == 59)
			return true;
	return false;
}

bool GameObject::Obstacle(const int& row, const int& col, GameBoard board[][SizeCol], Direction direction)
{
	switch (direction)
	{
	case Direction::Up : if (CheckWall(row - 1, col, board) || CheckTunnel(row - 1, col, board))
		return true;
		break;
	case Direction::Down: if (CheckWall(row + 1, col, board) || CheckTunnel(row + 1, col, board))
		return true;
		break;
	case Direction::Left: if (CheckWall(row, col - 1, board) || CheckTunnel(row, col - 1, board))
		return true;
		break;
	case Direction::Right: if (CheckWall(row, col + 1, board) || CheckTunnel(row, col + 1, board))
		return true;
		break;
	}
	return false;
}

Direction GameObject::SetMove(GameBoard board[][SizeCol])
{
	int random_move, row = _pos.getRow(), col = _pos.getCol();
	while (true)
	{
		random_move = rand() % 4;
		switch (random_move)
		{
		case (int)Direction::Up: if (!Obstacle(row, col, board, Direction::Up))
		{
			return Direction::Up;
		}
				 break;
		case (int)Direction::Down: if (!Obstacle(row, col, board, Direction::Down))
		{
			return Direction::Down;
		}
				   break;
		case (int)Direction::Left: if (!Obstacle(row, col, board, Direction::Left))
		{
			return Direction::Left;
		}
				   break;
		case (int)Direction::Right: if (!Obstacle(row, col, board, Direction::Right))
		{
			return Direction::Right;
		}
					break;
		default:
			break;
		}
	}


}

int GameObject::getRow()
{
	_pos.getRow();
}

int GameObject::getCol()
{
	return _pos.getCol();
}

