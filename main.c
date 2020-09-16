#include <stdio.h>
#include <stdlib.h>


char square[10] = {'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int choice, player;         // choice - what user entered player ( 1- 9)
                            // player - Whose player turn it is 1 or 2
// Function declarations
int checkForWin();              // will return an int
void displayBoard();            // will not return anyting
void markBoard(char mark);      // mark is  X or O. - will be reused for Player 1 and Player 2


int main()
{
    int gameStatus;          // gameStatus will be the return value for checking the win

    char mark;      // either x or o

    player = 1;

    do                  // do while loop because I want to execute the board at least once
    {
        displayBoard();

        // change turns
        player = (player % 2) ? 1 : 2;   // Ternary operator - (condition ? True : False)

        // get input
        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        // set the correct character based on player
        mark = (player == 1) ? 'X' : 'O'; // if its 1st player the give it X else (2) then O [ternary]

        // sets the board based on user choice or invalid choice
        markBoard(mark);        // passing X or O

        gameStatus = checkForWin();         // checking if there's the winner - returns 1, -1 or 0

        player++;

    }while (gameStatus == -1);   // since -1 represents the game is in progress

    if (gameStatus == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");

    return 0;
}

/*********************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOR WITH PLAYERS MARK
*********************************************************************/

void displayBoard()
{
        system("clear");
        printf("\n\n\tTic Tac Toe\n\n");

        printf("Player 1 (X)  - Player 2 (O) \n\n\n");

        printf("        |        |        \n");
        printf("   %c    |   %c    |   %c    \n", square[1], square[2], square[3]);

        printf("________|________|________\n");
        printf("        |        |        \n");

        printf("   %c    |   %c    |   %c    \n", square[4], square[5], square[6]);

        printf("________|________|________\n");
        printf("        |        |        \n");

        printf("   %c    |   %c    |   %c    \n", square[7], square[8], square[9]);

        printf("        |        |        \n\n");
}

/*********************************************************************
set the board to correct character,
x or o in the correct spot in the array
*********************************************************************/
void markBoard(char mark)
{
    if (choice == 1 && square[1] == '1')
        square[1] = mark;

    else if (choice == 2 && square[2] == '2')
        square[2] = mark;

    else if (choice == 3 && square[3] == '3')
        square[3] = mark;

    else if (choice == 4 && square[4] == '4')
        square[4] = mark;

    else if (choice == 5 && square[5] == '5')
        square[5] = mark;

    else if (choice == 6 && square[6] == '6')
        square[6] = mark;

    else if (choice == 7 && square[7] == '7')
        square[7] = mark;

    else if (choice == 8 && square[8] == '8')
        square[8] = mark;

    else if (choice == 9 && square[9] == '9')
        square[9] = mark;

    else
    {
        printf("Invalid move ");

        player--;      // we will mark the player back down by one because here players are 1 or 2


    }
}
/*********************************************************************
FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
**********************************************************************/

int checkForWin()
{
    int returnValue = 0;

    if (square[1] == square[2] && square[2] == square[3])
    {
        returnValue = 1;
    }
    else if (square[4] == square[5] && square[5] == square[6])
        returnValue = 1;

    else if (square[7] == square[8] && square[8] == square[9])
        returnValue = 1;

    else if (square[1] == square[4] && square[4] == square[7])
        returnValue = 1;

    else if (square[2] == square[5] && square[5] == square[8])
        returnValue = 1;

    else if (square[3] == square[6] && square[6] == square[9])
        returnValue = 1;

    else if (square[1] == square[5] && square[5] == square[9])
        returnValue = 1;

    else if (square[3] == square[5] && square[5] == square[7])
        returnValue = 1;

    else if (square[1] != '1' && square[2] != '2' &&  square[3] != '3' && square[4] != '4'
             && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' &&
             square[9] != '9')
        returnValue = 0;

    else
        returnValue = -1;

    return returnValue;

}

