#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void printArray(char Array[], int size)// Function to print the array//
{
	int i;
	for (i=0; i < size; i++)
	{printf("%c", Array[i]);}
	printf("\n");
}
void search(char Array[], int size,char x)
{
	int i,j,count_vokal=0,count_konsonan=0,count_numerik=0,count_search=0;
	int trueorfalse[size];
	
	for (i=0;i<size;i++)
	{
		if(Array[i]==x||Array[i]==toupper(x))
		{count_search++;}
		if(Array[i]=='a'||Array[i]=='e'||Array[i]=='i'||Array[i]=='o'||Array[i]=='u'||Array[i]=='A'||Array[i]=='E'||Array[i]=='I'||Array[i]=='O'||Array[i]=='U')
		{count_vokal++;trueorfalse[i]=1;}
		else if(Array[i]!=' '&&isalpha(Array[i]))
		{count_konsonan++;trueorfalse[i]=0;}
		else if(isdigit(Array[i]))
		{count_numerik++;}
	}
	
	printf("\nVokal:[%d]:",count_vokal);
	if(count_vokal==0)
	{printf("Tidak ada Vokal");}
	else
	for (i=0;i<size;i++)
	{
	if(trueorfalse[i]==1&&Array[i]!=' ')
	{printf("%c ",Array[i]);}
	}
	
	printf("\nKonsonan:[%d]:",count_konsonan);
	if(count_konsonan==0)
	{printf("Tidak ada Konsonan");}
	else
	for (i=0;i<size;i++)
	{
	if(trueorfalse[i]==0&&Array[i]!=' '&&isalpha(Array[i]))
	{printf("%c ",Array[i]);}
	}
	
	printf("\nNumerik:[%d]:",count_numerik);
	if(count_numerik==0)
	{printf("Tidak Ada Numerik");}
	else
	for (i=0;i<size;i++)
	{
	if(isdigit(Array[i]))
	{printf("%c ",Array[i]);}
	}
	
	printf("\nSearch:[%d]:",count_search);
	if(count_search==0)
	{printf("Tidak Ada Search");}
	else
	for (i=0;i<size;i++)
	{
		if(Array[i]==x||Array[i]==toupper(x))
		{printf("[%c]",Array[i]);}
		else
		{printf("%c",Array[i]);}
	}
}
void main ()
{
	int i,x;
	char string[]="Nama Saya Dias";//input//
	int n = sizeof(string)-1;
	printf("Data Yang Dicari:");scanf("%c",&x);
	printf("INPUT:");
	printArray(string,n);
	printf("OUTPUTS:");
	search(string,n,x);
}	



