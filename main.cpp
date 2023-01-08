#include <iostream>
using namespace std;

const int ROW_SIZE = 3;
const int COLUMN_SIZE = 3;

void container();
void initializeBoard(char board[ROW_SIZE][COLUMN_SIZE]);
void printToScreen(char board[ROW_SIZE][COLUMN_SIZE]);
void userInput(int (&input)[2]);
bool isValidInput(char board[ROW_SIZE][COLUMN_SIZE], int input[2]);
bool isBoardFull(char board[ROW_SIZE][COLUMN_SIZE]);
void updateBoard(char(&board)[ROW_SIZE][COLUMN_SIZE], int input[2], char player);
void updatePlayer(char& player, bool& xTurn);
bool isWinner(char board[ROW_SIZE][COLUMN_SIZE], char player);

int main()
{
	container();

	return 0;
}

void container()
{
	char board[ROW_SIZE][COLUMN_SIZE];
	char player = 'X';
	bool xTurn = true;
	int input[2];

	initializeBoard(board);

	cout << "Welcome to TicTacToe" << endl;

	bool run = true;

	while (run)
	{
		cout << "It is " << player << "'s turn." << endl;
		printToScreen(board);

		do
		{
			userInput(input);
		} while (!isValidInput(board, input));

		updateBoard(board, input, player);

		if (isWinner(board, player))
		{
			run = false;
			printToScreen(board);
			cout << player << " won!" << endl;
			break;
		} 
		else if (isBoardFull(board))
		{
			run = false;
			printToScreen(board);
			cout << "It is a tie!" << endl;
			break;
		}

		updatePlayer(player, xTurn);
	}
}

void initializeBoard(char board[ROW_SIZE][COLUMN_SIZE])
{
	for (int row = 0; row < ROW_SIZE; row++)
	{
		for (int column = 0; column < COLUMN_SIZE; column++)
		{
			board[row][column] = ' ';
		}
	}
}

void printToScreen(char board[ROW_SIZE][COLUMN_SIZE])
{
	for (int row = 0; row < ROW_SIZE; row++)
	{
		for (int column = 0; column < COLUMN_SIZE; column++)
		{
			if (column < COLUMN_SIZE - 1)
			{
				cout << board[row][column] << " | ";
			}
			else
			{
				cout << board[row][column];
			}
		}
		cout << endl;

		if (row < ROW_SIZE - 1)
		{
			for (int column = 0; column < COLUMN_SIZE; column++)
			{
				if (column == COLUMN_SIZE - 1)
				{
					cout << "-";
				}
				else
				{
					cout << "----";
				}
			}
			cout << endl;
		}
	}
}

void userInput(int (&input)[2])
{
	int offset = 1;

	cout << "Enter row THEN column: ";
	cin >> input[0];
	cin >> input[1];

	input[0] -= offset;
	input[1] -= offset;
}

bool isValidInput(char board[ROW_SIZE][COLUMN_SIZE], int input[2])
{
	if ((input[0] < 0 || input[0] > ROW_SIZE - 1) || (input[1] < 0 || input[1] > COLUMN_SIZE - 1))
	{
		cout << "Row or Column does not exist!" << endl;
		return false;
	}
	else if (board[input[0]][input[1]] != ' ')
	{
		cout << "Spot is already occupied!" << endl;
		return false;
	}
	else
	{
		return true;
	}
}

bool isBoardFull(char board[ROW_SIZE][COLUMN_SIZE])
{
	for (int row = 0; row < ROW_SIZE; row++)
	{
		for (int column = 0; column < COLUMN_SIZE; column++)
		{
			if (board[row][column] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

void updateBoard(char (&board)[ROW_SIZE][COLUMN_SIZE], int input[2], char player)
{
	board[input[0]][input[1]] = player;
}

void updatePlayer(char& player, bool& xTurn)
{
	if (xTurn)
	{
		xTurn = false;
		player = 'O';
	}
	else
	{
		xTurn = true;
		player = 'X';
	}
}

bool isWinner(char board[ROW_SIZE][COLUMN_SIZE], char player)
{
	// Check Rows
	for (int row = 0; row < ROW_SIZE; row++)
	{
		bool result = false;
		for (int column = 0; column < COLUMN_SIZE; column++)
		{
			if (player == board[row][column])
			{
				result = true;
			}
			else
			{
				result = false;
				break;
			}
		}
		if (result)
		{
			return true;
		}
	}

	// Check Columns
	for (int column = 0; column < COLUMN_SIZE; column++)
	{
		bool result = false;
		for (int row = 0; row < ROW_SIZE; row++)
		{
			if (player == board[row][column])
			{
				result = true;
			}
			else
			{
				result = false;
				break;
			}
		}
		if (result)
		{
			return true;
		}
	}

	// Check Left-Right Diagnol
	bool result = false;
	for (int row = 0; row < ROW_SIZE; row++)
	{
		if (player == board[row][row])
		{
			result = true;
		}
		else
		{
			result = false;
			break;
		}
	}

	if (result)
	{
		return true;
	}

	// Check Right-Left Diagnoal
	result = false;
	for (int row = 0; row < ROW_SIZE; row++)
	{
		int column = COLUMN_SIZE - row - 1;
		if (player == board[row][column])
		{
			result = true;
		}
		else
		{
			result = false;
			break;
		}
	}

	if (result)
	{
		return true;
	}

	return false;
}
