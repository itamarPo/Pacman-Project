#pragma once
#include <iostream>
using namespace std;
extern bool Color;

class Position
{
public:
	Position();
	~Position();

	void SetRow(const int& x);
	void SetCol(const int& y);

	int getCol() const;
	int getRow() const;

private:
	int _row;
	int _col;
};

