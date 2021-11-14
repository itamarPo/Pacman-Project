#pragma once
#include "GameBoard.h"
#include "GhostClass.h"
#include "PacmanClass.h"
class Ghost;
class Pacman;
/*note*/

class Game
{
private: 
	int _numBread;
public:
	Game();
	~Game();
	static bool checkWall(const int& x, const int& y, GameBoard board[][SizeCol]);
	static bool checkTunnel(const int& x, const int& y, GameBoard board[][SizeCol]);
	void checkImpact(Pacman& pacman,Ghost* ghosts, GameBoard board[][SizeCol]);
	char DecideChar(const int& row, const int& col);
	void GameCycle();
	void InitBoard(GameBoard board[][SizeCol]);
	void PrintBoard(GameBoard board[][SizeCol], Pacman& pacman, Ghost* ghosts) const;
	void Menu();
	void PrintMenu() const;
	void Instructions(char& user_input);
	void GameRun(Pacman& pacman, Ghost* ghosts, GameBoard board[][SizeCol]);
	bool IsGamePaused(char &pause);
	bool IsMoveValid(const char& ch);
	void ConsequencesOfMove(Pacman& pacman, Ghost* ghosts, GameBoard board[][SizeCol], char &direction);
	void PacmanCheck(Pacman& pacman, GameBoard board[][SizeCol], char& direction);
	void CheckIfPacmanAteFood(Pacman& pacman, GameBoard board[][SizeCol]);
	void PrintScoreAndLives(Pacman& pacman)const;
	void GhostInitialize(Ghost* ghosts);
	void PrintLifeLost(Pacman& pacman);
	//function that check whether or not both pacman an ghosts is going to hit a wall. if so, 
};
