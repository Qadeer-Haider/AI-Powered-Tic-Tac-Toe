# Tic-Tac-Toe-Battle-Human-vs.-Computer-AI in C++

This project is a C++ implementation of a Tic Tac Toe game where a human player competes against the computer. The game board is dynamically sized, and the first player to achieve a specified winning condition wins the game.

## Project Structure

1. **Game Initialization**
    - Setting up the game board
    - Getting player names and symbols
    - Determining the first turn randomly

2. **Game Loop**
    - Displaying the game board
    - Handling player turns
    - Validating moves
    - Updating the game board

3. **Win and Draw Conditions**
    - Checking for horizontal, vertical, and diagonal wins
    - Checking for draw conditions

4. **Computer's Move Logic**
    - Implementing the computer's strategy
    - Blocking the player's winning moves
    - Making a random move if no immediate win or block is possible

## Game Initialization

### Initialization

The `Initialization` function sets up the game board, player names, symbols, and randomly decides the first turn.

### Displaying the Board

The `DisplayBoard` function clears the console screen and displays the current state of the game board.

## Player and Computer Turns

### Player Turns

The `PlayerTurn` function gets the player's move input and validates it.

### Computer Turns

The `ComputerMove` function implements the computer's strategy to either win the game or block the player's winning moves.

## Win and Draw Conditions

### Checking for Wins

The `IsWin` function checks for horizontal, vertical, and diagonal wins.

### Checking for Draw

The `IsDraw` function checks if the game is a draw by verifying if the board is fully occupied without any winning condition met.

## Code Overview

### Main Game Loop

The `main` function contains the game loop, handling the initialization, game logic, and turn changes until the game is over. After the game ends, it asks the player if they want to play again.

### Game Logic Functions

- `Is_Horizontal_Win`
- `Is_Vertical_Win`
- `Is_Diagnol_Win_1`
- `Is_Diagnol_Win_2`

These functions check for winning conditions in the respective directions.

## Playing the Game

When you run the game, you will be prompted to:
- Enter the board dimensions.
- Enter the winning count (number of consecutive symbols needed to win).
- Enter player names and symbols.

The game then alternates turns between the player and the computer until a win or draw condition is met. If you choose to play again, the game will reinitialize and start over.

## Example Output

```sh
Enter Dimensions : 3
Enter Win Count : 3
Player 1 : Alice
Player 1's Symbol : X
Computer : Bob
Computer's Symbol : O
```

The board is displayed after each move, and the current player's turn is indicated. The game continues until a win or draw is declared.

