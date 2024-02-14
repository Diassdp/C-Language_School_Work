//Buatlah program membaca matriks a berukuran dan menampilkan elemen terbesar pada setiap barisnya.
//Contoh input :
/*4 4
1 3 2 1
8 4 3 2
1 2 3 4
9 8 7 6
Contoh output:
3 8 4 9*/
#include <stdio.h>
int main()
{
	int i,k,c,r,t;
	printf("Masukan Size Column:");scanf("%d",&c);
	printf("Masukan Size Row:");scanf("%d",&r);
	int A[c][r];
	int max[c];
	
	for(i=0;i<c;i++)
	{for(k=0;k<r;k++){printf("Array[%d][%d]:",i,k);scanf("%d",&A[i][k]);}}
	
	for(i=0;i<c;i++)
	{t=0;for(k=0;k<r;k++){if(A[i][k]>t){t=A[i][k];}}max[i]=t;}
	printf("\nNilai Isi Array:\n");	
	
	for(i=0;i<c;i++)
	{for(k=0;k<r;k++)printf("%d ",A[i][k]);printf("\n");}
	printf("\n Nilai Terbesar dari Semua Column:");
	for(i=0;i<c;i++){printf("%d ",max[i]);}
	
}
