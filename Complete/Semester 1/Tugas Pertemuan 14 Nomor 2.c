#include <stdio.h>
#include <stdlib.h> 
void main ()
{
	int N,i,count_genap,count_ganjil;
  	printf("Masukan Size array:");scanf("%d",&N);
  	int A[N],found[N];
  	for(i=0;i<N;i++)
  	{A[i]=(rand()%50);}
  	printf("INPUT:");
	for(i=0;i<N;i++)
	{printf("[%d]",A[i]);}
	count_genap=0;
	count_ganjil=0;
  	for(i=0;i<N;i++)
  	{
    	if(A[i]%2==0)
    	{count_genap++;found[i]=1;}
   	 	else
    	{count_ganjil++;found[i]=0;}
  	}
  	printf("\nOUTPUT:\n");
  	printf("\n[GENAP][%d]:",count_genap);
  	if(count_genap==0)
  		{printf("Tidak Ada Angka Genap");}
  	else
  	for(i=0;i<N;i++)
  	{
	  if(found[i]==1)
		{printf("[%d]",A[i]);}
	  }
	  
  	printf("\n[GANJIL][%d]:",count_ganjil);
  	if(count_ganjil==0)
  		{printf("Tidak Ada Angka Ganjil");}
  	else
  	for(i=0;i<N;i++)
  	if(found[i]==0)
		{printf("[%d]",A[i]);}
}
