#pragma once
#include "GameBoard.h"
#include "GhostClass.h"
#include "PacmanClass.h"
#include "GameObject.h"
#include "Fruit.h"
#include <filesystem>
#include <string>
#include <fstream>

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
	void getGameFiles();
	void checkFileNameFormat();
	void getBoardInformation(int fileIndex);
	void ClearGame();
	void RegularGame();
	void SpecificFileCycle();
	void ClearLevel();
	void DecideChar(const int& row, const int& col, const char& ch, bool& legend_appear, Ghost& ghost);
	void EndGameMessage() const;
	void WinGameMessage() const;
	void WaitMessage()const;
};
