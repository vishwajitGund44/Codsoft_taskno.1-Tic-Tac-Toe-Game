#include <iostream>
#include <vector>
const int BOARD_SIZE = 3;
std::vector<std::vector<char> > board(BOARD_SIZE, std::vector<char>(BOARD_SIZE, ' '));
void printBoard()
{
    for (int row = 0; row < BOARD_SIZE; ++row)
	 {
        for (int col = 0; col < BOARD_SIZE; ++col)
		 {
            std::cout << board[row][col];
            if (col < BOARD_SIZE - 1)
			 {
                std::cout << " | ";
            }
        }
        std::cout << std::endl;
        if (row < BOARD_SIZE - 1)
		 {
            std::cout << "---------" << std::endl;
        }
    }
    std::cout << std::endl;
}

bool isMoveValid(int row, int col)
 {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == ' ';
}

bool checkWin(char player)
 {
 	
    for (int i = 0; i < BOARD_SIZE; ++i)
	 {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) 
		{
            return true; 
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) 
		{
            return true; 
        }
    }

    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
	 {
        return true; 
    }

    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
	 {
        return true; 
    }

    return false;
}

bool isBoardFull()
 {
    for (int row = 0; row < BOARD_SIZE; ++row)
	 {
        for (int col = 0; col < BOARD_SIZE; ++col)
		 {
            if (board[row][col] == ' ')
			 {
                return false;
            }
        }
    }
    return true;
}

int main()
 {
    char currentPlayer = 'X';
    int row, col;
    bool gameWon = false;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    while (true)
	 {
        printBoard();

        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        if (isMoveValid(row, col)) 
		{
            board[row][col] = currentPlayer;

            if (checkWin(currentPlayer)) 
			{
                gameWon = true;
                break;
            } else if (isBoardFull()) 
			{
                break; // Draw
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
		 else
		  {
            std::cout << "Invalid move. Try again." << std::endl;
        }
    }

    printBoard();

    if (gameWon)
    {
        std::cout << "Player " << currentPlayer << " wins! Congratulations!" << std::endl;
    } 
	else 
	{
        std::cout << "It's a draw! The game is over." << std::endl;
    }

}

