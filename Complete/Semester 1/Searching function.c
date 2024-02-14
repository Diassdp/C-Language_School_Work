#include <stdio.h>
#include <stdlib.h> 

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(int Array[],int N)
{
    int i, j;
    for (i = 0; i < N-1; i++)
	{
        for (j = 0; j < N-i-1; j++)
		{
            if (Array[j] < Array[j+1])
			{swap(&Array[j], &Array[j+1]);}
        }
    }
}
void search(int Array[],int N,int x)
{
	int i,found;	
	while(i==N)
	{
		if (Array[i]==x)
		{found+1;}
	}
	print("%d",&found);
}
void main()
{
	int i,N,x;
	printf("Masukan Size Array:");scanf("%d",N);
	int Array[N];
	for (i=0;i<N;i++)
	{printf("Masukan Angka Untuk Array %d:",i+1);scanf("%d",&Array[i]);}
	bubbleSort(Array,N);
	printf("Search for: ");scanf("%d",&x);
}


