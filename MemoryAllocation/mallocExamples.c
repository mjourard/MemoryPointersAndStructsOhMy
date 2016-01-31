/*
 * This file was created to server as an example as to how to use malloc as well
 * as to demonstrate all the different pitfalls that those new to C might fall into.
 *
 * Author: Matthew Jourard
 * Date: 2016-1-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 500

int main(void)
{

  char buffer[BUFFER_SIZE];

  char * sampleString;

  printf("Hello, I hope this tutorial on memory allocation shows you how to use malloc, calloc and realloc.\n\n");

  printf("To start, malloc, calloc and realloc are short forms for memory allocation, clear and allocated, and reallocate.\n");

  /* The memory allocated by both malloc and realloc are not changed from what they were last set to.
   * That is why calloc exists, clear and allocate sets the values in the allocated memory to 0.
   * This is a case of if you don't need to clear the memory, then don't. 
   * One pitfall I fell into was lazily using calloc so that I didn't have to set the null terminator for strings for easy strcat calls. Don't do that.
   */


  /* show the different sizes of the basic variable types */

  /* You allocate memory at compile time (also called dynamic allocation), 
   * so you can create arrays of a single data type of any size. */

  /* For example, I can save a string you type in right now, 
   * using a fixed allocation of memory referred to as a buffer, 
   * and then a pointer to a character variable. 
   */

  printf("\nEnter a string. Up to the first %d characters will be saved.\n", BUFFER_SIZE - 1);

  fgets(buffer, BUFFER_SIZE, stdin);

  /* Alright, we've now saved a string. 
   * In order to allocate enough memory, we need to know how many characters there are, 
   * as well as size of a single character variable.
   * Once we know both of those, we multiply the two values together to get the number
   * of bytes we need to allocate. 
   */

  printf("You can get the number of characters with a call to strlen. Calling strlen on %s returns this many characters: %d\n", buffer, (int)strlen(buffer));

  /* You can find the size of any type of variable with a call to sizeof. */

  printf("Basic variable types, we have:\nchar | %d\n int | %d\n bool | %d\n long | %d\n", (int)sizeof(char), (int)sizeof(int), (int)sizeof(bool), (int)sizeof(long));
  
  printf("\nOverall, not very interesting, however it's best to use sizeof when determining the size of variables as it makes your code more portable between systems.\n");

  
  sampleString = malloc( (strlen(buffer) + 1) * sizeof(char));
  
  strcpy(sampleString, buffer);

  printf("sampleString = '%s'\n", sampleString);

  /* NOTE: sizeof will not return the number of a characters in an array. This is because it only looks at the size of the type of variable passed in. 
   * sizeof wouldn't know how much memory is allocated just by looking at a pointer or a variable, so that is why you can't use sizeof to determine the length of a string.
   */

  printf("calling sizeof on buffer: %d\nCalling sizeof on sampleString: %d\n", (int)sizeof(buffer), (int)sizeof(sampleString));
  
  

  /* Allocating memory for an array of ints is pretty much the same as for chars */
  int * intArray;
  int size;
  int i;

  printf("Enter the size of an integer array you would like: ");
  scanf("%d", &size);

  if (size <= 0)
    {
      size *= -1;
      size++;
    }

  printf("Allocating an array of %d ints. (NOTE: ensured a positive number was used.\n", size);
    

  intArray = malloc(sizeof(int) * size);

  for (i = 0; i < size; i++)
    {
      intArray[i] = i * size;
    }

  printf("And just to reiterate, calling sizeof on intArray: %d\n", (int)sizeof(intArray));


  /* Sometimes, for one reason or another, memory allocation fails. This could be because there isn't enough that you requested, or it's corrupted, etc. etc. 
  * To test for this, you simply need to check ensure the returned value of malloc isn't null.
  */

  /* A quick oneline check:
   * if ( (intArray = malloc(sizeof(int) * size)) == NULL) {
   *   //Handle appropriately
   * }
   */

  /* Since arrays are stored as pointers, 
     or rather pointers store the address of the first element in an allocated array,
   * you can actually move through an array by adding to the address of the first pointer.
*/

  char * moved;

  moved = sampleString;

  printf("sampleString: '%s'\n", sampleString);

  printf("First element: %c\n", moved[0]);

  moved++;
  printf("Second element: %c\n", moved[0]);

  moved++;
  printf("Third element: %c\n", moved[0]);
  

  /* The last part of the lesson is that you must always free allocated memory once you are done with it.
   * When a program exits, all of its allocated memory is automatically freed by the OS.
   * However, if you are losing the reference to allocated memory, you will leak memory.
   * I will now free all the allocated memory for this program by passing free the pointers we have used.
   * Then I will show use a loop to leak a lot of memory quickly. 
   * You can see the memory leaks with valgrind. 
   */

  free(sampleString);

  //This is good practice but not necessary
  sampleString = NULL;

  free(intArray);

  intArray = NULL;

  int loops;

  loops = 100;

  for (i = 1; i <= loops; i++)
    {
      sampleString = malloc(sizeof(char) * i);
    }

  printf("We have now leaked %d bytes of memory.\n", (loops * (loops + 1)) / 2);

  printf("Now you should have understood how to use malloc. Good luck.\n");

  return 0;

  
}
