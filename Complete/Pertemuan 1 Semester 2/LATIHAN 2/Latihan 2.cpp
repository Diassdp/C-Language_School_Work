#include <stdio.h>
#include <string.h>
int main ()
{
  char NIP[20],nama[100];
  int Golongan,hours;
  float Gaji;
  printf("[PERUSHAAN PT.ABC]\t\n");
  fflush(stdin);
  printf("NAMA PEGAWAI\t: ");gets(nama);
  printf("NIP(Nomor Induk Pegawai)\t: ");scanf("%s",&NIP);
  printf("Berapa Jam Bekerja\t: ");scanf("%d",&hours);
  printf("[Gologan Perkerjaan]\t\n1.Gologan Kerja 1\n2.Gologan Kerja 2\n3.Gologan Kerja 3\n");
  printf("Gologangan Kerja \t: ");scanf("%d",&Golongan);
  
  switch(Golongan)
  {
    case 1://Golongan 1
    printf("\n[DATA PEGAWAI GOLONGAN 1]\n");
    printf("Nama\t:%s\n",nama);
    printf("NIP(Nomor Induk Pegawai)\t:%s\n",NIP);
    printf("Waktu Lembur\t:%d Jam\n",hours-48);
    Gaji=100.000+20.000*(hours-48);
    printf("Total Gaji\t:Rp.%.3f",Gaji);break;
    
    case 2://Golongan 2
    printf("\n[DATA PEGAWAI GOLONGAN 2]\n");
    printf("Nama\t:%s\n",nama);
    printf("NIP(Nomor Induk Pegawai)\t:%s\n",NIP);
    printf("Waktu Lembur\t:%d Jam\n",hours-48);
    Gaji=150.000+20.000*(hours-48);
    printf("Total Gaji\t:Rp.%.3f",Gaji);break;
    
    case 3://Golongan 3
    printf("\n[DATA PEGAWAI GOLONGAN 3]\n");
    printf("Nama\t:%s\n",nama);
    printf("NIP(Nomor Induk Pegawai)\t:%s\n",NIP);
    printf("Waktu Lembur\t:%d Jam\n",hours-48);
    Gaji=200.000+20.000*(hours-48);
    printf("Total Gaji\t:Rp.%.3f",Gaji);
    
    default:printf("Invalid Golongan");break;
  }
} 
