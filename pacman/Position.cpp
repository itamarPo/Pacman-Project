#include "Position.h"

Position::Position()
{
	_row = 0;
	_col = 0;
}

Position::~Position()
{
}

void Position::SetRow(const int& row)
{
	_row = row;
}

void Position::SetCol(const int& col)
{
	_col = col;
}

int Position::getRow()
{
	return _row;
}

int Position::getCol()
{
	return _col;
}
