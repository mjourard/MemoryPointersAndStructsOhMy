/**
 * A simple example of passing command line arguments.
 * 
 * When invoking a program from the command line, each string you pass, including
 * the name of the executable, is passed to the program as a string in argv[].
 * To access them, you just need their index and to treat them as null-terminated strings.
 * 
 * Author: Matthew Jourard
 * Date: 1/23/2016
 */
#include <stdio.h>


int main(int argc, char * argv[]) {
  char lineBuffer[100];

  int i;

  if (argc < 2) {
    printf("Usage: type CLA <argument1> <argument 2> .. <argumentN> to see how argument values are passed in.\nTry Using quatations (\") to pass in arguments with spaces!\n");
  } else {

    printf("[Index] => [Value]\n");
    for(i=0; i<argc; i++){
      printf("[%d] => [%s]\n",i, argv[i]);
    }

  }

  return(0);
}





