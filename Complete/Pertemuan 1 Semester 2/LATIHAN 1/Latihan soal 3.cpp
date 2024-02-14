#include <stdio.h>
#include <string.h>
int main ()
{
  char nim[10];
  char nama[30];
  int usia;
  printf("INPUT DATA MAHASISWA\n");
  printf("NIM : ");scanf("%s",&nim);
  fflush(stdin);
  printf("NAMA : ");
  gets(nama);
  printf("USIA : ");scanf("%d",&usia);
  printf("\nNIM \t: %s",nim);
  printf("\nNAMA \t: %s",nama);
  printf("\nUSIA \t: %d",usia);
}
