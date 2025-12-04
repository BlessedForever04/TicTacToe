# Tic-Tac-Toe: A Battle of Friendship

A classic two-player Tic-Tac-Toe game implemented in C++ with a console-based interface. This project demonstrates fundamental programming concepts including game logic, input validation, and win condition checking.

## Overview

This is a command-line Tic-Tac-Toe game where two players take turns marking spaces on a 3×3 grid. The first player to align three of their marks horizontally, vertically, or diagonally wins the game. The implementation includes automatic move validation, board state management, and replay functionality.

## Features

- **Two-Player Gameplay**: Local multiplayer experience for two players (X and O)
- **Input Validation**: Robust validation ensures only valid moves (rows/columns 1-3) are accepted
- **Overwrite Protection**: Prevents players from overwriting occupied spaces
- **Win Detection**: Automatically detects winning conditions across all rows, columns, and diagonals
- **Draw Detection**: Identifies when the board is full with no winner
- **Replay Option**: Allows players to start a new game immediately after completion
- **Clear Display**: Automatic screen clearing after each move for a clean gaming experience

## Technical Details

### Game Architecture

The game is structured using procedural programming with the following key components:

- **Global Board State**: 3×3 character array representing the game board
- **Move Functions**: Separate functions for X and O player moves (`Xmove()`, `Omove()`)
- **Validation System**: `ValidMove()` ensures input is within valid range (1-3)
- **Board Update Logic**: `updateboard()` handles placing marks and preventing overwrites
- **Win Checker**: `winning()` evaluates all possible winning combinations
- **End Game Handler**: `endgame()` detects draws and offers replay options

### Key Functions

- `display()` - Renders the current board state to the console
- `Xmove()` / `Omove()` - Handle player input for X and O respectively
- `updateboard(row, column, player)` - Updates board with player's move
- `ValidMove(move)` - Recursively validates row/column input
- `winning()` - Checks all 8 possible winning conditions
- `endgame()` - Detects full board and offers game restart
- `game()` - Main game loop coordinating all functions

## How to Build and Run

### Prerequisites

- C++ compiler (GCC, Clang, MSVC, or similar)
- Windows OS (uses `system("cls")` for screen clearing)

### Compilation

```bash
g++ TicTacToe.cpp -o TicTacToe.exe
```

### Running the Game

```bash
./TicTacToe.exe
```

Or on Windows:

```bash
TicTacToe.exe
```

## How to Play

1. **Launch the game** - Run the executable to start
2. **Player X goes first** - Enter row and column numbers (1-3):
   ```
   X's turn -
   Enter row number: 2
   Enter column number: 2
   ```
3. **Player O's turn** - Same process for the second player
4. **Continue alternating** until someone wins or the board fills up
5. **Game ends** when:
   - A player gets three in a row (horizontal, vertical, or diagonal)
   - The board is full (draw) - players can choose to replay or exit

### Board Coordinates

```
   Column:  1   2   3
Row 1:      |   |   
Row 2:      |   |   
Row 3:      |   |   
```

## Game Logic

- Board positions are represented as a 3×3 array initialized with 'A' (empty)
- Players input row and column numbers (1-3)
- The game validates inputs and checks for occupied spaces
- After each move, the board is cleared and redisplayed
- Win conditions check 3 rows + 3 columns + 2 diagonals = 8 total combinations
- Draw condition checks if board is full with no winner

## Code Structure

The implementation uses procedural programming with global state:

```cpp
char board[3][3];  // Global game board
int row, column, factor;  // Global game state variables
```

The `factor` variable controls game flow:
- `0` = Game in progress
- `1` = Game won
- `5` = Game exited

## Future Improvements

As noted in the code comments, potential enhancements include:
- Refactoring to use object-oriented programming (classes for Board, Player, Game)
- Cross-platform compatibility (replace `system("cls")`)
- AI opponent option for single-player mode
- Graphical user interface
- Move history tracking
- Undo functionality
- Better separation of concerns (input/output/logic)

## Disclaimer

⚠️ **Warning**: We take no responsibility for broken friendships, sibling rivalries, or office feuds caused by this game. Play responsibly!

## License

This is an educational project. Feel free to use and modify as needed.

---

*Thanks for reading! Enjoy the game!*
