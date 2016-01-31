/**
 * Strtok is the string tokenizing function in the 'string.h' library.
 * To get the tokens from it, you must call it in succession, where each additional call after the first will return a string between two of the tokens you specified that can be found in the passed in string.
 * 
 * The first call to strtok points to the string to be tokenized. Each successive call while tokenizing the initial string will have NULL as the first passed in  argument.
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main (int argc, char * argv[]){

  int i;
  char * originalHeadToString;
  int originalStringLength;
  int tokenCount; 
  char * tokenDelimitedString;
  char * token;


  if (argc < 3) { 
    printf("Usage: enter a delimited string and the delimiter token. I.e. \"The quick brown fox jumps over the lazy dog.\" \" \"");
    exit(1);
  } else {

    tokenDelimitedString = malloc(sizeof(char)*(strlen(argv[1]) + 1));
    strcpy(tokenDelimitedString, argv[1]);

    originalHeadToString = tokenDelimitedString;
    originalStringLength = strlen(tokenDelmitedString);

    printf("Original string: %s\n", tokenDelimitedString);

    token = strtok(tokenDelimitedString, argv[2]);
    printf("The first token: %s\n", token);
    printf("The string after strtok: %s\n", tokenDelimitedString);
  
    tokenCount = 2;
    while(token != NULL) {
      token = strtok(NULL, argv[2]);
      printf("token %d: %s\n", token);
    }

    printf("Here is a print out of the values stored in the copied string, showing how strtok has modified them.\n");
    for (i = 0; i < originalStringLength; i++) {
      printf("index: %d | character: %c | character value: %d\n", i, originalHeadToString[i], originalHeadToString[i]);
    }

    return 0;
  }

}
