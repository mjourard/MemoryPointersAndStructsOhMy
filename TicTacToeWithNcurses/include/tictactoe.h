#include <ncurses.h>
#include <stdlib.h>
/*macros used for determining where to move the cursor provided by Judi */

#define UP	1
#define DOWN	2
#define LEFT	3
#define RIGHT	4


/* ncurses initialization function. */
void initCurses();

/* Judi use a character array called board in her solution (char * board) that was 9 elements 
long and just held the x and 0 characters.  the first three elements were the first row of the 
board, the next three were the second row, the last three were the third row.   All the logic
was calculated using that array.  The visual display just showed what that array represented */


void drawBoard ();

/*************************************
HANDLES THE GAMEPLAY
*************************************/

void drawPieces(char * board, int playerTurn);
/*prints an 'X' if playerTurn = 1, 'O' if playerTurn = 2 */

void printMessage ( char*s, int lineNum);
/*takes the string passed to the function and prints it out on the 12th line + however much is passed as the second parameter. E.g. printMessage("hello, World!", 1); would be printed on the 13th line. */

void  moveCursor(int dir);


/*************************************
VICTORY CONDITION HANDLING FUNCTIONS
*************************************/


int checkIsGameOver(char * board);
/*Checks to see if there are any remaining '-' characters. If there are, the game is not over and returns a 0. If the game is over, returns a 1. */

int checkWinner(char * board);
/*Should only be called once the game is over as determined by the checkIsGameOver functions.
 *returns a 0 if it's a tie, 1 if player 1 won and 2 if player 2 won. */


