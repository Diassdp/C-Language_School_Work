//Buatlah sebuah program bahasa C untuk menginput 10 bilangan bulat yang menyatakan nilai mahasiswa ke dalam sebuah array yang berisi 10 buah elemen. Selanjutnya cetak daftar nilai mahasiswa yang lulus (nilai>=60).
#include <stdio.h>
#include <string>
int main ()
{
	int i,N;
	printf("MASUKAN BERAPA BANYAK MAHASISWA YANG INGIN DI INPUT:");scanf("%d",&N);
	struct mahasiswa 
	{
		int nilai;
		char nama[30];
		char nim[110];
	};
	struct mahasiswa mhs[N];
	printf("[DATA MAHASISWA]\n");
	for(i=0;i<N;i++)
	{
	printf("MAHASISWA %i\n",i+1);
	printf("NAMA:");fflush(stdin);gets(mhs[i].nama);
	printf("NIM:");scanf("%s",&mhs[i].nim);
	printf("NILAI:");scanf("%i",&mhs[i].nilai);
	printf("\n");
	}
	for(i=0;i<N;i++)
	{
		if(mhs[i].nilai>=60)
		{	
		printf("\nMAHASISWA %i",i+1);
		printf("\nNAMA:[%s]",mhs[i].nama);
		printf("\nNIM:[%s]",mhs[i].nim);
		printf("\nNILAI:[%i]",mhs[i].nilai);
		printf("\nSTATUS:[LULUS]\n");
		}
		else
		{
		printf("\nMAHASISWA %i",i+1);
		printf("\nNAMA:[%s]",mhs[i].nama);
		printf("\nNIM:[%s]",mhs[i].nim);
		printf("\nNILAI:[%i]",mhs[i].nilai);
		printf("\nSTATUS:[TIDAK LULUS]\n");
		}	
	}
	
}


