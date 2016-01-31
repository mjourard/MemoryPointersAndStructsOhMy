#include <stdlib.h>
#include <stdio.h>
#include "fpheader.h"
Patron ** loadSomeData();
int main(void)
{

  int time;
  Patron ** myList;

  time = 0;
  myList = loadSomeData();

  if(myList[0]->movie){
     time += myList[0]->payment(myList[0]->speed);
  }
  if(myList[0]->snack){
   time += myList[0]->payment(myList[0]->speed);
  }
  printf("time: %d\n", time);

return(0);
}




Patron ** loadSomeData(){
  Patron ** newList = malloc(sizeof(Patron*)*3);
  newList[0] = malloc(sizeof(Patron));
  newList[0]->id = 1;
  newList[0]->movie = true;
  newList[0]->snack = true;
  newList[0]->speed = slow;
  newList[0]->payment = &cash;

  newList[1] = malloc(sizeof(Patron));
    newList[1]->id = 1;
  newList[1]->movie = true;
  newList[1]->snack = false;
  newList[1]->speed = med;
  newList[1]->payment = &cheque;

 newList[2] = malloc(sizeof(Patron));
    newList[2]->id = 1;
  newList[2]->movie = true;
  newList[2]->snack = false;
  newList[2]->speed = fast;
  newList[2]->payment = &debit;


 return (newList);
}

