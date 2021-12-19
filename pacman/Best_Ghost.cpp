#include "Best_Ghost.h"
/*needs to return Direction*/
void Best_Ghost::UpdateMove(const int& maxRow, const int& maxCol, vector<vector<GameBoard>> board, Pacman& pacman)
{
	bool visited[25][80];
	Qitem ghost(_pos, Direction::Stay);
	int i, j;
	for (i = 0 ; i < 25 ; i++)
		for(j = 0 ; j < 80 ; j++)
		{
			if (board[i][j].getSignpiece() == WALL)
				visited[i][j] = true;
		}
	queue<Qitem> q;
	q.push(ghost);
	bool IsFirst = true;
	Qitem p = q.front();
	while (!q.empty())
	{
		p = q.front();
		q.pop();

		// Destination found;
		if (p._pos.getRow() == pacman.getRow() && p._pos.getCol() == pacman.getCol())
			return p.getDirection();

		// moving up
		if ((p._pos.getCol() - 1 >= 0) && (visited[p._pos.getRow() - 1][p._pos.getCol()] == false))
		{
			if (IsFirst == true)
			{
				q.push(p._pos.getRow() - 1, p._pos.getCol(), Direction::Up); //assigning up
			}
			else
			{
				q.push(p._pos.getRow() - 1, p._pos.getCol(), p._direction));
			}
			visited[p._pos.getRow() - 1][p._pos.getCol()] = true;
		}

		// moving down
		if ((p._pos.getRow() + 1 < 5) && (visited[p._pos.getRow() + 1][p._pos.getCol()] == false))
		{
			if (IsFirst == true)
			{
				q.push(Qitem(p._pos.getRow() + 1, p._pos.getCol(), Direction::Down)); //assigning down
			}
			else
			{
				q.push(Qitem(p._pos.getRow() + 1, p._pos.getCol(), p._direction));
			}
			visited[p._pos.getRow() + 1][p._pos.getCol()] = true;
		}

		// moving left
		if ((p._pos.getCol() - 1 >= 0) && (visited[p._pos.getRow()][p._pos.getCol() - 1] == false))
		{
			if (IsFirst == true)
			{
				q.push(Qitem(p._pos.getRow(), p._pos.getCol() - 1, Direction::Left)); //assigning left
				IsFirst = false;
			}
			else
			{
				q.push(Qitem(p._pos.getRow(), p._pos.getCol() - 1, p._direction));
			}
			visited[p._pos.getRow()][p._pos.getCol() - 1] = true;
		}

		// moving right
		if ((p._pos.getCol() + 1 < 5) && (visited[p._pos.getRow() - 1][p._pos.getCol()] == false))
		{
			if (IsFirst == true)
			{
				q.push(Qitem(p._pos.getRow() - 1, p._pos.getCol(), Direction::Right)); //assigning right
				IsFirst = false;
			}
			else
			{
				q.push(Qitem(p._pos.getRow() - 1, p._pos.getCol(), p._direction));
			}
			visited[p._pos.getRow() - 1][p._pos.getCol()] = true;
		}
		if (IsFirst == true)
			IsFirst = false;
	}
}
