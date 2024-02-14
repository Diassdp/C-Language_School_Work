#include <stdio.h>
int main ()
{
	int	diameter,jari;
	float pi=3.14,Volume;
	printf("MASUKAN DIAMETER BOLA : ");scanf("%d",&diameter);
	jari=diameter/2;
	Volume=(4*3.14*jari*jari*jari)/3;
	printf("VOLUME BOLA \t: %.2f",Volume);
}

