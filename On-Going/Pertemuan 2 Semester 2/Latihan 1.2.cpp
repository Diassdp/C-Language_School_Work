//Buatlah sebuah program menggunakan array untuk mencari nilai maksimum dan minimum pada array tersebut. Jumlah data tidak lebih dari 100. Proses masukkan nilai pada array diulang sampai nilai yang dimasukkan kurang dari 0 atau lebih dari 100. Proses mencari nilai maksimum dan minimum menggunakan fungsi sendiri.
//Contoh input : 1 2 3 4 5 -1 Contoh 
//output : Maksimum = 5 Minimum = 1
#include<stdio.h>
void maksimal(int arr[],int n)
{
  int i;
  int max=0;
  for(i=0;i<n;i++)
  {
    if(arr[i]>max&&arr[i]<=100)
    {max=arr[i];}
  }
  printf("\nMAKSIMUM:[%d]",max);
}
void minimal(int arr[],int n,int min)
{
  int i;
  for(i=0;i<n;i++)
  {if(arr[i]<min&&arr[i]>=0){min=arr[i];}}
  printf("\nMINIMAL:[%d]",min);
}

int main()
{
	int i,min,c;
	int arr[100];
  	for(i=0;i<100;i++)
 	{printf("DATA ARRAY %d:",i+1);scanf("%d",&arr[i]);if(arr[i]>=100||arr[i]<=0)break;c++;}
 	int n = sizeof(arr)/sizeof(arr[0]);
  	min=arr[0];
 	maksimal(arr,c);
  	minimal(arr,c,min);
 	return 0;
}
