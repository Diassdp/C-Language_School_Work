#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//NAMA:DIAS SYAHADATPUTRA//
//NIM:2110512154//
//KELAS D//

//Algorithma Logic//
/*Menggunakan dua list untuk menampung dua jenis antrian dengan menggunakan 2 list pemishan kedua jenis anrian lebih gampang dan tidak memkanbayak complexsitas dengan demikian menurunkan beban di mesin*/
//Trial pertama saya menggunakan cara search tetapi membebebankan mesin dengan demikian program ngestall dengan demikian saya menggunakan cara 2 list tersebut dengan logica 2 jenis antrian//

typedef struct//Isi Value /Kontainer/
{
	char nama[50];
	char tujuan[20];
}nilai;
typedef struct elmt *alamatelmt;//Alamat Element
typedef struct elmt//Element List
{
	nilai kontainer;
	alamatelmt next;
}elemen;
typedef struct 
{
	elemen *first;
}list;

void CreateList(list *L)
{
	(*L).first=NULL;
}

int countElement(list L)
{
	int hasil=0;
	if(L.first != NULL)//list tidak kosong
	{
		//inisialisasi
		elemen *bantu;
		bantu=L.first;
		while(bantu !=NULL)
		{
			hasil=hasil + 1;
			bantu=bantu->next;
		}
	}
	return hasil;
}

void addFirst(char nama[],char tujuan[],list *L)
{
	elemen *baru;
	baru=(elemen *)malloc(sizeof(elemen));
	//Insert Data into Value
	strcpy(baru->kontainer.nama,nama);
	strcpy(baru->kontainer.tujuan,tujuan);
	if((*L).first==NULL)
	{baru->next=NULL;}
	else
	{baru->next=(*L).first;}
	(*L).first=baru;
	baru=NULL;
}

void addAfter(elemen *prev,char nama[],char tujuan[],list *L)
{
	if(prev!=NULL)
	{
		elemen *baru;
		baru=(elemen *)malloc(sizeof(elemen));
		//Insert Data into Value
		strcpy(baru->kontainer.nama,nama);
		strcpy(baru->kontainer.tujuan,tujuan);		
		if(prev->next==NULL)
		{
			baru->next=NULL;
		}
		else
		{
			baru->next=prev->next;
		}
		prev->next = baru;
		baru=NULL;
	}
}
//NAMA:DIAS SYAHADATPUTRA//
//NIM:2110512154//
//KELAS D//
void Enqueue(char nama[],char tujuan[],list *L)
{
	if((*L).first==NULL)//Jika List Kosong
	{
		addFirst(nama,tujuan,L);
	}
	else
	{
		//jika list  tidak kosong akan //Mencari Element terakhir List
		elemen *last=(*L).first;
		while(last->next !=NULL)
		{
			last = last->next;
		}
		addAfter(last,nama,tujuan,L);
	}
}

void delFirst(list *L)
{
	if((*L).first !=NULL)//jika list tidak kosong//
	{
		elemen *hapus=(*L).first;
		if(countElement(*L)==1)
		{
			(*L).first=NULL;
		}
		else
		{
			(*L).first=(*L).first->next;
		}
		hapus->next=NULL;
		free(hapus);
	}
	else//jika list kosong//
	{
		printf("List Kosong\n");
	}
}

void delAfter(elemen *prev)
{
	if(prev !=NULL)//jika list tidak kosong//
	{
		elemen *hapus = prev->next;
		if(hapus !=NULL)
		{
			if(hapus->next==NULL)
			{
				prev->next = NULL;
			}
			else
			{
				prev->next=hapus->next;
			}
			hapus->next=NULL;
			free(hapus);
		}
	}
}

void delLast(list *L)
{
	if((*L).first !=NULL)//jika list tidak kosong//
	{
		if(countElement(*L)==1)
		{
			delFirst(L);
		}
		else
		{
			elemen *last=(*L).first;
			elemen *before_last;
			while(last->next !=NULL)
			{
				before_last=last;
				last=last->next;
			}
			delAfter(before_last);
		}
	}
}

void delAll(list *L)
{
	if(countElement(*L)!=0)
	{
		int i;
		for(i=countElement(*L);i>=1;-i--)
		{delLast(L);}
	}
}

void printElementTeller(list L)
{
	if(L.first !=NULL)//jika list tidak kosong
	{
		int i,c,d;
		elemen *bantu =L.first;
		i=0;
		printf("-----------isi Antrian Teller-----------\n");
		while (bantu !=NULL)
		{
				{
				printf("=====================================\n");
				printf("Elemen Ke-%d\n",i);
				printf("nama\t: %s\n",bantu->kontainer.nama);
				printf("=====================================\n");
				bantu=bantu->next;
				i++;
				}
		}
		printf("--------------------------------------\n");
	}
	else//jika list Kosong
	{printf("--------------------------------------\n");printf("isi Antrian Teller Kosong\n");printf("--------------------------------------\n");}
}

void printElementCS(list L)
{
	if(L.first !=NULL)//jika list tidak kosong
	{
		int i;
		elemen *bantu =L.first;
		i=0;
		printf("-----------isi Antrian CS-----------\n");
		while (bantu !=NULL)
		{
				{
				printf("===================================\n");
				printf("Elemen Ke-%d\n",i);
				printf("nama\t: %s\n",bantu->kontainer.nama);
				printf("===================================\n");
				bantu=bantu->next;
				i++;
				}
		}
		printf("--------------------------------------\n");
	}
	else//jika list Kosong
	{printf("--------------------------------------\n");printf("isi Antrian CS Kosong\n");printf("--------------------------------------\n");}
}

int main ()
{
	list teller;
	list cs;
	char nama[50];char choice;char tujuan[20];int pilihan;
	CreateList(&teller);//list untuk menampung antrian tller
	CreateList(&cs);//list untuk menampung antrian cs
	printf("===================================\n");
	printf("= NAMA\t:DIAS SYAHADATPUTRA\t  =\n");
	printf("= NAMA\t:2110512154\t\t  =\n");
	printf("= KELAS\t:D\t\t\t  =\n");
	printf("===================================\n\n");
	while(1)
	{
		printf("\n===========================\n");
		printf("=  PROGRAM ANTREAN BANK   =\n");
		printf("===========================\n");
		printf("= 1.AMBIL ANTREAN\n");
		printf("= 2.TAMPIL ANTREAN\n");
		printf("= 3.EXIT\n");
		printf("===========================\n");
		printf("Masukan Pilihan:");scanf("%d",&pilihan);
		switch(pilihan)
		{
			case 1://Untuk Masukan antrian
			{
				printf("Masukan Nama Nasabah : ");fflush(stdin);gets(nama);
				printf("Masuk Tujuan(A.Teller B.CS): ");scanf("%c",&choice);
				if (choice=='a'||choice=='A')
						{Enqueue(nama,"Teller",&teller);}
					if (choice=='b'||choice=='B')
						{Enqueue(nama,"CS",&cs);}
			}
			break;
			case 2://Untuk Print antrian
			{
			printElementTeller(teller);
			printElementCS(cs);
			break;
			}
			case 3://Untuk Exit Menu
			exit(0);break;	
			default:printf("pilihan tidak ada dalam Pilihan\n");break;	
		}
	}
	return 0;
}
//NAMA:DIAS SYAHADATPUTRA//
//NIM:2110512154//
//KELAS D//
