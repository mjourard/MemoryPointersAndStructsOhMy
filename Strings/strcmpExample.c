#define _XOPEN_SOURCE
#define _OPEN_SOURCE_EXTENDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  char * stringA;
  char * stringB;
  int length;

  stringA = strdup("Sample");
  stringB = strdup("Sample");

  printf("\n\n*******\nSet stringA to %s\nSet stringB to %s\n*******\n\n", stringA, stringB);

  printf("strcmp looks at the whole of the two strings, and returns any differences found\nBecause there are no differences between stringA and stringB, it returns %d\n\n", strcmp(stringA, stringB));

  free(stringA);
  free(stringB);

  stringA = strdup("Change");
  stringB = strdup("Changf");

  printf("\n\n*******\nSet stringA to %s\nSet stringB to %s\n*******\n\n", stringA, stringB);

  printf("Here, strcmp returns %d because the last letters of stringA and stringB are different by one value in ASCII\n", strcmp(stringA, stringB));

  free(stringA);
  free(stringB);

  stringA = strdup("Change");
  stringB = strdup("ChangF");

  printf("\n\n*******\nSet stringA to %s\nSet stringB to %s\n*******\n\n", stringA, stringB);

  length = strlen(stringA);

  printf("If we change the last character of stringB to be capitalized, now strcmp returns %d because the values of the last characters are %c->%d and %c->%d\n", strcmp(stringA, stringB), stringA[length - 1], stringA[length - 1], stringB[length - 1], stringB[length - 1]);

}
