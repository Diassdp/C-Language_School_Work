#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct//Isi Value /Kontainer/
{
	char nim[10];
	char nama[50];
	char nilai[2];
	
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

void addFirst(char nim[],char nama[],char nilai[],list *L)
{
	elemen *baru;
	baru=(elemen *)malloc(sizeof(elemen));
	//Insert Data into Value
	strcpy(baru->kontainer.nim,nim);
	strcpy(baru->kontainer.nama,nama);
	strcpy(baru->kontainer.nilai,nilai);
	//
	if((*L).first==NULL)
	{
		baru->next=NULL;
	}
	else
	{
		baru->next=(*L).first;
	}
	(*L).first=baru;
	baru=NULL;
}


void addAfter(elemen *prev,char nim[],char nama[],char nilai[],list *L)
{
	if(prev!=NULL)
	{
		elemen *baru;
		baru=(elemen *)malloc(sizeof(elemen));
		//Insert Data into Value
		strcpy(baru->kontainer.nim,nim);
		strcpy(baru->kontainer.nama,nama);
		strcpy(baru->kontainer.nilai,nilai);
		//
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
void addLast(char nim[],char nama[],char nilai[],list *L)
{
	if((*L).first==NULL)//Jika List Kosong
	{
		addFirst(nim,nama,nilai,L);
	}
	else
	{
		//jika list  tidak kosong akan //Mencari Element terakhir List
		elemen *last=(*L).first;
		while(last->next !=NULL)
		{
			last = last->next;
		}
		addAfter(last,nim,nama,nilai,L);
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
void delafter(elemen *prev)
{
	if(prev !=NULL)
	{
	}
}

void printElement(list L)
{
	if(L.first !=NULL)//jika list tidak kosong
	{
		elemen *bantu =L.first;
		int i=1;
		while (bantu !=NULL)
		{
			//proses print//
			printf("===================================\n");
			printf("Elemen Ke-%d",i);
			printf("nim\t: %s\n",bantu->kontainer.nim);
			printf("nim\t: %s\n",bantu->kontainer.nama);
			printf("nim\t: %s\n",bantu->kontainer.nilai);
			printf("===================================\n");
			bantu=bantu->next;
			i++;
		}	
	}
	else//jika list Kosong
	{
		printf("Kontainer Kosong");
	}
}

int main ()
{
	list L;
	return 0;
}

