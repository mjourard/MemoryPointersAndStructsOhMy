/*************************tictactoe.c****************************
Student Name: Matthew Jourard                        Student Number:  080740
Date: Monday, January 28, 2013                          Course Name: CIS2500
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:
     1) I have read and understood the University policy on academic integrity;
     2) I have completed the Computing with Integrity Tutorial on Moodle; and
     3) I have achieved at least 80% in the Computing with Integrity Self Test.
I assert that this work is my own. I have appropriately acknowledged any and all material
(data, images, ideas or words) that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for this course.
****************************************************************************/
#include "tictactoe.h"


int main() {
  int inputChar, playerTurn, gameOver, dir;
  char* msg;
  msg = malloc(sizeof(char*)*30);
  
  /*Holds the game board pieces data.
  laid out in this style: 012345678
           012
           345
           678
  */
  char boardData[9] = {'-','-','-','-','-','-','-','-','-'};
  
  /*player turn shows who's turn it is
   *winnerCheck will remain valueless until it is needed
   *gameOver remains a 0 until the game is over */
  playerTurn = 1; 
  gameOver = 0;

  initCurses();
  /*draw the board and the pieces here */
  drawBoard();

  while (gameOver == 0) {
    
 
  inputChar = getch(); /* get a single character from the user */
 
  if  (inputChar !='q' ){

    if (inputChar !=' ' ){ /* if it isn't a space, then they are moving */
      sprintf(msg, "Player Number %d\n", playerTurn);
      printMessage(msg, 1);
      switch (inputChar) {
      case KEY_UP: 
	dir = UP;
	break;
      case KEY_RIGHT: 
        dir = RIGHT;
	break;
      case KEY_DOWN: 
        dir = DOWN;
        break; 
      case KEY_LEFT: 
        dir = LEFT;
	break;
      default: 
	break; 
	   
      }
      /*with the dir variable, pass it off to the moveCursor function */
      moveCursor(dir); 
     
    } else { /* it must be a space now.. time to place the symbol */
    
	/*find the cursor, place the symbol, check to see if the game is done */
        drawPieces(boardData, playerTurn);

        /*check to see if the game is over. Either way, end of the while loop. */
        gameOver = checkIsGameOver(boardData);
        /* change the player's turn */
         if (playerTurn > 1) {
            playerTurn = 1;
         } else {
             playerTurn = 2;
         }
   }
      
  } else { /*user typed q, must ask to quit the game */
    printMessage("Would you like to quit the game? Y/N", 2);
    inputChar = getch();
    if (inputChar == 'Y' || inputChar == 'y') {
      endwin();
    } 
  }
 }      
    /* the game is over, do something */

    if (gameOver == 3) {
      printMessage("DRAW! Nobody wins...", 0);
    } else {
      sprintf(msg, "Congrations Player %d, you win!", gameOver);
      printMessage(msg, 1);
    
     
    }
    printMessage("Press \"Q\" to quit.\n", 3);
    while ((inputChar = getch()) != 'q');
    /* leave the endwin() call in at the end of your main. 
       It cleans up ncurses really nicely */
  endwin();
  return(0);
}
