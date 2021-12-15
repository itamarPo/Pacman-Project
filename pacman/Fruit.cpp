#include "Fruit.h"

Fruit::Fruit()
{
	_scoreNum = 5 + rand() % 4;
	_appear = false;
	_moves = 0;
	_movesAppear = 0;
	_direction = (Direction)(rand() % 4);
}

void Fruit::setStartPos(const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board)
{
	int row=0, col=0;
	do
	{
		row = rand() % 20;
		col = rand() % 60;
	} while (CheckWall(row, col, maxRow, maxCol, board) || CheckTunnel(row, col, maxRow, maxCol, board)); // need to check if a fruit can be spawned on ghost or pacman
	_pos.SetRow(row);
	_pos.SetCol(col);
}



void Fruit::setScore()
{
	_scoreNum = 5 + rand() % 4;
}

void Fruit::setAppear()
{
	_appear = !_appear;
}

void Fruit::updateStatus(const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board)
{
	_moves++;
	if (_appear)
	{
		if (_moves == MovesDisappear)
		{
			_moves = 0;
			setAppear();
			setMovesAppear();
		}
		else
		{
			if (Obstacle(_pos.getRow(),_pos.getCol(),maxRow, maxCol, board, _direction))
			{
				_direction = SetMove(maxRow, maxCol, board);
			}
			Movement(board);
		}
		//This might be need to be changed:
		Print();
	}
	else
	{
		if (_moves == _movesAppear)
		{
			setAppear();
			setScore();
			_moves = 0;
			_direction = SetMove(maxRow, maxCol, board);
		}
		
	}
}

void Fruit::setMovesAppear()
{
	_movesAppear = 4 + rand() % 6;
}




bool Fruit::checkAppear() const
{
	return _appear;
}

void Fruit::Print() const
{
	gotoxy(_pos.getRow(), _pos.getCol());
	cout << _scoreNum;
}

/*
void Fruit::Movement(vector<vector<GameBoard>> board)
{
	int row = _pos.getRow(), col = _pos.getCol();

	switch (_direction)
	{
	case Direction::Up: SetPosition(row - 1, col);
		board[row][col].printPiece(row, col);
		break;
	case Direction::Down: SetPosition(row + 1, col);
		board[row][col].printPiece(row, col);
		break;
	case Direction::Left: SetPosition(row, col - 1);
		board[row][col].printPiece(row, col);
		break;
	case Direction::Right: SetPosition(row, col + 1);
		board[row][col].printPiece(row, col);
		break;
	default:
		break;
	}
}
*/