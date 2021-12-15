#include "PacmanClass.h"


Pacman::Pacman(const int row, const int col, const int score, const int Lives, const char direction)
{
	_pos.SetRow(row);
	_pos.SetCol(col);
	_score = score;
	_remaininglives = Lives;
	_direction = direction;
}

Pacman::~Pacman()
{
}

void Pacman::setPacmanPosition()
{
	if (_direction == LEFT || _direction == (LEFT - 32))
		_pos.SetCol(_pos.getCol() - 1);
	else if (_direction == RIGHT || _direction == (RIGHT - 32))
		_pos.SetCol(_pos.getCol() + 1);
	else if (_direction == UP || _direction == (UP - 32))
		_pos.SetRow(_pos.getRow() - 1);
	else if (_direction == DOWN || _direction == (DOWN - 32))
		_pos.SetRow(_pos.getRow() + 1);
	else
		return;
	
	
}


void Pacman::setPacmanScore(int bonus)
{
	_score = _score + bonus;
}

void Pacman::setPacmanLives(int minus)
{
	_remaininglives = _remaininglives - minus;
}

void Pacman::setPacmanDirection(const char& direction)
{
	_direction = direction;
}

void Pacman::setPacmanIfTunnel(const int row, const int col)
{
	_pos.SetRow(row);
	_pos.SetCol(col);
}

void Pacman::printPacman() const
{
	gotoxy(_pos.getRow(),_pos.getCol());
	if (Color)
	{
		cout << YELLOW << "@" << RESET;
	}
	else
		cout << "@";
}

int Pacman::getPacmanRow() const 
{
	return _pos.getRow();
}

int Pacman::getPacmanCol() const
{
	return _pos.getCol();
}

int Pacman::getPacmanScore() const
{
	return _score;
}

int Pacman::getPacmanLives() const
{
	return _remaininglives;
}

void Pacman::ResetPos()
{
	_pos.SetRow(getStartRow());
	_pos.SetCol(getStartCol());
}

char Pacman::getPacmanDirection() const
{
	return _direction;
}

bool Pacman::CheckIfPacmanHitWall(const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board)
{
	
	if (_direction == UP || _direction == UP - 32)
	{
		return CheckWall(_pos.getRow() - 1, _pos.getCol(), maxRow, maxCol, board);
	}
	else if (_direction == DOWN || _direction == DOWN - 32)
	{
		return CheckWall(_pos.getRow() + 1, _pos.getCol(), maxRow, maxCol, board);
	}
	else if (_direction == LEFT || _direction == LEFT - 32)
	{
		return CheckWall(_pos.getRow(), _pos.getCol() - 1, maxRow, maxCol, board);
	}
	else if (_direction == RIGHT || _direction == RIGHT - 32)
	{
		return CheckWall(_pos.getRow(), _pos.getCol() + 1, maxRow, maxCol, board);
	}
	else
		return false;
}

bool Pacman::CheckTunnel(const int& maxRow,const int& maxCol, vector<vector<GameBoard>> board)
{
	if (_pos.getRow() == 0)
	{
		if (board[maxRow - 1][_pos.getCol()].getSignpiece() != WALL)
		{
			setPacmanIfTunnel(maxRow - 2, _pos.getCol());
			return true;
		}
		else
			return false;
	}
	else if (_pos.getRow() == (maxRow - 1))
	{
		if (board[0][_pos.getCol()].getSignpiece() != WALL)
		{
			setPacmanIfTunnel(1, _pos.getCol());
			return true;
		}
		else
			return false;
	}
	else if (_pos.getCol() == 0)
	{
		if (board[_pos.getRow()][maxCol - 1].getSignpiece() != WALL)
		{
			setPacmanIfTunnel(_pos.getRow(), maxCol - 2);
			return true;
		}
		else
			return false;
	}
	else if (_pos.getCol() == (maxCol - 1))
	{
		if (board[_pos.getRow()][0].getSignpiece() != WALL)
		{
			setPacmanIfTunnel(_pos.getRow(), 1);
			return true;
		}
		else
			return false;
	}
	else
		return false;
}