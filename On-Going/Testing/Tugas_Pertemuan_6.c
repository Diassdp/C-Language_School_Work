#include <stdio.h>
#include <stdlib.h>
typedef struct//Isi Value /Kontainer/
{
	int inter;
}inter;

typedef struct elmt *alamatelmt;//Alamat Element

typedef struct elmt//Element List
{
	inter kontainer;
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

void addFirst(int inter,list *L)
{
	elemen *baru;
	baru=(elemen *)malloc(sizeof(elemen));
	//Insert Data into Value
	baru->kontainer.inter=inter;
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


void addAfter(elemen *prev,int inter,list *L)
{
	if(prev!=NULL)
	{
		elemen *baru;
		baru=(elemen *)malloc(sizeof(elemen));
		//Insert Data into Value
		baru->kontainer.inter=inter;
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
void addLast(int inter,list *L)
{
	if((*L).first==NULL)//Jika List Kosong
	{
		addFirst(inter,L);
	}
	else
	{
		//jika list  tidak kosong akan //Mencari Element terakhir List
		elemen *last=(*L).first;
		while(last->next !=NULL)
		{
			last = last->next;
		}
		addAfter(last,inter,L);
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
			printf("inter\t: %i\n",bantu->kontainer.inter);
			printf("===================================\n");
			bantu=bantu->next;
			i++;
		}	
	}
	else//jika list Kosong
	{printf("Kontainer Kosong");}
}
void swap(list *a,list *b)
{

}

void bubbleSort(list *L)
{
	if((*L).first!=NULL)
	{
		elemen *bantu =(*L).first;
		while(bantu!=NULL)
		{
			if()
			bantu=bantu->next;
		}
	}

}

int main ()
{
	list L;
	CreateList(&L);
	addFirst(3,&L);addFirst(4,&L);addFirst(1,&L);
	printElement(L);
	bubbleSort(&L);
	printf("\nAfter Sort\n");
	printElement(L);
	
	return 0;
}


