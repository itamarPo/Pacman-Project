#include "Game.h"


Game::Game()
{
	_numBread = 0;
	maxRow = 0;
	maxCol = 0;
	status = CmdArg::Simple;
}

Game::~Game()
{
}


void Game::CheckImpact()
{
	int i;
	for (i = 0; i < ghosts.size(); i++)
	{
		if (pacman.getRow() == ghosts[i]->getRow()) // check if ghosts[i] ate pacman
			if (pacman.getCol() == ghosts[i]->getCol())
			{
				pacman.setPacmanLives();
				PrintLifeLost();
				GhostInitialize();
				pacman.ResetPos();
				if (pacman.getPacmanLives() == 0)
					return;
				PrintBoard();
				return;
			}
	}
	return;
}


void Game::Start(int& argc, char** argv)
{
	bool filesFound = true;
	getGameFiles(filesFound);
	if (!filesFound)
		return;
	getCommandStatus(argc, argv);
	if(status == CmdArg::Simple || status == CmdArg::Save)
		Menu();
	else
	{
		GameRunLoadSilent();
	}
	
}

void Game::getCommandStatus(int& argc, char** argv)
{
	int i;
	for (i = 1; i < argc; i++)
	{
		if (i == 1)
		{
			if (!strcmp(argv[i], "-save"))
			{
				status = CmdArg::Save;
				cout << "save" << endl;
				Sleep(2000);
				return;
			}
			else if (strcmp(argv[i], "-load"))
			{
				status = CmdArg::Simple;
				return;
			}
			else
			{
				status = CmdArg::Load;
			}
		}
		if (i == 2)
		{
			if (!strcmp(argv[i], "[-silent]"))
				status = CmdArg::Silent;
		}
	}


}


void Game::PrintBoard() const
{
	int row, col;
	for(row=0; row <maxRow; row++)
		for (col = 0; col < maxCol; col++)
			board[row][col].printPiece(row,col);
	for (auto i = 0; i < ghosts.size(); i++)
		ghosts[i]->Print();
	pacman.printPacman();
	PrintScoreAndLives();
	
}

void Game::Menu()
{
	char user_input;
	int GhostLevel = 1;
	PrintMenu();
	Color = false;
	
	do
	{
		user_input = _getch();
		switch (user_input)
		{
		case '1':
			RegularGame(GhostLevel);
			break;
		case '2':
			SpecificFileCycle(GhostLevel);
			break;
		case '3':
			ChooseGhostLevel(GhostLevel);
			break;
		case '7': turnColor();
			break;
		case '8': 
			Instructions(user_input);
			break;
		case '9': clrscr();
			cout << "Good Bye" << endl;
			GameFiles.clear();
			return;
		default: clrscr();
			cout << "Incorrect input";
			Sleep(1400);
			break;
		}
		PrintMenu();	
	} while (true);

}

void Game::PrintMenu() const
{
	clrscr();
	cout << "Welcome To Pacman" << endl;
	cout << "(1) Start a new regular game" << endl;
	cout << "(2) Start a specific level of your choice" << endl;
	cout << "(3) Select a difficulty level for ghosts " << endl;
	cout << "(7) Turn on/off colors" << endl;
	cout << "(8) Present instructions and keys" << endl;
	cout << "(9) EXIT" << endl;
}


void Game::Instructions(char& user_input)
{
	clrscr();
	cout << "Welcome To Pacman" << endl;
	cout << "Youre the pacman (@ in the game), your goal is to eat all the breadcumbs on the board" << endl;
	cout << "while avoiding the ghosts ($ in the game)." << endl;
	cout << "As pacman you start with 3 lives." << endl;
	cout << "If you get in contact with a ghost you will lose a life. if you lose 3 lives you also lose the game." << endl;
	cout << "When you lose a life the game will restart and you will be back to your intial position." << endl;
	cout << "But your score will be saved as will your breadcrumbs eating progress." << endl;
	cout << endl;
	cout << "Keys:" << endl;
	cout << "Move Left: A" << endl;
	cout << "Move Right: D" << endl;
	cout << "Move Up: W" << endl;
	cout << "Move Down: X" << endl;
	cout << "Stay: S" << endl;
	cout << "Pause: ESC" << endl;
	cout << endl;
	cout << "To return to the menu press ESC.";
	do
	{
		user_input = _getch();
	} while (user_input != 27);
}

void Game::ChooseGhostLevel(int& GhostLevel)
{
	clrscr();
	cout << "Choose the ghost's level: " << endl;
	cout << "Press 1. for Novice ghosts" << endl;
	cout << "Press 2. for Good ghosts" << endl;
	cout << "Press 3. for Best ghosts" << endl;
	cin >> GhostLevel;
	while (0 >= GhostLevel || GhostLevel > 3)
	{
		cout << "Incorrect Input, please enter a number between 1 to 3 to choose your level of ghosts";
		cin >> GhostLevel;
	}
}


void Game::getStepsResFileNames(string& steps, string& res, int& fileIndex) 
{
	steps = GameFiles[fileIndex];
	steps.resize(steps.size() - 6);
	res = steps;
	steps += "steps";
	res += "result";
}

void Game::LoadConcequence()
{
}

void Game::GameRun(int& fileIndex)
{
	string stepsFile, resultFile;
	//stepsFile.resize(stepsFile.size() - 6);
	//resultFile = stepsFile;
	//stepsFile += "steps";
	//resultFile += "result";
	ofstream resFile, stepFile;
	getStepsResFileNames(stepsFile, resultFile, fileIndex);
	// maybe add if to create files.
	resFile.open(resultFile);
	stepFile.open(stepsFile);
		if (!resFile) { // file couldn't be opened
			cout << "Error: file could not be opened" << endl;
			exit(1);
		}

	clrscr();
	PrintBoard();
	char tmp_move = 0;
	bool is_ghost_turn = false;
	while (pacman.getPacmanLives() != 0 && _numBread != 0)
	{
		if (IsGamePaused(tmp_move) == true) //waits until user select ESC again to continue game.
		{
			clrscr();
			PrintBoard();
		}
		if (_kbhit()) //if the user pressed any key
		{
			tmp_move = getKey(); //get char entered by user.
			if (IsMoveValid(tmp_move) == true) //check if its a vaild move for pacman.
			{
				if (tmp_move == PAUSE)
					continue;
				else
					pacman.setPacmanDirection(tmp_move);
			}
		}
		
		ConsequencesOfMove(is_ghost_turn, stepFile);
		if (pacman.getPacmanLives() != 0)
			PrintScoreAndLives();
		Sleep(GameSpeed);
	}
	if(status == CmdArg::Save)
		resFile << pacman.getMoves();
	resFile.close();
	stepFile.close();
	clrscr();
	gotoxy(10, 20);
	//close
}

void Game::GameRunLoadSilent()
{
	int size = GameFiles.size(), i;
	int ghostLevel = 1, moves=0, tmp_pacman_move;
	for (i = 0; i < size; i++)
	{
		getBoardInformation(i, ghostLevel);
		moves = ReadStepsFromFiles(i);
		if (status == CmdArg::Silent)
		{
			if (moves != pacman.getMoves())
			{
				clrscr();
				cout << "Test Failed! 1";
				ClearLevel();
				return;
			}
			else
			{
				clrscr();
				cout << "Test for level: " << i << "Passed!";
				//Sleep(200);
			}
			///*if(i == size - 1)
			//{
			//clrscr();
			//	if(moves != pacman.getMoves())
			//	{
			//		
			//		cout << "Test failed! 1";
			//	}
			//	else
			//	{
			//		cout << "Test Passed!";
			//	}
			//}*/
			//else
			//{
			//	if (moves != pacman.getMoves())
			//	{
			//		clrscr();
			//		cout << "Test failed! 2";
			//		ClearLevel();
			//		return;
			//	}
			//		
			//}
		}
	
		tmp_pacman_move = pacman.getMoves();
		ClearLevel();
		if (pacman.getPacmanLives() == 0)
		{
			clrscr();
			if (status == CmdArg::Silent)
			{
				if (moves == tmp_pacman_move)
				{
					cout << "Test Passed!";
				}
				else
					cout << "Test failed! 3";
			}
			return;
		}
		
	}
	
	
}

int Game::ReadStepsFromFiles(int& fileIndex)
{
	string steps, res;
	int numMoves;
	getStepsResFileNames(steps, res, fileIndex);
	ifstream stepsFile, resFile;
	stepsFile.open(steps); resFile.open(res);
	if (stepsFile.fail())
	{
		stepsFile.close();
		resFile.close();
		return 0;
	}
	string line;
	int counter = 1;
	clrscr();
	if(status == CmdArg::Load)
		PrintBoard();
	getline(stepsFile, line);
	while (!stepsFile.eof())
	{
		switch (line[0])
		{
		case 'P':
			if(status == CmdArg::Load)
				Sleep(100);
			CheckImpact();
			board[pacman.getRow()][pacman.getCol()].printPiece(pacman.getRow(), pacman.getCol()); // prints gameboard over old pcaman location
			pacman.SetLoadDirection((Direction)((int)line[2]-'0'));
			PacmanLoadCheck();
			pacman.updateMoves();
			CheckImpact();
			break;
		case 'G':
			ghosts[(int)line[1]-'0']->SetLoadDirection((Direction)((int)line[3] - '0'));
			ghosts[(int)line[1]-'0']->Movement(board);
			//ghosts[(int)line[1]-'0']->Print();
			break;
		case 'F': FruitLoad(line);
			break;
		default:
			break;
		}
		for (int i = 0; i < ghosts.size(); i++)
			if (status == CmdArg::Load)
				ghosts[i]->Print();
		getline(stepsFile, line);
		counter++;
		if (status == CmdArg::Load)
			PrintScoreAndLives();
		///general check of board situation
	}
	resFile >> numMoves;
	
	resFile.close();
	stepsFile.close();
	return numMoves;


}

void Game::PacmanLoadCheck()
{
	if(!pacman.CheckTunnel(maxRow, maxCol, board))
		pacman.setPacmanPosition();
	CheckIfPacmanAteFood();
	pacman.printPacman();
}

void Game::FruitLoad(string& line)
{

	switch(line[1])
	{
	case '0':
		fruit.setAppear();
		fruit.SetLoadDirection((Direction)((int)line[3]-'0'));
		readFruitPos(line, 5, 0);
		fruit.Print();
		break;
	case '1':
		fruit.SetLoadDirection((Direction)((int)line[3]-'0'));
		fruit.Movement(board);
		fruit.Print();
		break;
	case '2':
		board[fruit.getRow()][fruit.getCol()].printPiece(fruit.getRow(), fruit.getCol());
		fruit.setAppear();
		readFruitPos(line, 3, 2);
		break;
	default:
		break;
	}
}

void Game::readFruitPos(string& line, int index, int fruitStatus)
{
	int row, col;
	row = (int)line[index]-'0';
	if (line[++index] != ' ')
	{
		row *= 10; 
		row += (int)line[index]-'0';
		index += 2;
	}
	else
		index++;

	col = (int)line[index++]-'0';
	if(index < line.size())
	{
		col *= 10;
		col += (int)line[index]-'0';
	}
	if (fruitStatus == 0)
		fruit.SetPosition(row, col);
	else
	{
		fruit.SetPosition(0, 0);
		//board[row][col].printPiece(row,col);
	}

}

bool Game::IsGamePaused(char& pause)
{
	if (pause == PAUSE)
	{
		clrscr();
		gotoxy(0, 0);
		cout << "Game is paused. please press ESC to continue.";
		char tmp;
		while (pause == PAUSE)
		{
			if (_kbhit())
			{
				tmp = getKey();
				if (tmp == PAUSE)
					pause = 0;
			}
			Sleep(GameSpeed*2);
		}
		return true;
	}
	return false;
}

bool Game::IsMoveValid(const char& ch)
{
	if (ch == STAY || ch == (STAYS))
		return true;
	else if (ch == LEFT || ch == (LEFTA))
		return true;
	else if (ch == RIGHT || ch == (RIGHTD))
		return true;
	else if (ch == UP || ch == (UPW))
		return true;
	else if (ch == DOWN || ch == (DOWNX))
		return true;
	else if (ch == PAUSE)
		return true;
	else
		return false;
	
}

/*this function checks if pacman ate, hit a ghost, or got into a tunnel*/

void Game::ConsequencesOfMove(bool& is_ghost_turn, ofstream& stepFile)
{
	int pacRow = pacman.getRow(), pacCol = pacman.getCol(),i; 
	bool IsSave = false;
	board[pacRow][pacCol].printPiece(pacRow, pacCol);
	PacmanCheck();
	if(status == CmdArg::Save)
	{
		IsSave = true;
		stepFile << "P " << (int)pacman.getDirection() << endl;
	}
	CheckImpact();

	if (pacman.getPacmanLives() == 0)
		return;
	if (is_ghost_turn == true)// makes sure that ghosts move once in two p5acman moves.
	{
		bool fruitappear = fruit.checkAppear();
		fruit.updateStatus(maxRow, maxCol, board,stepFile, IsSave);
		for (i = 0; i < ghosts.size(); i++) // updates the ghost's movements (if needed it changes direction)
			ghosts[i]->UpdateMove(maxRow, maxCol, board, pacman);
		is_ghost_turn = false;
		CheckGhostFruitImpact();
		for (i = 0; i < ghosts.size(); i++)
		{

			ghosts[i]->Print();
			if (IsSave)
			{
				stepFile << 'G' << i << ' ' << (int)ghosts[i]->getDirection() << endl;
			}
		}
	}
	else
		is_ghost_turn = true;
	
	CheckImpact();
	CheckIfPacmanAteFood();
}

void Game::PacmanCheck()
{
	if (pacman.CheckIfPacmanHitWall(maxRow, maxCol, board) == true) 
	{
		if(pacman.CheckTunnel(maxRow, maxCol, board) != true) // if tunnel, move pacman to the other side
		pacman.setPacmanDirection(STAY); // if wall, dont move pacman and put stay as direction
	}
	else
		pacman.setPacmanPosition(); // set new position due to direction
	CheckIfPacmanAteFood();
	pacman.printPacman(); // print pacman at his new position
	pacman.updateMoves();
}

void Game::CheckIfPacmanAteFood()
{
	if (board[pacman.getRow()][pacman.getCol()].getSignpiece() == FOOD)
	{
		pacman.setPacmanScore();
		_numBread--;
		board[pacman.getRow()][pacman.getCol()].setGamePiece(Space);
	}
	if (fruit.checkAppear()) 
	{
		if (pacman.getRow() == fruit.getRow())
			if (pacman.getCol() == fruit.getCol())
			{
				pacman.setPacmanScore(fruit.getScore());
				fruit.Eaten();
			}
	}
}

void Game::PrintScoreAndLives() const
{
	int i,j;
	gotoxy(_legend.getRow(), _legend.getCol());
	string score = "Your score: ";
	string legend[3];
	for (i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			legend[i] = "Your score: " + to_string(pacman.getPacmanScore());
			break;
		case 1:
			legend[i] = "Remaining lives: " + to_string(pacman.getPacmanLives());
			break;
		}
		cout << legend[i];
		for (j = legend[i].size(); j < 20; j++)
		{
			cout << " ";
		}
		cout << endl;
		gotoxy(_legend.getRow()+(i+1), _legend.getCol());
	}
}


void Game::GhostInitialize()
{
	int i;
	for (i = 0; i < ghosts.size(); i++)
	{
		ghosts[i]->SetPosition(ghosts[i]->getStartRow(),ghosts[i]->getStartCol());
	}
}


void Game::PrintLifeLost() const
{
	clrscr();
	
	if (pacman.getPacmanLives() > 0)
	{
		gotoxy(10, 30);
		cout << "The Pacman was eaten by a ghost." << endl;
		gotoxy(11, 30);
		cout << "You have " << pacman.getPacmanLives() << " lives reamining";
		if(status != CmdArg::Silent)
			Sleep(GameSpeed * 8);
	}
	clrscr();
}



void Game::turnColor()
{
	clrscr();
	gotoxy(0, 0);
	if (!Color)
		cout << "Colors are turned On";
	else
		cout << "Colors are turend Off";
	Color = !Color;
	Sleep(GameSpeed * 2);
	clrscr();
}


void Game::CheckGhostFruitImpact()
{
	int i;
	for (i = 0; i < ghosts.size(); i++)
	{
		if(fruit.checkAppear())
			if (fruit.getRow() == ghosts[i]->getRow())
				if (fruit.getCol() == ghosts[i]->getCol())
				{
					fruit.Eaten();
					return;
				}
	}
}

void Game::getGameFiles(bool& filesFound)
{
	string path = "./";
	for (const auto& file : directory_iterator(path))
	{
		GameFiles.push_back(file.path().filename().string()); // Add file's name to vector.
		checkFileNameFormat(); //check if file format is ok
	}
	if (GameFiles.size() == 0)
	{
		cout << "No files were found, Good bye.";
		filesFound = false;
	}
}

void Game::checkFileNameFormat()
{
	string last = GameFiles[GameFiles.size() - 1];
	int namesize = last.size(), i, j = SizeToCheck;
	for (i = 0; i < SizeToCheck; i++, namesize--, j--)
	{
		if ((last[i] != filenamestart[i]) || (last[namesize - 1] != filenamefinish[j]))
		{
			GameFiles.pop_back();
			return;
		}
	}
}



void Game::RegularGame(int & GhostLevel)
{
	int size = GameFiles.size(), i,j,maxRow = 0, maxCol = 0;
	for (i = 0 ; i < size ; i++)
	{
		getBoardInformation(i, GhostLevel);
		GameRun(i);
		if (pacman.getPacmanLives() == 0)
		{
			EndGameMessage();
			ClearGame();
			return;
		}
		else
		{
			if (i != size - 1) //don't print or clear board after last level
			{
				ClearLevel();
				clrscr();
				gotoxy(0, 0);
				cout << "Level Cleared. Next Level in: " << endl;
				for (j = 3; j > 0; j--)
				{
					gotoxy(1, 0);
					cout << j;
					Sleep(1000);
				}
			}
		}
	}
	WinGameMessage();
	ClearGame();
}

void Game::SpecificFileCycle(int & GhostLevel)
{
	string file_name;
	int fileIndex;
	cout << "Please enter the file's name you wish to play" << endl;
	cin >> file_name;

	if (binary_search(GameFiles.begin(), GameFiles.end(), file_name))
	{
		fileIndex = lower_bound(GameFiles.begin(), GameFiles.end(), file_name)-GameFiles.begin();
		getBoardInformation(fileIndex, GhostLevel);
		GameRun(fileIndex);
		if (pacman.getPacmanLives() == 0)
			EndGameMessage();
		else
			WinGameMessage();
		ClearGame();
	}
	else
	{
		cout << "File was not found" << endl;
		Sleep(2000);
		return;
	}

}

void Game::ClearLevel()
{
	int i;
	for (i = 0; i < board.size() - 1; i++)
	{
		board[i].clear();
	}
	board.clear();
	ghosts.clear();
	if (fruit.checkAppear())
		fruit.setAppear();	
	_numBread = 0;
	maxRow = 0;
	maxCol = 0;
	pacman.SetNumMoves();
}

void Game::DecideChar(const int& row, const int& col, const char& ch, bool& legend_appear, int & GhostLevel)
{
	if (legend_appear)
	{
		if (_legend.getRow() <= row && row <= _legend.getRow() + 2)
		{
			if (_legend.getCol() <= col && col <= _legend.getCol() + 19)
			{
				board[row][col].setGamePiece(WALL);
				return;
			}
		}
	}
	switch (ch)
	{
	case Pacman_sign: pacman.setStartPosition(row, col);
		board[row][col].setGamePiece(Space);
		break;
	case Ghost_sign:
		if(GhostLevel == 1) // novice difficulty
		ghosts.push_back(new Ghost);
		else if(GhostLevel == 2) // interdimate difficulty
		ghosts.push_back(new Good_Ghost); 
		else // hardest difficulty
		ghosts.push_back(new Best_Ghost);
		ghosts[ghosts.size() - 1]->setStartPosition(row, col);
		board[row][col].setGamePiece(FOOD);
		_numBread++;
		break;
	case Legend: legend_appear = true;
		_legend.SetCol(col);
		_legend.SetRow(row);
		board[row][col].setGamePiece(WALL);
		break;
	case Space: 
		board[row][col].setGamePiece(FOOD);
		_numBread++;
		break;
	default: board[row][col].setGamePiece(ch);
	}
}

void Game::EndGameMessage() const
{
	clrscr();
	cout << "Game Over!";
	WaitMessage();
}

void Game::WinGameMessage() const
{
	clrscr();
	cout << "Congragulation you Won!";
	WaitMessage();
}

void Game::WaitMessage() const
{
	char flush;
	Sleep(GameOverWon);
	clrscr();
	cout << "Press any key to return to the menu";
	while (!_kbhit());
	flush = _getch();
	clrscr();
}


void Game::getBoardInformation(int fileIndex, int& GhostLevel)
{
	ifstream File;
	vector<GameBoard> boardLine;
	GameBoard boardCol;
	if (board.empty() && ghosts.empty())
	{
		board.push_back(boardLine);
	}
	bool legend_appear = false;
	int colCounter = 0;
	File.open(GameFiles[fileIndex]);
	if (!File)
	{
		cout << "Error getting file";
		return;
	}
	char ch;
	File.get(ch);
	
	while(!File.eof())
	{
		if (ch != '\n')
		{
			board[maxRow].push_back(boardCol);
			DecideChar(maxRow, colCounter, ch, legend_appear, GhostLevel);
			colCounter++;
			if (maxRow == 0)
			{
				maxCol++;
			}
		}
		else
		{
			board.push_back(boardLine);
			maxRow++;
			colCounter = 0;
		}
		File.get(ch);
	}
	maxRow++;
	File.close();
}

void Game::ClearGame()
{
	ClearLevel();
	pacman.resetPacmanScore(StartScore);
	pacman.resetPacmanLives(StartLives);
	pacman.setPacmanDirection(STAY);
}
 