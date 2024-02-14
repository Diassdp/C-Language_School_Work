/*
Buatlah program untuk membuat matriks simetris berukuran n×n, seluruh elemen pada
diagonal sekunder (kanan atas ke kiri bawah) adalah n, dan elemen-elemen di bawah dan atasnya
adalah n-1, n-2, … , 1.
Contoh input:
5
Contoh ouput :
1 2 3 4 5
2 3 4 5 4
3 4 5 4 3
4 5 4 3 2
5 4 3 2 1
*/
#include <stdio.h>
int main()
{
	int n,i,k,c,j;
	printf("INPUT N:");scanf("%d",&n);
	int a[n][n];

	for(i=0;i<n;i++)
	{
		for(k=0;k<n;k++)	
		{
			if((i+k+1)<=n)
			{a[i][k]=i+k+1;}
			else
			{a[k][i]=1-k-i+n+3;}
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
	{for(k=0;k<n;k++){printf("%d ",a[i][k]);}printf("\n");}
}
