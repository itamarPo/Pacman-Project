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

void Pacman::setPacmanDirection(const char direction)
{
	_direction = direction;
}

void Pacman::setPacmanIfTunnel(const int row, const int col)
{
	_pos.SetRow(row);
	_pos.SetCol(col);
}

void Pacman::printPacman()
{
	gotoxy(_pos.getRow(),_pos.getCol());
	if (Color)
	{
		cout << YELLOW << "@" << RESET;
	}
	else
		cout << "@";
}

int Pacman::getPacmanRow() 
{
	return _pos.getRow();
}

int Pacman::getPacmanCol() 
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
	_pos.SetRow(StartRow);
	_pos.SetCol(StartCol);
}

char Pacman::getPacmanDirection() const
{
	return _direction;
}

bool Pacman::CheckIfPacmanHitWall(GameBoard board[][SizeCol])
{
	
	if (_direction == UP || _direction == UP - 32)
	{
		return Game::CheckWall(_pos.getRow() - 1, _pos.getCol(), board);
	}
	else if (_direction == DOWN || _direction == DOWN - 32)
	{
		return Game::CheckWall(_pos.getRow() + 1, _pos.getCol(), board);
	}
	else if (_direction == LEFT || _direction == LEFT - 32)
	{
		return Game::CheckWall(_pos.getRow(), _pos.getCol() - 1, board);
	}
	else if (_direction == RIGHT || _direction == RIGHT - 32)
	{
		return Game::CheckWall(_pos.getRow(), _pos.getCol() + 1, board);
	}
	else
		return false;
	
	
}
