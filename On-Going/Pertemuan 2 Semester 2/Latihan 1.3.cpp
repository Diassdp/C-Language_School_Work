//Pak Dengklek menyelenggarakan ujian harian setelah selesai mengajarkan N ekor beberk mengenai konsep array. Setiap bebek ke-I mendapat nilai sebesar hi yang merupakan bilangan bulat. Untuk menentukan lulus, nilai bebek tersebut tidak kurang dari nilai rata-rata dari seluruh bebek. Tentukan banyaknya bebek yang lulus ujian!. Batasan : (1<=N<=100 ; 1<=hi<=100 ; 1<=i<=N). Masukkan berupa dua baris. Baris pertama berisi sebuah bilangan bulat N. Bari kedua berisi nilai ujian bebek. Baris kedua ini merupakan hi . Keluarannya berupa sebuah baris yang menyatakan banyaknya bebek yang lulus ujian.
//Contoh input : 3 
              //5 6 7
//Contoh ouput : 2
#include <stdio.h>
#include <math.h>
int main()
{
  //n jumlah bebek//
  //hi nilai bebek//
	int n,i,Nilai_rata=0,sum=0,count=0;
	printf("Masukan N:");scanf("%d",&n);
	int a[n];
  for(i=0;i<n;i++)
  {printf("Masukan Nilai bebek ke-%d:",i+1);scanf("%d",&a[i]);}
  for(i=0;i<n;i++)
  {sum=sum+a[i];}
  Nilai_rata=sum/n;
  count=0;
  for(i=0;i<n;i++)
  {if(a[i]>=Nilai_rata){count++;}}
  printf("Nilai  Rata-rata:[%d]",Nilai_rata);
  printf("\nBebek Yang Lulus:[%d]",count);
}

