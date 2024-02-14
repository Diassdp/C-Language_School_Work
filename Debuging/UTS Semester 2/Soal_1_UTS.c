#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//NAMA:DIAS SYAHADATPUTRA//
//NIM:2110512154//
//KELAS D//
//Algorithma Logic//
/* Logica yang digunakan akan adalah dengan bentuk stack yang mirip dengan list dengan menggunakan addfirst() sebagai push() dan menggunakan delfirst() sebagai pop() dengan demikian kita dapat persamakan list dengan stack */
//dan juga dengan bentuknya printtop() adalah untuk print stack yang top dan printstack() sebagai print seluruh stack dengan logika nya stack dan list tidak make limit

typedef struct
{
	char nim[11];
	char nama[50];
	float nilai;
}nilaimatkul;
typedef struct elmt *alamatelmt;//Alamat Element
typedef struct elmt//Element List
{
	nilaimatkul kontainer;
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
void push(char nim[],char nama[],float nilai,list *L)
{
	elemen *baru;
	baru=(elemen *)malloc(sizeof(elemen));
	strcpy(baru->kontainer.nim,nim);
	strcpy(baru->kontainer.nama,nama);
	baru->kontainer.nilai=nilai;
	if((*L).first==NULL)
	{baru->next=NULL;}
	else
	{baru->next=(*L).first;}
	(*L).first=baru;
	baru=NULL;
}

int countElement(list L)
{
	int hasil=0;
	if(L.first != NULL)
	{
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

void pop(list *L)
{
  	if((*L).first !=NULL)
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
void printtop(list L)
{
	if(L.first !=NULL)//jika list tidak kosong
	{
		elemen *bantu =L.first;
		printf("\n----------------[TOP]----------------\n");
		{//proses print//
			printf("===================================\n");
			printf("Nim\t: %s\n",bantu->kontainer.nim);//NIM:2110512154//
			printf("Nama\t: %s\n",bantu->kontainer.nama);//NAMA:DIAS SYAHADATPUTRA//
			printf("Nilai\t: %.2f\n",bantu->kontainer.nilai);//KELAS D//
			printf("===================================\n");
		}	
		printf("---------------------------------------\n");
	}
	else//jika list Kosong
	{
	printf("\n---------------------------------------\n");
	printf("Kontainer Kosong\n");
	printf("---------------------------------------\n");}
		
}

void printStack (list L)
{
	if(L.first !=NULL)//jika list tidak kosong
	{
		elemen *bantu =L.first;
		int i=1;
		printf("\n----------------[STACK]----------------\n");
		printf("\t\tvFIRSTv\n");
		while (bantu !=NULL)
		{//proses print//
			printf("===================================\n");
			printf("Elemen Ke-%d\n",i);
			printf("Nim\t: %s\n",bantu->kontainer.nim);//NIM:2110512154//
			printf("Nama\t: %s\n",bantu->kontainer.nama);//NAMA:DIAS SYAHADATPUTRA//
			printf("Nilai\t: %.2f\n",bantu->kontainer.nilai);//KELAS D//
			printf("===================================\n");
			bantu=bantu->next;
			i++;
		}	
		printf("\t\t^TOP^\n");
		printf("---------------------------------------\n");
	}
	else//jika list Kosong
	{
	printf("\n----------------[ISI STACK]----------------\n");
	printf("Kontainer Kosong\n");
	printf("---------------------------------------\n");}
		
}
int main ()
{
  int choice;
  char nim_str[10],nama_str[50];float nilai_float;list L;
  CreateList(&L);
  printf("===================================\n");
  printf("= NAMA\t:DIAS SYAHADATPUTRA\t  =\n");
  printf("= NAMA\t:2110512154\t\t  =\n");
  printf("= KELAS\t:D\t\t\t  =\n");
  printf("===================================\n\n");
  while(1)
    {
      printf("==========[STACK MENU]==========\n");
      printf("1.PUSH STACK\n");
	  printf("2.PRINT STACK\n");
      printf("3.TOP STACK\n");
      printf("4.POP STACK\n");
      printf("5.EXIT\n");
      printf("MASUKAN PILIHAN:");scanf("%d",&choice);
      switch(choice)
        {
          case 1:
          printf("MASUKAN NIM:");scanf("%s",&nim_str);
          printf("MASUKAN NAMA:");fflush(stdin);gets(nama_str);
          printf("MASUKAN NILAI:");scanf("%f",&nilai_float);
          push(nim_str,nama_str,nilai_float,&L);fflush(stdin);break;
          case 2:
          printStack(L);break;
          case 3:printtop(L);break;
          case 4:
		  pop(&L);printStack(L);break;
          case 5:
		  printf("\nGoodbye\n");exit(0);break;
          default:
          printf("TIDAK ADA DALAM PILIHAN");break;
        }
    }
	return 0;
}
//NAMA:DIAS SYAHADATPUTRA//
//NIM:2110512154//
//KELAS D//
