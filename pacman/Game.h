#pragma once
#include "GameBoard.h"
#include "GhostClass.h"
#include "PacmanClass.h"
#include "GameObject.h"
#include "Fruit.h"
#include <filesystem>
#include <string>
#include <vector>
#include <fstream>
class Ghost;
class Pacman;
const int GameSpeed = 200;
const int GameOverWon = 3000;
extern bool Color;
using std::filesystem::directory_iterator;
const char filenamestart[] = "pacman_";
const char filenamefinish[] = ".screen";
const char Legend = '&';
const char EmptyPos = '%';
const char Space = ' ';
const int SizeToCheck = 6;

class Game
{
private: 
	vector<vector<GameBoard>> board;
	Pacman pacman;
	vector<Ghost> ghosts;
	Position _legend;
	vector<string> GameFiles;
	int _numBread;
public:
	Game();
	~Game();
	/*static bool CheckWall(const int& x, const int& y, GameBoard board[][SizeCol]);
	static bool CheckTunnel(const int& x, const int& y, GameBoard board[][SizeCol]);*/
	/*void CheckImpact(Pacman& pacman,Ghost* ghosts, GameBoard board[][SizeCol]);*/
	void Start();
	void GameCycle();
	void InitBoard(GameBoard board[][SizeCol]);
	void PrintBoard(GameBoard board[][SizeCol], Pacman& pacman, Ghost* ghosts) const;
	void Menu();
	void PrintMenu() const;
	void Instructions(char& user_input);
	void GameRun(Pacman& pacman, Ghost* ghosts, GameBoard board[][SizeCol]);
	bool IsGamePaused(char &pause);
	bool IsMoveValid(const char& ch);
	void ConsequencesOfMove(Pacman& pacman, Ghost* ghosts, GameBoard board[][SizeCol], bool& is_ghost_turn);
	void PacmanCheck(Pacman& pacman, GameBoard board[][SizeCol]);
	void CheckIfPacmanAteFood(Pacman& pacman, GameBoard board[][SizeCol]);
	void PrintScoreAndLives(Pacman& pacman)const;
	void GhostInitialize(Ghost* ghosts);
	void PrintLifeLost(Pacman& pacman); 
	void CheckTunnel(Pacman& pacman, GameBoard[][SizeCol]);
	void turnColor();
	void checkImpact(Ghost* ghosts, Fruit& frut, GameBoard[][SizeCol]);
	void getGameFiles();
	void checkFileNameFormat();
	void getBoardInformation(int fileIndex, int& maxRow, int& maxCol);
	void clearGame();
	void createLegendRectangle();
	void SpecificFileCycle();
	void DecideChar(const int& row, const int& col, const char& ch, bool& legend_appear);
};
