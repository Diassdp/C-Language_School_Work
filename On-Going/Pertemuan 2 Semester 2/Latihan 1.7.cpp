/*Buatlah sebuah program yang mengandung sebuah struct yang menyimpan data buku
berupa:
-kode isbn dengan panjang maksimal 18
-judul buku dengan panjang maksimal 50
-nama penulis buku dengan panjang maksimal 40
-nama penerbit dengan panjang maksimal 25
-jumlah halaman buku
-tahun terbitan buku
-harga buku
Lengkapi titik-titik pada program sehingga menghasilkan program yang bebas error dan
output yang benar */
#include <stdio.h>
#include <string>
typedef struct{
	char isbn[18];
	char judul[50];
	char penulis[40];
	char penerbit[25];
	int halaman;
	int tahun;
	int harga;
}Buku;

void IsiDataBuku(Buku *B)
{
  printf("ISBN\t\t:");fflush(stdin);gets(B->isbn);
  printf("Judul\t\t:");fflush(stdin);gets(B->judul);
  printf("Penulis\t\t:");fflush(stdin);gets(B->penulis);
  printf("Penerbit\t:");fflush(stdin);gets(B->penerbit);
  printf("Halaman\t\t:");scanf("%d",&B->halaman);
  printf("Tahun Terbit\t:");scanf("%d",&B->tahun);
  printf("Harga\t\t:");scanf("%d",&B->harga);
}
void tampilkanDataBuku(Buku B)
{
	printf("%s|%s|%s|%s|%d|%d|%d|",B.isbn,B.judul,B.penulis,B.penerbit,B.halaman,B.tahun,B.harga);
}

int main()
{
Buku B;
IsiDataBuku(&B);
printf("\n");
tampilkanDataBuku(B);
return 0;
}
