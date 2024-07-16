#include <iostream>
#include <time.h>
using namespace std;

#define Capacity 100
#define Number_of_Players 2

// Function to initialize the game board, player names, symbols, and turn
void Initialization(char Board[Capacity][Capacity], int& Dimensions, char Player_Name[Number_of_Players][30], char Player_Symbol[], int& Turn, int& Win_Count) {
    cout << "Enter Dimensions : ";
    cin >> Dimensions;
    cout << "Enter Win Count : ";
    cin >> Win_Count;

    // Getting player and computer details
    cout << "Player 1 : ";
    cin >> Player_Name[0];
    cout << "Player 1's Symbol : ";
    cin >> Player_Symbol[0];
    cout << "Computer : ";
    cin >> Player_Name[1];
    cout << "Computer's Symbol : ";
    cin >> Player_Symbol[1];

    // Initializing the board with '-'
    for (int ri = 0; ri < Dimensions; ri++) {
        for (int ci = 0; ci < Dimensions; ci++) {
            Board[ri][ci] = '-';
        }
    }

    // Randomly deciding the first turn
    Turn = rand() % Number_of_Players;
}

// Function to display the current state of the game board
void DisplayBoard(char Board[Capacity][Capacity], int Dimensions) {
    system("cls");  // Clears the console screen
    for (int ri = 0; ri < Dimensions; ri++) {
        for (int ci = 0; ci < Dimensions; ci++) {
            cout << Board[ri][ci] << "\t";
        }
        cout << endl;
    }
}

// Function to display a message for the current player
void PlayerMessage(char Player_Name[], char Player_Symbol) {
    cout << Player_Name << "'s (" << Player_Symbol << ") Turn : \n";
}

// Function to get the player's move input
void PlayerTurn(int& ri, int& ci) {
    cout << "Enter Row and Column Number : ";
    cin >> ri >> ci;
    ri = ri - 1;  // Adjusting for zero-based index
    ci = ci - 1;
}

// Function to check if the move is valid
bool IsValidMove(char Board[Capacity][Capacity], int Dimensions, int ri, int ci) {
    return(ri >= 0 && ri < Dimensions && ci >= 0 && ci < Dimensions && Board[ri][ci] == '-');
}

// Function to update the board with the player's move
void UpdateBoard(char Board[Capacity][Capacity], int ri, int ci, char Player_Symbol) {
    Board[ri][ci] = Player_Symbol;
}

// Function to change the turn to the next player
void TurnChange(int& Turn) {
    Turn = (Turn + 1) % Number_of_Players;
}

// Function to check for a horizontal win
bool Is_Horizontal_Win(char Board[Capacity][Capacity], int Dimension, int ri, int ci, int win_count, char player_sym) {
    if (ci + win_count - 1 >= Dimension) {
        return false;
    }
    for (int i = 0; i < win_count; i++) {
        if (Board[ri][ci + i] != player_sym) {
            return false;
        }
    }
    return true;
}

// Function to check for a vertical win
bool Is_Vertical_Win(char Board[Capacity][Capacity], int Dimension, int ri, int ci, int win_count, char player_sym) {
    if (ri + win_count - 1 >= Dimension) {
        return false;
    }
    for (int i = 0; i < win_count; i++) {
        if (Board[ri + i][ci] != player_sym) {
            return false;
        }
    }
    return true;
}

// Function to check for a diagonal win (top-left to bottom-right)
bool Is_Diagnol_Win_1(char Board[Capacity][Capacity], int Dimension, int ri, int ci, int win_count, char player_sym) {
    if (ci + win_count - 1 >= Dimension || ri + win_count - 1 >= Dimension) {
        return false;
    }
    for (int i = 0; i < win_count; i++) {
        if (Board[ri + i][ci + i] != player_sym) {
            return false;
        }
    }
    return true;
}

// Function to check for a diagonal win (bottom-left to top-right)
bool Is_Diagnol_Win_2(char Board[Capacity][Capacity], int Dimension, int ri, int ci, int win_count, char player_sym) {
    if ((ri + win_count - 1 >= Dimension) || (ci - (win_count - 1) < 0)) {
        return false;
    }
    for (int i = 0; i < win_count; i++) {
        if (Board[ri + i][ci - i] != player_sym) {
            return false;
        }
    }
    return true;
}

// Function to check if there is a win
bool IsWin(char Board[Capacity][Capacity], int Dimensions, int Win_Count, char Player_Symbol) {
    for (int ri = 0; ri < Dimensions; ri++) {
        for (int ci = 0; ci < Dimensions; ci++) {
            if (Is_Horizontal_Win(Board, Dimensions, ri, ci, Win_Count, Player_Symbol) ||
                Is_Vertical_Win(Board, Dimensions, ri, ci, Win_Count, Player_Symbol) ||
                Is_Diagnol_Win_1(Board, Dimensions, ri, ci, Win_Count, Player_Symbol) ||
                Is_Diagnol_Win_2(Board, Dimensions, ri, ci, Win_Count, Player_Symbol)) {
                return true;
            }
        }
    }
    return false;
}

// Function to check if the game is a draw
bool IsDraw(char Board[Capacity][Capacity], int Dimensions) {
    for (int ri = 0; ri < Dimensions; ri++) {
        for (int ci = 0; ci < Dimensions; ci++) {
            if (Board[ri][ci] == '-') {
                return false;
            }
        }
    }
    return true;
}

// Function to determine the computer's move
void ComputerMove(char Board[Capacity][Capacity], int Dimensions, int& ri, int& ci, int wincount, char CS, char PS) {
    char TBoard[Capacity][Capacity];

    // Copying the current board to a temporary board
    for (int r = 0; r < Dimensions; r++) {
        for (int c = 0; c < Dimensions; c++) {
            TBoard[r][c] = Board[r][c];
        }
    }

    // Checking if the computer can win
    for (int r = 0; r < Dimensions; r++) {
        for (int c = 0; c < Dimensions; c++) {
            if (IsValidMove(TBoard, Dimensions, r, c)) {
                TBoard[r][c] = CS;
                if (IsWin(TBoard, Dimensions, wincount, CS)) {
                    ri = r;
                    ci = c;
                    return;
                }
                else {
                    TBoard[r][c] = '-';
                }
            }
        }
    }

    // Blocking the human player's winning move
    for (int wc = wincount; wc > 0; wc--) {
        for (int r = 0; r < Dimensions; r++) {
            for (int c = 0; c < Dimensions; c++) {
                if (IsValidMove(TBoard, Dimensions, r, c)) {
                    TBoard[r][c] = PS;
                    if (IsWin(TBoard, Dimensions, wc, PS)) {
                        ri = r;
                        ci = c;
                        return;
                    }
                    else {
                        TBoard[r][c] = '-';
                    }
                }
            }
        }
    }

    // Making a random move if no immediate win or block is possible
    do {
        ri = rand() % Dimensions;
        ci = rand() % Dimensions;
    } while (!IsValidMove(Board, Dimensions, ri, ci));
}

int main() {
    srand(time(0));
    char Board[Capacity][Capacity];
    int Dimensions;
    char Player_Name[Number_of_Players][30];
    char Player_Symbol[Number_of_Players], PlayAgain;
    int Turn, ri = 0, ci = 0;
    int Win_Count, Winner = -1;
    int WinnerCounts[Number_of_Players] = { 0 };
    bool Game_Over = false;

    do {
        // Initialize the game
        Initialization(Board, Dimensions, Player_Name, Player_Symbol, Turn, Win_Count);

        do {
            // Display the game board
            DisplayBoard(Board, Dimensions);

            do {
                // Display the current player's turn message
                PlayerMessage(Player_Name[Turn], Player_Symbol[Turn]);

                // If it's the human player's turn
                if (Turn == 0) {
                    do {
                        // Get the player's move
                        PlayerTurn(ri, ci);
                        if (!IsValidMove(Board, Dimensions, ri, ci)) {
                            cout << "Invalid Move \n";
                        }
                    } while (!IsValidMove(Board, Dimensions, ri, ci));
                }
                else {
                    // If it's the computer's turn, determine the computer's move
                    ComputerMove(Board, Dimensions, ri, ci, Win_Count, Player_Symbol[1], Player_Symbol[0]);
                }
            } while (!IsValidMove(Board, Dimensions, ri, ci));

            // Update the board with the current move
            UpdateBoard(Board, ri, ci, Player_Symbol[Turn]);

            // Check if the game is over (win or draw)
            Game_Over = IsWin(Board, Dimensions, Win_Count, Player_Symbol[Turn]);
            if (Game_Over) {
                Winner = Turn;
            }

            if (!Game_Over) {
                Game_Over = IsDraw(Board, Dimensions);
            }

            // Change the turn to the next player
            if (!Game_Over) {
                TurnChange(Turn);
            }
        } while (!Game_Over);

        // Display the result of the game
        if (Winner == -1) {
            cout << "Draw Game.. ";
        }
        else {
            cout << Player_Name[Winner] << " has won the Match \n";
            WinnerCounts[Winner]++;
        }

        // Ask if the player wants to play again
        cout << "\nDo you want to play again? Press Y for yes and N for no \n";
        cin >> PlayAgain;
        system("cls");  // Clears the console screen
    } while (PlayAgain == 'Y' || PlayAgain == 'y');

    // Display the total matches played and the number of matches each player won
    int total_match = 0;
    for (int i = 0; i < Number_of_Players; i++) {
        total_match = total_match + WinnerCounts[i];
    }
    cout << "Total Matches Played : " << total_match << endl;
    for (int i = 0; i < Number_of_Players; i++) {
        cout << Player_Name[i] << " has won " << WinnerCounts[i] << " matches.. \n";
    }
}
