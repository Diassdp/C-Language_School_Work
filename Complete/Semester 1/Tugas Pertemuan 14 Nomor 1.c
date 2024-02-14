#include <stdio.h>
#include <stdlib.h> 
void main() 
{
  int N,i,x,count;
  printf("Masukan Size array:");scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++)
  {printf("Masukan Angka untuk kolom ke-%d:",i+1);scanf("%d",&A[i]);}
  printf("Masukan Angka Yang dicari:");scanf("%d",&x);
  count=0;
  int found[N];
  for(i=0;i<N;i++)
  {
    if(A[i]==x)
    {count=count+1;found[i]=1;}
    else
    {found[i]=0;}
  }
   for(i=0;i<N;i++)
  {printf("[%d]",A[i]);}
  printf("\n Angka yang di cari [%d] \nTotal ada:[%d]",x,count);
  printf("\nLokasi Kolom:");
  for(i=0;i<N;i++)
  {if(found[i]==1){printf("\nkolom ke-%d",i+1);}}
}
