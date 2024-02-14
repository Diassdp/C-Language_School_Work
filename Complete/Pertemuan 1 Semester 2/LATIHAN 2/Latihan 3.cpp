#include <stdio.h>
int main ()
{
  char grade;
  int sks;
  int angka_mutu= 0;
  printf("program Hitung Angka Mutu");
  printf("\ninput Grade (A, B, C, D, E) : ");
  grade = getchar();
  printf("input SKS : ");scanf("%i",&sks);
  switch(grade)
  {
  case 'A': angka_mutu =4 *sks;break;
  case 'B': angka_mutu =3 *sks;break;
  case 'C': angka_mutu =2 *sks;break;
  case 'D': angka_mutu =1 *sks;break;
  case 'E': angka_mutu =0 *sks;break;
  default : angka_mutu =0;
  }
  printf("\nGrade : %c",grade);
  printf("\nSKS : %i",sks);
  printf("\nAngka Mutu : %i",angka_mutu);
}
