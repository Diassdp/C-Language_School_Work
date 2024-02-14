#include <stdio.h>
#include <math.h>
int main ()
{
	double A,B,C;
	printf("Masukan Panjang Sisi Alas : ");scanf("%lf",&A);
	printf("Masukan Sisi Tinggi : ");scanf("%lf",&B);
	C=sqrt((A*A)*(B*B));
	printf("Sisi Miring Segitiga \t: %.0lf",C);
}
