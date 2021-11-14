#include "Game.h"
//GameBoard board[SizeRow][SizeCol];


Game::Game()
{
	_numBread = 0;
}

Game::~Game()
{
}

bool Game::checkWall(const int& x,const int& y, GameBoard board[][SizeCol])
{
	if (board[x][y].getSignpiece() == '#')
		return true;
	return false;
}

bool Game::checkTunnel(const int& row, const int& col, GameBoard board[][SizeCol])
{
	if (row == 30)
	{
		if (col == 0 || col == 19)
			return true;
	}
	else if (col == 10)
		if (row == 0 || row == 59)
			return true;
	return false;
}

void Game::checkImpact(Pacman& pacman, Ghost* ghosts, GameBoard board[][SizeCol])
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
				PrintBoard(board, pacman, ghosts);
				return;
			}
	}
	return;
}

char Game::DecideChar(const int& row, const int& col)
{
	if (col == 0 || col == 59)
	{
		if (row == 10)
			return ' ';
		else
			return '#';
	}
	else if (row == 0 || row == 19)
	{
		if (col == 30)
			return ' ';
		else
			return '#';
	}
	else if (row == 12 || row == 13)
	{
		if (5 <= col && col <= 13)
			return '#';
		else
			return char(248);
	}
	else if (col == 15)
	{
		if (10 <= row && row < 16)
			return '#';
		else
			return char(248);
	}
	else if (col == 3)
	{
		if (10 <= row && row <= 15)
			return '#';
		else
			return char(248);
	}
	else
		return char(248);
}

void Game::GameCycle()
{
	Ghost ghosts[2]; 
	GhostInitialize(ghosts);
	Pacman pac;
	GameBoard board[SizeRow][SizeCol]; 
	InitBoard(board);
	PrintBoard(board, pac, ghosts);
	GameRun(pac, ghosts, board);


	//GameBoard board[SizeRow][SizeCol];
	// first ghosts movements are needed to be randomized outside of the ghost class. meaning: in this function
	
 //ahrey she buza zaad zarih lahzor la mishbezet ha kodemet ladpis ota. nase at ze bezrat ha kelet mi ha mishtamesh, o kelet shel ha ruah.
}

void Game::InitBoard(GameBoard board[][SizeCol])
{
	int row, col;
	char sign;
	for (row = 0; row < SizeRow; row++)
		for (col = 0; col < SizeCol; col++)
		{
			
			if (!(row == 12 && col == 30))
			{
				sign = DecideChar(row, col);
				if (sign == FOOD)
					_numBread++;
				board[row][col].setGamePiece(sign);
			}
			else
				board[row][col].setGamePiece(' ');
			
		}
}

void Game::PrintBoard(GameBoard board[][SizeCol], Pacman& pacman, Ghost* ghosts) const
{
	int row, col;
	for(row=0; row <SizeRow; row++)
		for (col = 0; col < SizeCol; col++)
			board[row][col].printPiece(row,col);
	for (auto i = 0; i < 2; i++)
		ghosts[i].Print();
	pacman.printPacman();
	PrintScoreAndLives(pacman);
	
}

void Game::Menu()
{
	char user_input;
	PrintMenu();

	do
	{
		user_input = _getch();
		switch (user_input)
		{
		case '1': GameCycle();
			break;
		case '8': clrscr();
			Instructions(user_input);
			break;
		case '9': clrscr();
			cout << "Good Bye" << endl;
			return;
		default: clrscr();
			cout << "Incorrect input";
			Sleep(1400);
			break;
		}
		clrscr();
		PrintMenu();	
	} while (true);

}

void Game::PrintMenu() const
{
	cout << "Welcome To Pacman" << endl;
	cout << "(1) Start a new game" << endl;
	cout << "(7) Turn on/off colors" << endl;
	cout << "(8) Present instructions and keys" << endl;
	cout << "(9) EXIT" << endl;
}

void Game::Instructions(char& user_input)
{
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
	cout << "Menu: ESC" << endl;
	cout << endl;
	cout << "To return to the menu press ESC.";
	do
	{
		user_input = _getch();
	} while (user_input != 27);
}

void Game::GameRun(Pacman& pacman, Ghost* ghosts, GameBoard board[][SizeCol])
{
	char tmp_move = 0;
	bool IsGhostTurn = false;
	while (pacman.getPacmanLives() != 0 || _numBread != 0)//or pacman earned max points
	{
		if (IsGamePaused(tmp_move) == true) //waits until user select ESC again to continue game.
		{
			clrscr();
			PrintBoard(board, pacman, ghosts);
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
		
		if (IsGhostTurn == true)// makes sure that ghosts move once in two pacman moves.
		{
			//to do: randomly pick a direction for ghosts
			ghosts[0].UpdateMove(board); // updates the ghost's movements (if needed it changed direction)
			ghosts[1].UpdateMove(board);
			//move ghosts
			IsGhostTurn = false;
		}
		else
			IsGhostTurn = true; 
		if (pacman.CheckIfPacmanHitWall(board))
			pacman.setPacmanDirection(STAY);
		pacman.setPacmanPosition();
		//enter pacman's direction change and prev char.
		board[pacman.getPacmanRow()][pacman.getPacmanCol()].printPiece(pacman.getPacmanRow(), pacman.getPacmanCol());
		//pacman.setPacmanPosition(direction);
		CheckIfPacmanAteFood(pacman, board);
		pacman.printPacman();
		//ConsequencesOfMove(pacman, ghosts, board, direction);
		PrintScoreAndLives(pacman);
		Sleep(1000);
	}
	//after game is over (win or lose)
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
			Sleep(1000);
		}
		return true;
	}
	return false;
}

bool Game::IsMoveValid(const char& ch)
{
	if (ch == STAY || ch == (STAY - 32))
		return true;
	else if (ch == LEFT || ch == (LEFT - 32))
		return true;
	else if (ch == RIGHT || ch == (RIGHT - 32))
		return true;
	else if (ch == UP || ch == (UP - 32))
		return true;
	else if (ch == DOWN || ch == (DOWN - 32))
		return true;
	else if (ch == PAUSE)
		return true;
	else
		return false;
	
}

/*this function checks if pacman ate, hit a ghost, or got into a tunnel*/
void Game::ConsequencesOfMove(Pacman& pacman, Ghost* ghosts, GameBoard board[][SizeCol], char &direction)
{
	/* 1. print the game board's pacman location before move.
	* 2. move pacman
	* 3. checks
	* 4. prints
	*/
	board[pacman.getPacmanRow()][pacman.getPacmanCol()].printPiece(pacman.getPacmanRow(), pacman.getPacmanCol());
	PacmanCheck(pacman, board, direction);
	//Ghostcheck (walls)
	checkImpact(pacman, ghosts, board);
	
}

void Game::PacmanCheck(Pacman& pacman, GameBoard board[][SizeCol], char& direction)
{
	//check if there's a wall.
	pacman.setPacmanPosition();
	CheckIfPacmanAteFood(pacman, board);
	//checkTunnel()

}

void Game::CheckIfPacmanAteFood(Pacman& pacman, GameBoard board[][SizeCol])
{
	if (board[pacman.getPacmanRow()][pacman.getPacmanCol()].getSignpiece() == FOOD)
	{
		pacman.setPacmanScore();
		_numBread--;
		board[pacman.getPacmanRow()][pacman.getPacmanCol()].setGamePiece(' ');
	}
}

void Game::PrintScoreAndLives(Pacman& pacman) const
{
	gotoxy(21, 0);
	cout << "Your score: " << pacman.getPacmanScore();
	gotoxy(21, 30);
	cout << "Remaining lives: " << pacman.getPacmanLives();
}


void Game::GhostInitialize(Ghost* ghosts)
{
	int i;
	for (i = 0; i < 2; i++)
	{
		ghosts[i].SetPosition(StartGhostRow + i * 10, StartGhostCol);
	}
}

void Game::PrintLifeLost(Pacman& pacman)
{
	clrscr();
	gotoxy(20, 20);
	cout << "The Pacman was eaten by a ghost." << endl;
	cout << "You have " << pacman.getPacmanLives() << "Lives reamining";
	Sleep(1000);
	clrscr();
}

