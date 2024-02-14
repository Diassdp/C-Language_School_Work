#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int menu, Golongan,Gaji_Pokok,Gaji_Per_Jam,Total_Gaji, Masa_Lembur,Total_Gaji_Lembur;
    char Ulang;
    do
	{
        printf("Menentukan Lembur dan Total Gaji\n");
        printf("Karyawan Golongan 1\n");
        printf("Karyawan Golongan 2\n");
        printf("Karyawan Golongan 3\n");


        printf("Pilih Nomor Menu: ");
        scanf("%d", &Golongan);
		switch(Golongan){
		case 1:
		printf("Masukan Lama Lembur (Jam) : ");
		scanf("%d",&Masa_Lembur);
		Gaji_Pokok = 100000;
		Gaji_Per_Jam = 20000;
		Total_Gaji_Lembur = Gaji_Per_Jam*Masa_Lembur;
		printf("Gaji Anda sebagai : Karyawan Golongan 1 adalah Rp%d + Rp%d = Rp%d\n",Gaji_Pokok,Total_Gaji_Lembur,Total_Gaji_Lembur+Gaji_Pokok);break;
 case 2:
    printf("Masukan Lama Lembur (Jam) : ");
scanf("%d",&Masa_Lembur);
 Gaji_Pokok = 150000;
 Gaji_Per_Jam = 20000;
 Total_Gaji_Lembur = Gaji_Per_Jam*Masa_Lembur;
 printf("Gaji Anda sebagai : Karyawan Golongan 2 adalah Rp%d + Rp%d = Rp%d\n",Gaji_Pokok,Total_Gaji_Lembur,Total_Gaji_Lembur+Gaji_Pokok);
 break;
 case 3:
    printf("Masukan Lama Lembur (Jam) : ");
scanf("%d",&Masa_Lembur);
 Gaji_Pokok = 200000;
 Gaji_Per_Jam = 20000;
 Total_Gaji_Lembur = Gaji_Per_Jam*Masa_Lembur;
 printf("Gaji Anda sebagai : Karyawan Golongan 3 adalah Rp%d + Rp%d = Rp%d\n",Gaji_Pokok,Total_Gaji_Lembur,Total_Gaji_Lembur+Gaji_Pokok);
 break;
}
 Ulang=getch();
 }while(Ulang=='y');
 }
