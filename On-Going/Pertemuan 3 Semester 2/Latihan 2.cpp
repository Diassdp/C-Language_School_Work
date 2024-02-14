#include <stdio.h>
void Rekursif(int N)
{
  //checker//
  if (N < 0) 
	{return;}
  
  //Rekursif//
	N % 2== 0 ? Rekursif(N - 2): Rekursif(N - 1);
  //print//
	if (N % 2 == 0) 
  {printf("%d,",N);}
}

int main()
{
  int N;
	printf("N:");scanf("%d",&N);
	Rekursif(N);
}
