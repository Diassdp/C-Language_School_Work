/*Buatlah sebuah program yang mengandung sebuah struct yang menyimpan data tanggal
hari ini (tanggal, bulan, tahun). Buat variabel elemen bulan sebagai sebuah enumerasi. Gunakan
sebuah fungsi bernama cetak_tanggal yang digunakan untuk mencetak tanggal yang telah
diinputkan.
Contoh input :
Masukkan tanggal hari ini : 26-11-2018
Contoh output:
Hari ini adalah 26 November 2018.*/
#include <stdio.h>
#include <string>
int main ()
{
	int i;
	
	struct Calender
	{
	int tanggal;
	char Bulan[12][50]={"Januari","Februari","Maret","April","Mei","Juni","Juli","Agustus","September","Oktober","November","Desember"};
	int tahun;
	}tgl;
	printf("Masukan Tanggal hari ini:");scanf("%d-%d-%d",&tgl.tanggal,&i,&tgl.tahun);
	printf("Hari ini adalah %d %s %d",tgl.tanggal,tgl.Bulan[i-1],tgl.tahun);
	}
