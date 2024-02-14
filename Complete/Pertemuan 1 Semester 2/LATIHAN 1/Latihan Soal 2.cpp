#include <stdio.h>
#include <string.h>
int main ()
{
  char nim[10];
  char nama[30];
  int tugas,kehadiran,uts,uas;
  float nilai_akhir;
  //Data Mahasiswa//
  strcpy(nim,"0902040");
  strcpy(nama,"Mirna Suminar");
  kehadiran=100;
  tugas=90;
  uts=83;
  uas=86;
  /*Perhitungan nilai Akhir*/
  nilai_akhir=((0.1*kehadiran)+(0.2*tugas)+(0.3*uts)+(0.4*uas));
  //tampilkan data printf("\nNIM \t: %s",nim);
  printf("\nNAMA \t: %s",nama);
  printf("\nNILAI TUGAS \t:%i",tugas);
  printf("\nNILAI UTS \t: %i",uts);
  printf("\nNILAI UAS \t: %i",uas);
  printf("\nNILAI AKHIR \t: %.2f",nilai_akhir);
}
