#include <stdio.h>
#include <stdlib.h>

int matrix[20][20];

void displaymatrix(int v)
{
	int i,j;
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			printf("[%d]",matrix[i][j]);
		}
		printf("\n");
	}
}

void edge(int u,int v)
{
	matrix[u][v]=1;
}

int main()
{
	int i,j,n,m,Awal,Tujuan;
	printf("Masukan Jumlah Simpul:");scanf("%d",&n);
	printf("Masukan Jumlah Sisi:");scanf("%d",&m);
	
	//Inisialisai Matrix
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			matrix[i][j]=0;
			matrix[j][i]=0;
		}
	}
	
	//Connection
	for(j=1;j<=m;j++)
	{
		printf("Masukan Simpul Asal:");scanf("%d",&Awal);
		printf("Masukan Simpul Tujuan:");scanf("%d",&Tujuan);
		edge(Awal,Tujuan);
	}
	displaymatrix(n);
}
