#include <stdio.h>
#include <stdlib.h>
void Choice_A()
{
	int i,N,j=N;
	printf("Masukan Element sendiri\n");
	printf("Masukan Jumlah Array=");scanf("%d",&N);
	char A[N];
	for (i=1;i<=N;i++)
	{printf("Masukan Char= ");scanf(" %c",&A[i]);}
	printf("\nBefore Swap\n");
	for (i=1;i<=10;i++)
	{printf("%c",A[i]);}
	printf("\nAfter Swap\n");
	for (i=10;i>=1;i--)
	{printf("%c",A[i]);}
}
void Choice_B()
{
	int i;
	char A[10]={'A','B','C','D','E','F','G','H','I','J'};
	printf("Menggunakan Element A yang sudah di definisi");
	printf("\nBefore Swap\n");
	for (i=0;i<=10;i++)
	{printf("%c",A[i]);}
	printf("\nAfter Swap\n");
	for (i=10;i>=0;i--)
	{printf("%c",A[i]);}
}
int main ()
{
	int choice;
	printf("1.Masukan Element sendiri\n2.Menggunakan Element A yang sudah di definisi\n");
	printf("Masukan Pilihan dengan memasukan int 1 atau 2\nMasukan Interger=");scanf("%d",&choice);
	switch(choice)
	{case 1:Choice_A();break;case 2 :Choice_B();break;}
}
