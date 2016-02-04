/*************************tictactoefunctions.c****************************
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

void initCurses() {
  initscr ();
  cbreak ();
  noecho ();
  keypad (stdscr, TRUE);

}

void drawBoard () {
  int i, j;

  /*make a couple of loops that go through to the size you want 
the board to be and put in the lines for the board.   
the command you want to use is
mvaddch (i, 3, '|');*/
/* verticl lines */
  for (j = 5; j < 12; j+=6) {
      for (i = 0; i <= 10; i++) {
        mvaddch(i, j, '#');
      }
  }
  /* horizontal lines are the same, just reverse i and j in the function call parameters and replace the character that is going to be added there */
 for (j = 3; j < 8; j+=4) {
      for (i = 0; i <= 16; i++) {
        mvaddch(j, i, '#');
      }
  }

/* where the player's pieces should go, denoted by "-" */
 for (i = 2; i < 15; i+=6) {
   for (j = 1; j < 10; j+= 4) {
     mvaddch(j, i, '-');
   }
 }

  /*at the end of each function, reset the cursor to 0,0 and refresh the display*/
 /*Changing to move the cursor so that the user can only select game positions */
  move (1,2);
  refresh ();
}


void printMessage (char *s, int lineNum)
{
  int x, y;
  /* get the current x,y position so that you can put the
     cursor back at the end of the function */
  getyx(stdscr, y, x);
  mvwprintw (stdscr, 12+lineNum, 0, "%s", s);
  
 /*put the cursor back where it was */
  move(y, x);
  refresh ();
}


void  moveCursor(int dir){
  /* Judi solved this one with a switch statement */
   /* going to need the arrow key passed and the current position of the cursor */
  int y, x;
  getyx(stdscr, y, x);
  
  switch(dir) {
  case UP: if (y > 1) {
      move(y-1, x);
    }
    break;
  case RIGHT: if (x < 14) {
      move(y, x + 1);
    } 
    break;
  case DOWN: if (y < 9) {
      move(y + 1, x);
    } 
    break;
  case LEFT: if (x > 2) {
      move(y, x - 1);
    }
      break; 
    default: 
      break; 
    }
  refresh();
}





void drawPieces(char * board, int playerTurn){
  /* find where the cursor is and save it */ 
 int x,y;
  getyx(stdscr, y,x);
  /* figure out which position the player has chosen from the screen posisiton */
  switch(y) {
  case 1:
    switch(x) {
    case 2:
      if (board[0] == '-') {
	  if (playerTurn == 1) {
	    mvaddch(y, x, 'X');
	    board[0] = 'X';
	  } else {
	    mvaddch(y, x, 'O');
	    board[0] = 'O';
	  }
      }
      break;
    case 8: 
      if (board[1] == '-') {
	  if (playerTurn == 1) {
	    mvaddch(y, x, 'X');
	    board[1] = 'X';
	  } else {
	    mvaddch(y, x, 'O');
	    board[1] = 'O';
	  }
      }
      break;
    case 14: 
      if (board[2] == '-') {
	  if (playerTurn == 1) {
	    mvaddch(y, x, 'X');
	    board[2] = 'X';
	  } else {
	    mvaddch(y, x, 'O');
	    board[2] = 'O';
	  }
      }
      break; 
    default:
      break;
    }
    break;
  case 5:
    switch(x) {
    case 2:
      if (board[3] == '-') {
	  if (playerTurn == 1) {
	    mvaddch(y, x, 'X');
	    board[3] = 'X';
	  } else {
	    mvaddch(y, x, 'O');
	    board[3] = 'O';
	  }
      }
      break;
    case 8: 
      if (board[4] == '-') {
	  if (playerTurn == 1) {
	    mvaddch(y, x, 'X');
	    board[4] = 'X'; 
	  } else {
	    mvaddch(y, x, 'O');
	    board[4] = 'O';
	  }
      }
      break;
    case 14: 
      if (board[5] == '-') {
	  if (playerTurn == 1) {
	    mvaddch(y, x, 'X');
	    board[5] = 'X';
	  } else {
	    mvaddch(y, x, 'O');
	    board[5] = 'O';
	  }
      }
      break;
    default:
      break;
    }
    break;
  case 9:
    switch(x) {
    case 2:
      if (board[6] == '-') {
	  if (playerTurn == 1) {
	    mvaddch(y, x, 'X');
	    board[6] = 'X';
	  } else {
	    mvaddch(y, x, 'O');
	    board[6] = 'O';
	  }
      }
      break;
    case 8:
      if (board[7] == '-') { 
	  if (playerTurn == 1) {
	    mvaddch(y, x, 'X');
	    board[7] = 'X';
	  } else {
	    mvaddch(y, x, 'O');
	    board[7] = 'O';
	  }
      }
      break;
    case 14: 
      if (board[8] == '-') {
	  if (playerTurn == 1) {
	    mvaddch(y, x, 'X');
	    board[8] = 'X';
	  } else {
	    mvaddch(y, x, 'O');
	    board[8] = 'O';
	  }
      }
      break;
    default:
      break;
    }
    break; 
 default:
   break;
  }

    
  /* now figure out if that position is occupied (use the char * board) */


  /* put the correct piece in the char * board and then redraw the board so that 
     the new piece shows up */
 
}


int checkIsGameOver(char * board){
  /* if the game is not over,  this function returns a 0. If there is a winner, it returns their player number. If it is a tie, it returns a 3. The function is called after every move */
  /*check if the game is over */
  
  
   if  (board[0] == board[1] && board[0] == board[2]) {
     if (board[0] == 'X') {
       return 1;
     } else if (board[0] == 'O') {
       return 2; 
     } 
   } else if (board[0] == board[4] && board[0] == board[8]) {
     if (board[0] == 'X') {
	   return 1;
     } else if (board[0] == 'O') {
       return 2;
     } 
   } else if (board[0] == board[3] && board[0] == board[6]) {
     if (board[0] == 'X') {
       return 1; 
     } else if (board[0] == 'O') {
       return 2;
     }
   } else if (board[2] == board[4] && board[2] == board[6]) {
     if (board[2] == 'X') {
       return 1; 
     } else if (board[2] == 'O') {
       return 2; 
     }
   } else if (board[2] == board[5] && board[2] == board[8]) {
     if (board[2] == 'X') {
       return 1;
     } else if (board[2] == 'O') {
       return 2;
     }
   } else if (board[1] == board[4] && board[1] == board[7]) {
     if (board[1] == 'X') {
       return 1;
     } else if (board[1] == 'O') {
       return 2;
     }
   } else if (board[3] == board[4] && board[3] == board[5]) {
     if (board[3] == 'X') {
       return 1;
     } else if (board[3] == 'O') {
       return 2;
     }
   } else if (board[6] == board[7] && board[6] == board[8]) {
     if (board[6] == 'X') {
       return 1; 
     } else if (board[6] == 'O') {
       return 2;
     }
   } 
     /* if it gets this far, check to see if it's a draw. */
    int i;
    for (i = 0; i < 9; i++) {
      if (board[i] == '-') {
        return 0;
      }
    }
    return 3; /* at this point, it's a draw, */
   
   
 }
/***********************************************
 *Small thing about this function, 
it doesn't quite work 100% of the time. 
So long as nobody has a move in the top row, 
then a winner can't be determined as the function won't go past that check.
 If I had budgeted my time better, 
I could have found a much more elegant solution than this.
*************************************************/

