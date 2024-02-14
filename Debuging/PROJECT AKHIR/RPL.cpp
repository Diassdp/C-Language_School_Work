#include  <iostream>
#include  <bits/stdc++.h>
#include <iomanip>
#define MAX 60 
//Today Date & Time//  
#define Day 22
#define Month 05 
#define Year 2020
//Costumize Date//

using namespace std;

int main() 
{	
	int Jam;//Int Jam Pengunjugan
	int m, d, y;//Int Day Month Year Birthday
  	char seperator;// Separtor Char
  	char Name[MAX];// String Nama
  	
  	cout << "-\tSistem-Point-of-Sales\t-";
  	cout << "\n-\tDias Syahadatputra\t-";
  	cout << "\n-\tYonathan\t\t-";
  	cout << "\n-\tRayhan Athurahman\t-";
  	cout << "\n-\tTLDR\t-";
  	cout << "\n-\tTLDR\t-";

  	cout << "\nMasukan Nama:";gets(Name);
  	cout << "Masukan  Tanggal Lahir dengan Format DD/MM/YYYY:";
	std::cin >> d;
	std::cin.get();
	std::cin >> m;
	std::cin.get();
	std::cin >> y;
  	cout << "Masukan Berapa Lama Jam Penggunjungan:";cin >> Jam;
  	float harga;
	int n;
  	std::cout << std::fixed;	
	system("CLS");
	
	//Jika Ulang Tahun Kurang kan 3 jam Setiap Loop
  	if (m == Month && d == Day)
  		{
  			cout<<"[Happy Birthday]\nNama:"<<Name<<"\nBirthdate:"<< d << " " << m << " " << y <<"\n[Anda Mendapatkan Discount Sebesar 10.000 Setiap 3 Jam]";
  			int count=0;
  			int n;
  			for (n=0;n<Jam;n++)
  			{
  				count++;
  				if(count==3)//setiap 3 jam bakal dikurang 10.000 
  				{
  					harga=harga-10.000;
  					count=0;
				}
  				//setiap 1 jam nambah 12.500	
  				harga=harga + 12.500;
			}
			if(n>=1)
			{
				//setiap 1 jam nambah 8.000
				harga=harga + 8.000;
			}
		}
	
	else
		{
		cout<<"\nNama:"<<Name<<"\nBirthdate:"<< d << "/" << m << "/" << y;
		for (n=0;n<Jam;n++)
			{
  			//setiap 1 jam nambah 12.500	
  			harga=harga + 12.500;
			}
			if(n>=1)
			{
				//setiap 1 jam nambah 8.000
				harga=harga + 8.000;
			}	
		}
	printf("\n Biaya Total:%.3f",harga);
}
