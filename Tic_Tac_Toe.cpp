#include <iostream>
#include <vector>

using namespace std;

void initializeBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------\n";
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------\n";
    }
}

bool checkWin(const vector<vector<char>>& board, char player) {
 
    for (int i = 0; i < 3; ++i) {
        
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    return false;
}

bool isDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool makeMove(vector<vector<char>>& board, int row, int col, char player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3));
    char currentPlayer = 'X';
    bool gameOver = false;
    int row, col;

    while (true) {
        
        initializeBoard(board);
        gameOver = false;

        while (!gameOver) {
            
            displayBoard(board);

            cout << "Player " << currentPlayer << "'s turn. Enter row (0-2) and column (0-2): ";
            cin >> row >> col;

            if (!makeMove(board, row, col, currentPlayer)) {
                cout << "Invalid move, try again.\n";
                continue;
            }

            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!\n";
                gameOver = true;
            }

            else if (isDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                gameOver = true;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }

    cout << "Thanks for playing!\n";
    return 0;
}