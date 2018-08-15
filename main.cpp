#include <iostream>
#include "TicTacHeader.h"

int main()
{

    // Variables
    char boardAr[ROWS][COLS];         // IN & OUT & CALC - the game board
    char keepPlaying;				  // IN - input by user if they want to
                                      //      play again
    char newPlayers;				  // IN - input by user if they want to
                                      //      change players
    int players;					  // IN - the number of players
    char token;						  // CALC - the token of the current
                                      //        player (X or O)
    char whoWon;					  // CALC - the winner of the game
    string playerX; 				  // IN & OUT - player X’s name
    string playerO; 				  // IN & OUT - player O's name


    token = 'X';					  // Initializes token to 'X', player 1
    whoWon = ' ';					  // Initializes winner
    srand(time(NULL));    			  // Generates random number to play against
                                      // the computer

    // Outputs the instructions to play the game
    OutputInstruct();

    // Initializes all board spaces to ' '
    InitBoard(boardAr);

    // Asks user if they want to play
    keepPlaying = PlayGame(keepPlaying);

    // If user wants to play, will get the number of players and names
    if(keepPlaying == 'Y')
    {
        players = GetNumPlayers(players);
        GetPlayers(playerX, playerO);
    }

    // Loops through while the user inputs 'Y' to play again
    while(keepPlaying == 'Y')
    {
        // Displays the tic-tac-toe board
        DisplayBoard(boardAr);

        // Two player mode is selected
        if(players == 2)
        {
            GetAndCheckInp(boardAr, token, playerX, playerO);
        }
        // One player mode is selected
        else if(players == 1)
        {
            PlayComputer(boardAr, token, playerX, playerO);
        }
        DisplayBoard(boardAr);
        // Switches token after making a move
        token = SwitchToken(token);
        // Will check if there is a win condition
        whoWon = CheckWin(boardAr);
        // If there is a winner, will output message
        if((whoWon == 'X') || (whoWon == 'O') || (whoWon == 'T'))
        {
            // Outputs the winner of the game
            OutputWinner(whoWon, playerX, playerO);
            // Asks user if they want to play another game
            keepPlaying = PlayGame(keepPlaying);
            // If user types 'Y', will prompt user to change players
            if(keepPlaying == 'Y')
                {
                    do
                    {
                        // Asks if user wants to change players
                        cout << "Would you like to change players? (y/n)";
                        cin >> newPlayers;
                        cin.ignore(1000,'\n');
                        newPlayers = toupper(newPlayers);

                        if((newPlayers != 'Y') && (newPlayers != 'N'))
                        {
                            cout << "\nINVALID INPUT! Please enter 'y' or"
                                    " 'n'.\n\n";
                        }
                    }
                    while((newPlayers != 'Y') && (newPlayers != 'N'));
                    // If user wants to input new players, will ask for
                    // player names again
                    if(newPlayers == 'Y')
                    {
                        players = GetNumPlayers(players);
                        GetPlayers(playerX, playerO);
                    }
                        InitBoard(boardAr);
                }
        }
    }

    return 0;
}
