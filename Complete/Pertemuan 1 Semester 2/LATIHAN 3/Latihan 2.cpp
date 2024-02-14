#include <stdio.h>
int main ()
{
  int I,X;
  I=1;
  while(I<=10)
  {
    X=(I-1)*2+1;
    printf("%4i",X);
    I++;
  }
}
