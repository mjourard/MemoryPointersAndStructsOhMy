/* 
This example program taken from
http://newtonapples.com/ca08-function-pointer-in-c/
*/
#include<stdio.h>

/*function declarations */

int add(int a, int b) { return a+b;}
int sub(int a, int b) { return a-b;}
int mul(int a, int b) { return a*b;}
int div(int a, int b) { return a/b;}


void mySillyFunction(int a, int b, int (*funcPtr) (int, int))
{
  int result= funcPtr(a,b);
  printf("%d\n", result);
}

main()
{
  mySillyFunction(10, 20, &add); // a-> 10, b->20, *funcPtr-> &add
}
