#pragma once
#include "GameBoard.h"
#include "GhostClass.h"
#include "Best_Ghost.h"
#include "Good_Ghost.h"
#include "PacmanClass.h"
#include "GameObject.h"
#include "Fruit.h"
#include <filesystem>
#include <string>
#include <fstream>
#include <typeinfo>

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
	vector<vector<GameBoard>> board; //levelofghost* 
	Pacman pacman;
	vector<Ghost*> ghosts;
	Position _legend;
	vector<string> GameFiles;
	Fruit fruit;
	int _numBread;
	int maxRow;
	int maxCol;
public:
	Game();
	~Game();
	void CheckImpact();
	void Start();
	void PrintBoard() const;
	void Menu();
	void PrintMenu() const;
	void Instructions(char& user_input);
	void ChooseGhostLevel(int& GhostLevel);
	void GameRun();
	bool IsGamePaused(char &pause);
	bool IsMoveValid(const char& ch);
	void ConsequencesOfMove(bool& is_ghost_turn);
	void PacmanCheck();
	void CheckIfPacmanAteFood();
	void PrintScoreAndLives()const;
	void GhostInitialize();
	void PrintLifeLost() const; 
	void turnColor();
	void CheckGhostFruitImpact();
	void getGameFiles(bool& filesFound);
	void checkFileNameFormat();
	void getBoardInformation(int fileIndex, int & GhostLevel);
	void ClearGame();
	void RegularGame(int & GhostLevel);
	void SpecificFileCycle(int & GhostLevel);
	void ClearLevel();
	void DecideChar(const int& row, const int& col, const char& ch, bool& legend_appear, int & GhostLevel);
	void EndGameMessage() const;
	void WinGameMessage() const;
	void WaitMessage()const;
};
