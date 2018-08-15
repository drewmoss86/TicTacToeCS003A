#include <iostream>
#include "TicTacHeader.h"

/**************************************************************************
 * DisplayBoard
 *     This function outputs the tic tac toe board including the tokens
 *     played in the proper format (as described below).
 *
 * RETURNS: nothing
 *     outputs the current state of the board
 *************************************************************************/

void DisplayBoard(const char boardAr[][COLS])
{
    int row;	// Declares the variable for the row of the space
    int col;	// Declares the variable for the column of the space

    // Clears screen
    system("CLS");
    
    // Outputs the playing board
    cout << setw(10) << "1" << setw(8) << "2" << setw(9) << "3\n";
    
    // Displays the tic-tac-toe board
    for (row = 0; row < ROWS; row++)
    {
        cout << setw(7) << "[" << row + 1 << "][1] | " << "[" << row + 1;
        cout << "][2] | " << "[" << row + 1 << "][3]" << endl;
        cout << setw(14) << "|" << setw(9) << "|" << endl;

        // When token is assigned to a certain row and col, will display
        // the token being played to that space
        for (col = 0; col < 3; col++)
        {
            switch(col)
            {
                case 0: cout << row + 1 << setw(9) << boardAr[row][col];
                cout << setw(4) << "|";
                break;
                
                case 1: cout << setw(4) << boardAr[row][col];
                cout << setw(5) << "|";
                break;
                
                case 2: cout << setw(4) << boardAr[row][col] << endl;
                break;
                
                default: cout <<"ERROR!\n\n";
            }
        }
        cout << setw(14)<< "|" << setw(10) << "|\n";
        
        // If row is not equal to 2, will output the dividing line for
        // the tic tac toe board
        if (row != 2)
        {
            cout << setw(32) << "--------------------------\n";
        }
    }
        cout << endl << endl;
}

/**************************************************************************
 * GetAndCheckInp
 *     This function determines which spot the user wants to play in, and must
 *     type in the row and column they would like to occupy. The function will
 *     obtain the input and verify that the row and column are within range and
 *     the spot is not taken.
 *
 * RETURNS: the players names through the variables playerX and playerO.
 *************************************************************************/
void GetAndCheckInp(char boardAr[][COLS], char token, string playerX,
                    string playerO)
{
        int row; 		      // IN - Row position chosen by player
        int col; 		      // IN - Column position chosen by player
        bool invalidRow;      // CALC - Condition to see if row is valid
        bool invalidCol;      // CALC - Condition to see if column is valid
        bool valid = false;;  // CALC - Condition to see if row or column 
                              // is valid

        do
        {
                // Prompts player to type in which space they want to enter
                if(token == 'X')
                {
                    cout << playerX << "'s turn!"
                         << endl << "Please enter row and column: ";
                    cin >> row >> col;
                    cin.ignore(1000,'\n');
                }
                
                else
                {
                    cout << playerO << "'s turn!"
                         << endl << "Please enter row and column: ";
                    cin >> row >> col;
                    cin.ignore(1000,'\n');
                }
                row--;
                col--;

                invalidRow = (row < 0) || (row >= ROWS);
                invalidCol = (col < 0) || (col >= COLS);

                if(invalidRow && invalidCol)
                {
                    valid = false;
                    cout << endl << "Row and column are invalid!" << endl << endl;
                }
                else if(invalidRow)
                {
                    valid = false;
                    cout << endl << "Row is invalid!" << endl << endl;
                }
                else if(invalidCol)
                {
                    valid = false;
                    cout << endl << "Column is invalid!" << endl << endl;
                }
                else if(boardAr[row][col] != ' ')
                {
                    valid = false;
                    cout << "This spot is taken!" << endl << endl;
                }
                else if(boardAr[row][col] == ' ')
                {
                    valid = true;
                    boardAr[row][col] = token;
                }
            } while(!valid);
}

/**************************************************************************
 * GetNumPlayers
 *    This function receives as input the number of players who want to play
 *    tic-tac-toe.
 *
 * RETURNS: players
 *  Returns the number of players who want to play
 *************************************************************************/

int GetNumPlayers(int players)
{
    // Checks if the number of players input by user is valid, if not
    // will loop through
    do
    {
            cout << "If 1 player, enter name for Computer." << endl 
                 << "Please enter the number of players (1 or 2): ";
             
            cin >> players;
            cin.ignore(1000,'\n');
        
        if((players != 1) && (players != 2))
        {
            cout << endl << "INVALID! Please enter 1 or 2." << endl 
                 << endl;
        }
        
    } while((players != 1) && (players != 2));
    
    // Returns either 1 or 2 players
    return players;
}

/**************************************************************************
 * GetPlayers
 *     This function prompts the user and gets the input for the players’ names
 *     playerX will always contain the name of the player that is using the
 *     X token.
 *     playerO will always contain the name of the player that is using the
 *     O token.
 *
 * RETURNS: the players names through the variables playerX and playerO.
 *************************************************************************/
void GetPlayers(string& playerX, // OUT - player X’s name
                string& playerO) // OUT - player O’x name
{
    cout << endl << "Player 1, what is your name?: ";
    getline(cin, playerX);
    cout << endl;
    
    cout << endl << "Player 2, what is your name?: ";
    getline(cin, playerO);
    cout << endl;
}

/**************************************************************************
 * InitBoard
 *     This function initializes each spot in the board to a space ' '.
 *
 * RETURNS: Board initialized with all spaces
 *************************************************************************/
void InitBoard(char boardAr[][COLS]) // OUT - tic tac toe board
{
    int row;
    int col;

    // Initializes the board
    for(row = 0; row < ROWS; row++)
    {
        for(col = 0; col < COLS; col++)
        {
            boardAr[row][col] = ' ';
        }
    }
}

/**************************************************************************
 * OutputInstruct
 *    This function outputs instructions to the users. There are no input
 *    or output parameters for this function as it only displays text to
 *    the screen.
 *
 * RETURNS: nothing
 *    Displays the instructions to the user
 *************************************************************************/

void OutputInstruct()

{
    cout << "****************************************************************\n" 
         << "Instructions: Two players will take turns choosing a spot to "
            "enter on the board. First person to get three in a row, wins." 
            << endl
         << "****************************************************************\n";
}

/**************************************************************************
 * PlayGame
 *    This function receives as input the user's decision to play one game or
 *    exit the program. (Y/N)
 *
 * RETURNS: message
 *    Returns message, the user's input to play one game or not (y/n)
 *************************************************************************/

char PlayGame(char play)
{
    //Checks if user wants to play
    do
        {
            cout << "Want to play?(y/n): ";
            cin >> play;

            cin.ignore(1000,'\n');
            play = toupper(play);
            if((play != 'Y') && (play != 'N'))
            {
                cout << endl << "INVALID INPUT! Please enter 'y' or 'n'."
                     << endl << endl;
            }
        }
        while((play != 'Y') && (play != 'N'));
}
/**************************************************************************
 * SwitchToken
 *    This function switches the active player.
 *    It takes in a parameter representing the current player's token
 *    as a character value (either an X or an O) and returns the opposite.
 *    For example, if this function receives an X it returns an O. If it
 *    receives and O it returns an X.
 *
 * RETURNS: the token opposite of the one in which it receives.
 *************************************************************************/
char SwitchToken(char token) // IN - current player’s token ('X' or 'O')
{

    // Token will switch from X to O
    if(token == 'X')
    {
        token = 'O';
    }
    // Token will switch from O to X
    else if(token == 'O')
    {
        token = 'X';
    }

    return token;
}

/**************************************************************************
 * CheckWin
 *    This function checks to see if either player has run. Once it is
 *    possible for a win condition to exist, this should run after each a
 *    player makes a play.
 *
 * RETURNS the character value of the player that won or a value that
 *    indicates a tie.
 *************************************************************************/
char CheckWin(const char boardAr[][COLS]) // IN - tic tac toe board
{
    char win;	  // Declares variable for the win condition to be checked
    int index;    // Declares index used to go through the array

        // Checks if there is a winner horizontally
        for(index = 0; index < ROWS; index++)
        {
            if( (win = boardAr[index][0]) != ' '
             && (boardAr[index][1] == win)
             && (boardAr[index][2] == win) )
            {
                win = boardAr[index][0];
                return win;
            }
        }
        // Checks if there is a winner vertically
        for(index = 0; index < COLS; index++)
        {
            if( (win = boardAr[0][index]) != ' '
             &&  (boardAr[1][index] == win)
             &&  (boardAr[2][index] == win) )
            {
                win = boardAr[0][index];
                return win;
            }
        }

        // Checks if there is a win diagonally
        if(  (win = boardAr[1][1]) != ' '
          && (boardAr[0][0] == win && boardAr[2][2] == win)
          || (boardAr[2][0] == win && boardAr[0][2] == win) )
        {
            win = boardAr[1][1];
            return win;
        }
        // Checks if all rows and cols are filled and there is no winner
        if(  (boardAr[0][0] != ' ') &&  (boardAr[0][1] != ' ')
         &&  (boardAr[0][2] != ' ') &&  (boardAr[1][0] != ' ')
         &&  (boardAr[1][1] != ' ') &&  (boardAr[1][2] != ' ')
         &&  (boardAr[2][0] != ' ') &&  (boardAr[2][1] != ' ')
         &&  (boardAr[2][2] != ' ') &&  (win = ' '))

        {
            win = 'T';
            return win;
        }
}

/**************************************************************************
 * OutputWinner
 *    This function receives as input a character indicating which player won
 *    or if the game was a tie and outputs an appropriate message. This
 *    function does not return anything as it simply outputs the appropriate
 *    message to the screen.
 *
 * RETURNS: nothing
 *    Displays the winner’s name
 *************************************************************************/
void OutputWinner(char isWinner,   // IN - represents the winner or a value
                                   // indicating a tied game.
                  string playerX,  // OUT - player X’s name
                  string playerO)  // OUT - player O’x name
{
    // Winner will be display: X, O, or tied.
    if((isWinner == 'X') || (isWinner == 'O') || (isWinner == 'T'))
    {
        if(isWinner == 'X')
        {
            cout << "The winner is " << playerX << "!!" << endl;
        }
        else if(isWinner == 'O')
        {
            cout << "The winner is " << playerO << "!!" << endl;
    
        }
        else if(isWinner == 'T')
        {
            cout << "It's a tie." << endl << endl;
        }
    }

}

/**************************************************************************
 * PlayComputer
 *     This function receives as input playerX's choice on the tic-tac-toe
 *     board and randomizes a spot for the computer's choice on the tic-tac-toe board
 *
 * RETURNS: nothing
 *     the updated boardAr, the token played, playerX, playerO
 *************************************************************************/

void PlayComputer(char boardAr[][COLS],
                  char token,
                  string playerX,
                  string playerO)
{
        int row; 		     // IN - Row location input by user
        int col; 		     // IN - Column location input by user
        bool invalidRow;     // CALC - Check if row is valid
        bool invalidCol;     // CALC - Check if col is valid
        bool valid = false;  // CALC - True if row or column is valid

        do
        {
                // Prompts player to type in which space they want to enter
                if(token == 'X')
                {
                    cout << playerX << ", your turn!"
                         << endl << "Please enter row and column: ";
                    cin >> row >> col;
                    cin.ignore(1000,'\n');
                }
                // Computer's move
                else if(token == 'O')
                {
                    cout << playerO <<"\'s turn!";

                    if( (boardAr[0][0] == ' ') ||  (boardAr[0][1] == ' ')
                    ||  (boardAr[0][2] == ' ') ||  (boardAr[1][0] == ' ')
                    ||  (boardAr[1][1] == ' ') ||  (boardAr[1][2] == ' ')
                    ||  (boardAr[2][0] == ' ') ||  (boardAr[2][1] == ' ')
                    ||  (boardAr[2][2] == ' '))
                    {
                        row = (rand() % 3 + 1);
                        col = (rand() % 3 + 1);
                    }
                }
                // Decrements row and col as the location displayed on the
                // board starts at [1][1] instead of [0][0]
                row--;
                col--;

                invalidRow = (row < 0) || (row >= ROWS);
                invalidCol = (col < 0) || (col >= COLS);

                // If it is the user's turn, will output a message
                // according to row and col chosen
                if(token == 'X')
                {
                    if(invalidRow && invalidCol)
                    {
                        valid = false;
                        cout << endl << "Row and column are invalid, please try"
                                " again." << endl << endl;
                    }
                    else if(invalidRow)
                    {
                        valid = false;
                        cout << endl << "Row is invalid!" << endl << endl;
                    }
                    else if(invalidCol)
                    {
                        valid = false;
                        cout << endl << "Column is invalid!" << endl << endl;
                    }
                    else if(boardAr[row][col] != ' ')
                    {
                        valid = false;
                        cout << "This spot is taken!" << endl << endl;
                    }
                    // If the spot assigned is valid the play will be assigned
                    // to that location
                    else if(boardAr[row][col] == ' ')
                    {
                        valid = true;
                        boardAr[row][col] = token;
                    }
                }

                // Since the computer automatically chooses the spot, will not
                // output a message, and will just check if spot is valid
                else if(token == 'O')
                {
                    if(invalidRow && invalidCol)
                    {
                        valid = false;
                    }
                    else if(invalidRow)
                    {
                        valid = false;
                    }
                    else if(invalidCol)
                    {
                        valid = false;
                    }
                    else if(boardAr[row][col] != ' ')
                    {
                        valid = false;
                    }
                    else if(boardAr[row][col] == ' ')
                    {
                        valid = true;
                        boardAr[row][col] = token;
                    }
                }

            } while(!valid);
}
