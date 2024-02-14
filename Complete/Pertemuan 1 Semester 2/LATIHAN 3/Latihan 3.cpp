#include <stdio.h>
int main ()
{
  int n;
  double V=2,S=2;
  for(n=1;n<=100;n++)
  {
    printf("|T=%d|",n);
    printf("|V=%.1lf|",V);
    printf("|S=%.1lf|\n",S);
    V=V+0.1;
    S=S+V;
  }
}
