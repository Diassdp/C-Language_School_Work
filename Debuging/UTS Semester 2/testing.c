#include <stdio.h>
#include <conio.h>
#include <string.h>
int main()
{
//Deklarasikan nama variabel dari nama, keterangan, dan kode serta nilai elemen di dalam char
char nama[50],keterangan[50],kode;
printf("Masukkan nama mahasiswa: "); scanf(" %s",&nama);
printf("Pilih kode Program Studi [A/B/C/D] :");
kode=getche();
switch(kode)
  {
case 'A':
strcpy(keterangan,"Program Studi Teknik Perkapalan"); break;
case 'B':
strcpy(keterangan,"Program Studi Teknik Industri");
break;
case 'C':
strcpy(keterangan,"Program Studi Teknik Mesin");
break;
case 'D':
strcpy(keterangan,"Program Studi Teknik Elektro");
break;
case 'a':
strcpy(keterangan,"Program Studi Teknik Perkapalan"); break;
case 'b':
strcpy(keterangan,"Program Studi Teknik Industri");
break;
case 'c':
strcpy(keterangan,"Program Studi Teknik Mesin");
break;
case 'd':
strcpy(keterangan,"Program Studi Teknik Elektro");
break;
default:
strcpy(keterangan,"Program Studi Tidak Ditemukan");
break;
    }
printf("\n\nNama Mahasiswa: %s \n",nama);
 printf("Kode Program Studi: %c \n",kode);
  printf("Nama Program Studi: %s\n",keterangan);
getch(); 
return 0;
}
