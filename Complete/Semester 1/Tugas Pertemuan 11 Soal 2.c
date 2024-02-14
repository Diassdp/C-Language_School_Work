#include <stdio.h>
#include <stdlib.h>
void Choice_A()
{
	int i,N,j,P;
	printf("Masukan Jumlah Array=");scanf("%d",&N);
	char A[N];//array A yg belum di definisi
	for (i=1;i<=N;i++)
	{printf("Masukan interger= ");scanf("%d",&A[i]);}
	for (i=1;i<=N;i++)
	{
		for(j=N;j>=1;j--)
		if(i!=j&&A[i]==A[j])
			{printf("\n interger dari baris array ke [%d]sama dengan baris ke[%d] Dengan interger %d",i,j,A[i]);P=1;}
		else continue;
	}
	if(P==1)
	{printf("ADA INTERGER YANG SAMA DALAM ARRAY");}
	else
	{printf("TIDAK ADA INTERGER YANG SAMA DALAM ARRAY");}
}
void Choice_B()
{
	int i,N,j,P;
	char A[10]={12,3,3,4,5,6,7,12,9,10};//Array A yg Di Definisi//Boleh Diganti
	printf("Menggunakan Element A yang sudah di definisi");
	for (i=1;i<=10;i++)
	{
		for(j=10;j>=1;j--)
		if(i!=j&&A[i]==A[j])
			{printf("\n interger dari baris array ke [%d]sama dengan baris ke[%d] Dengan interger %d",i,j,A[i]);P=1;}
		else continue;
	}
	if(P==1)
	{printf("\nADA INTERGER YANG SAMA DALAM ARRAY");}
	else
	{printf("\nTIDAK ADA INTERGER YANG SAMA DALAM ARRAY");}
}
void main ()
{
	int choice;
	printf("1.Masukan Element sendiri\n2.Menggunakan Element A yang sudah di definisi\n");
	printf("Masukan Pilihan dengan memasukan int 1 atau 2\nMasukan Interger=");scanf("%d",&choice);
	switch(choice)
	{case 1:Choice_A();break;case 2 :Choice_B();break;}
}
