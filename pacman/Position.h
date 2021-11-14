#pragma once
#include <iostream>
using namespace std;

class Position
{
public:
	Position();
	~Position();

	void SetRow(const int& x);
	void SetCol(const int& y);

	int getCol();
	int getRow();

private:
	int _row;
	int _col;
};

