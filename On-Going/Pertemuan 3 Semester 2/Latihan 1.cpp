#include <stdio.h>
//Fibonaci Sequance rekursif Function//
int fibonacci(int n) 
{
  if (n == 0 || n ==1)
  {return n;} 
  else 
  {return (fibonacci(n-1) + fibonacci(n-2));}
}

int main() 
{
  int n, i, j = 0;
  printf ("INPUT N:");scanf("%d",&n);
  printf("Fibonaci Sequence: \n");
  for (i = 0; i < n; i++)
  {printf("%d,",fibonacci(j));j++;}
  return 0;
}

