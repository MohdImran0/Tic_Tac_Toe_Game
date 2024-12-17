Overview

This project is a simple Tic-Tac-Toe game implemented in C++. It allows two players to play against each other in a terminal-based interface. The program manages the game board, checks for winning conditions, handles invalid moves, and provides the option to play multiple rounds.


Game Rules:

    A player wins if they align 3 of their marks (X or O) horizontally, vertically, or diagonally.
    The game ends in a draw if all cells are filled and no player has won.
    Interactive Console: Players input their moves (row and column).
    Validation: Prevents invalid moves such as overwriting existing marks.
    Replay Option: After completing a game, players can choose to play again.

Code Structure:-

The program consists of the following key components:
      
      initializeBoard() - Initializes an empty 3x3 game board.
      displayBoard() - Displays the game board in a clean format.
      makeMove() - Handles player input and ensures valid moves.
      checkWin() - Checks if a player has won the game.
      isDraw() - Checks if the game is a draw.
      main() - Controls the game flow, including player turns, input, and replay functionality.

