#include <ncurses.h>
#define UP	1
#define DOWN	2
#define LEFT	3
#define RIGHT	4

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

void  moveCursor(char dir, int x, int y) {
/* Judi solved this one with a switch statement */
  /* going to need the arrow key passed and the current position of the cursor */
  
  switch(dir) {
  case UP: if (y > 1) {
      move(y-4, x);
    }
    break;
  case RIGHT: if (x < 14) {
      move(y, x + 6);
    } 
    break;
  case DOWN: if (y < 9) {
      move(y + 4, x);
    } 
    break;
  case LEFT: if (x > 2) {
      move(y, x - 6);
    }
      break; 
    default: 
      break; 
    }

}


  
      

int main(void) {
  char in, dir;
  initCurses();
  drawBoard();
  

     moveCursor(dir, 1, 2);
  }
  endwin();
  return 0;
}
