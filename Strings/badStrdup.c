#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
  char buffer[] = {"I like pizza."};
  char * strCopy;

  strCopy = strdup(buffer);

  printf("Copied string: '%s'\n", strCopy);

  return 0;
  
}
