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
	if((*L).first==NULL)
	{baru->next=NULL;}
	else
	{baru->next=(*L).first;}
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

void printElement(list L)
{
	if(L.first !=NULL)//jika list tidak kosong
	{
		elemen *bantu =L.first;
		int i=1;
		while (bantu !=NULL)
		{//proses print//
			printf("===================================\n");
			printf("Elemen Ke-%d\n",i);
			printf("nim\t: %s\n",bantu->kontainer.nim);
			printf("nim\t: %s\n",bantu->kontainer.nama);
			printf("nim\t: %s\n",bantu->kontainer.nilai);
			printf("===================================\n");
			bantu=bantu->next;
			i++;
		}	
	}
	else//jika list Kosong
	{printf("Kontainer Kosong");}
}

int main ()
{
	list L;
	CreateList(&L);
	printElement(L);
	printf("\n===========================\n");
	addFirst("123","Nana","A",&L);
	addFirst("125","Adrezo","A",&L);
	addAfter(L.first->next,"135","Iza","A",&L);
	addLast("137","Rara","A",&L);
	printElement(L);
	printf("\n===========================\n");
	delLast(&L);
	delAfter(L.first->next);
	delFirst(&L);
	printElement(L);
	printf("\n===========================\n");
	return 0;
}



