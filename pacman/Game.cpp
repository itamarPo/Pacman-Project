#include "Game.h"


Game::Game()
{
	_numBread = 0;
}

Game::~Game()
{
}

/*
bool Game::CheckWall(const int& x,const int& y, GameBoard board[][SizeCol])
{
	if (board[x][y].getSignpiece() == WALL)
		return true; 
	return false;
}

bool Game::CheckTunnel(const int& row, const int& col, GameBoard board[][SizeCol])
{
	if (col == 29)
	{
		if (row == 0 || row == 19)
			return true;
	}
	else if (row == 10)
		if (col == 0 || col == 59)
			return true;
	return false;
}*/
/*
void Game::CheckImpact(Pacman& pacman, Ghost* ghosts, GameBoard board[][SizeCol])
{
	int i;
	for (i = 0; i < 2; i++)
	{
		if (pacman.getPacmanRow() == ghosts[i].getGhostRow())
			if (pacman.getPacmanCol() == ghosts[i].getGhostCol())
			{
				pacman.setPacmanLives();
				PrintLifeLost(pacman);
				GhostInitialize(ghosts);
				pacman.ResetPos();
				if (pacman.getPacmanLives() == 0)
					return;
				PrintBoard(board, pacman, ghosts);
				return;
			}
	}
	return;
}
*/

void Game::Start()
{
	getGameFiles();
	Menu();
}

void Game::GameCycle()
{
	Ghost ghosts[2]; 
	//GhostInitialize(ghosts);
	Pacman pac;
	GameBoard board[SizeRow][SizeCol]; 
	InitBoard(board);
	//PrintBoard(board, pac, ghosts);
	//GameRun(pac, ghosts, board);


	
}

void Game::InitBoard(GameBoard board[][SizeCol])
{
	ifstream File;
	File.open("pacmanboard.txt");
	if (!File)
	{
		cout << "Error opening file!";
		exit(1);
	}
	int row, col;
	char sign;
	for (row = 0; row < SizeRow; row++)
		for (col = 0; col <= SizeCol; col++)
		{
			sign = File.get();
			if (sign != '\n')
			{
				if (!(row == StartRow && col == StartCol))
				{
					if (sign == '*')
					{
						_numBread++;
						sign = FOOD;
					}
				}
				else
					sign = ' ';
				board[row][col].setGamePiece(sign);
			}
		}
	File.close();
}

void Game::PrintBoard(int& maxRow, int& maxCol) const
{
	int row, col;
	for(row=0; row <maxRow; row++)
		for (col = 0; col < maxCol; col++)
			board[row][col].printPiece(row,col);
	for (auto i = 0; i < ghosts.size(); i++)
		ghosts[i].Print();
	pacman.printPacman();
	PrintScoreAndLives();
	
}

void Game::Menu()
{
	char user_input;
	PrintMenu();
	Color = false;
	
	do
	{
		user_input = _getch();
		switch (user_input)
		{
		case '1':
			RegularGame();
			break;
		case '2':
			SpecificFileCycle();
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

void Game::GameRun(int& maxRow, int& maxCol)
{
	PrintBoard(maxRow, maxCol);
//	char flush;
//	char tmp_move = 0;
//	bool is_ghost_turn = false;
//	while (pacman.getPacmanLives() != 0 && _numBread != 0)//or pacman earned max points
//	{
//		if (IsGamePaused(tmp_move) == true) //waits until user select ESC again to continue game.
//		{
//			clrscr();
//			PrintBoard(maxRow, maxCol);
//		}
//		if (_kbhit()) //if the user pressed any key
//		{
//			tmp_move = getKey(); //get char entered by user.
//			if (IsMoveValid(tmp_move) == true) //check if its a vaild move for pacman.
//			{
//				if (tmp_move == PAUSE)
//					continue;
//				else
//					pacman.setPacmanDirection(tmp_move);
//			}
//		}
		
//		ConsequencesOfMove(pacman, ghosts, board, is_ghost_turn);
//		if (pacman.getPacmanLives() != 0)
//			PrintScoreAndLives(pacman);
//		Sleep(GameSpeed);
//	}
//	clrscr();
//	gotoxy(10, 20);
//	/*
//	if (pacman.getPacmanLives() == 0)
//		cout << "Game Over!";
//	else
//		cout << "Congratulations, you won!!";
//	Sleep(GameOverWon);
//	clrscr();
//	cout << "Press any key to return to the menu";
//	while (!_kbhit());
//	flush = _getch();
//	clrscr();
//	*/
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
/*
void Game::ConsequencesOfMove(Pacman& pacman, Ghost* ghosts, GameBoard board[][SizeCol], bool& is_ghost_turn)
{
	int pacRow = pacman.getPacmanRow(), pacCol = pacman.getPacmanCol(); 
	board[pacRow][pacCol].printPiece(pacRow, pacCol);
	PacmanCheck(pacman, board);
	CheckImpact(pacman, ghosts, board);
	if (pacman.getPacmanLives() == 0)
		return;
	if (is_ghost_turn == true)// makes sure that ghosts move once in two pacman moves.
	{
		ghosts[0].UpdateMove(board); // updates the ghost's movements (if needed it changed direction)
		ghosts[1].UpdateMove(board);
		is_ghost_turn = false;
	}
	else
		is_ghost_turn = true;
	ghosts[0].Print();
	ghosts[1].Print();
	CheckImpact(pacman, ghosts, board);
	
}

void Game::PacmanCheck(Pacman& pacman, )
{
	if (pacman.CheckIfPacmanHitWall(board) == true)
	{
		pacman.setPacmanDirection(STAY);
	}
	pacman.setPacmanPosition();
	//CheckIfPacmanAteFood(pacman, board);
	CheckTunnel(pacman, board);
	pacman.printPacman();
	CheckIfPacmanAteFood(pacman, board);
}

void Game::CheckIfPacmanAteFood(Pacman& pacman, GameBoard board[][SizeCol])
{
	if (board[pacman.getPacmanRow()][pacman.getPacmanCol()].getSignpiece() == FOOD)
	{
		pacman.setPacmanScore();
		_numBread--;
		board[pacman.getPacmanRow()][pacman.getPacmanCol()].setGamePiece(' ');
	}
}*/

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

/*
void Game::GhostInitialize(Ghost* ghosts)
{
	int i;
	for (i = 0; i < 2; i++)
	{
		ghosts[i].SetPosition(StartGhostRow + i * 10, StartGhostCol);
	}
}*/

/*
void Game::PrintLifeLost(Pacman& pacman)
{
	clrscr();
	
	if (pacman.getPacmanLives() > 0)
	{
		gotoxy(10, 30);
		cout << "The Pacman was eaten by a ghost." << endl;
		gotoxy(11, 30);
		cout << "You have " << pacman.getPacmanLives() << " lives reamining";
		Sleep(GameSpeed * 8);
	}
	clrscr();
}
*/

/*
void Game::CheckTunnel(Pacman& pacman, GameBoard[][SizeCol])
{
	int pacRow = pacman.getPacmanRow(), pacCol = pacman.getPacmanCol();
	if (pacRow == 10)
	{
		if (pacCol == 0)
		{
			pacman.setPacmanIfTunnel(pacRow, 58);
			return;
		}
		if (pacCol == 59)
		{
			pacman.setPacmanIfTunnel(pacRow, 1);
			return;
		}
	}
	if (pacCol == 29)
	{
		if (pacRow == 0)
		{
			pacman.setPacmanIfTunnel(18, pacCol);
			return;
		}
		if (pacRow == 19)
		{
			pacman.setPacmanIfTunnel(1, pacCol);
			return;
		}
	}
	return;
}
*/
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

/*
void Game::checkImpact(Ghost* ghosts, Fruit& fruit, GameBoard[][SizeCol])
{
	int i;
	for (i = 0; i < 2; i++)
	{
		if (fruit.getRow() == ghosts[i].getGhostRow())
			if (fruit.getCol() == ghosts[i].getGhostCol())
			{
				fruit.setAppear();
				return;
			}
	}
	return;
}
*/
void Game::getGameFiles()
{
	string path = "./";
	for (const auto& file : directory_iterator(path))
	{
		GameFiles.push_back(file.path().filename().string()); // Add file's name to vector.
		checkFileNameFormat(); //check if file format is ok
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



void Game::RegularGame()
{
	int size = GameFiles.size(), i,maxRow = 0, maxCol = 0;
	for (i = 0 ; i < size ; i++)
	{
		getBoardInformation(i, maxRow, maxCol);
		//gamerun
		if (pacman.getPacmanLives() == 0)
		{
			ClearGame();
			return;
		}
		else
			ClearLevel();
	}
}

void Game::SpecificFileCycle()
{
	string file_name;
	int fileIndex, maxRow = 0, maxCol = 0;
	cout << "Please enter the file's name you wish to play" << endl;
	cin >> file_name;

	if (binary_search(GameFiles.begin(), GameFiles.end(), file_name))
	{
		fileIndex = lower_bound(GameFiles.begin(), GameFiles.end(), file_name)-GameFiles.begin();
		getBoardInformation(fileIndex, maxRow, maxCol);
		GameRun(maxRow, maxCol); //tomorrow
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
	for (int i = 0; i < board.size() - 1; i++)
	{
		board[i].clear();
	}
	board.clear();
	ghosts.clear();
	_numBread = 0;
}

void Game::DecideChar(const int& row, const int& col, const char& ch, bool& legend_appear, Ghost& ghost)
{
	
	
	if (legend_appear)
	{
		if (_legend.getRow() < row && row <= _legend.getRow() + 2)
		{
			if (_legend.getCol() < col && col <= _legend.getCol() + 19)
			{
				board[row][col].setGamePiece(WALL);
				return;
			}
		}
	}
	switch (ch)
	{
	case Pacman_sign: pacman.setPacmanStartPosition(row, col);
		board[row][col].setGamePiece(Space);
		break;
	case Ghost_sign:
		ghosts.push_back(ghost);
		ghosts[ghosts.size() - 1].SetPosition(row, col);
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

/*maxrow and maxcol are used for tunnels*/
void Game::getBoardInformation(int fileIndex, int& maxRow, int& maxCol)
{
	ifstream File;
	vector<GameBoard> boardLine;
	GameBoard boardCol;
	Ghost ghost;
	if (board.empty() && ghosts.empty())
	{
		board.push_back(boardLine);
	}
	bool legend_appear = false;
	//vector<string> line;
	int colCounter = 0; //maxCol=0;
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
			DecideChar(maxRow, colCounter, ch, legend_appear, ghost);
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
}

void Game::ClearGame()
{
	ClearLevel();
	pacman.setPacmanScore(StartScore);
	pacman.setPacmanLives(StartLives);
	pacman.setPacmanDirection(STAY);
}
 
/*Need to intiliaize Pacman position, also ghosts.
problem with &.*/