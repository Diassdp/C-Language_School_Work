#include <stdio.h>

int main ()
{
  int a,b,c,max;
  printf("input 3 Buah Bilangan\n");
  printf("Bilangan 1: ");scanf("%i",&a);
  printf("Bilangan 2: ");scanf("%i",&b);
  printf("Bilangan 3: ");scanf("%i",&c);
  max=0;
  if(a>b)
  {
    if(a>c) {printf("%i",a);}
    else    {printf("%i",c);}
  }
  else
  {	
    if(b>c) {printf("%i",b);}
    else    {printf("%i",c);}
  }
}
