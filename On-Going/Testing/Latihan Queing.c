#include<stdio.h>
#include<string.h>
#define max 10
typedef struct 
{
	char nim[11];
	char nama[50];
	float nilai;
}nilaiMatkul;

typedef struct 
{
	int first;
	int last;
	nilaiMatkul data[max];
}queue;
	
void createEmpty(queue *Q)
{
	(*Q).first= -1;
	(*Q).last= -1;
}
void printQueue(queue Q)
{
	if(Q.first !=-1)
	{
		printf("===========[ISI QUEUE]===========\n");
		int i;
		for(i=Q.last;i>=Q.first;i--)
		{
			printf("======================\n");
			printf("Element ke-%d :\n",i);
			printf("NIM           :%s\n",Q.data[i].nim);
			printf("NAMA          :%s\n",Q.data[i].nama);
			printf("NILAI         :%.2f\n",Q.data[i].nilai);
			printf("======================\n");
		}
	}
	
	else{printf("Queue Kosong\n");}
}
int isEmpty(queue Q)
{
	int hasil=0;
	if (Q.first == -1)
	{hasil = 1;}
	return hasil;

}

int isfull(queue Q)
{
	int hasil=0;
	if (Q.last==max-1)
	{hasil=1;}
	return hasil;
}

void add(char nim[],char nama[],float nilai, queue *Q)
{
	if(isEmpty(*Q)==1)
	{
		(*Q).first=0;(*Q).last=0;
		strcpy((*Q).data[(*Q).last].nim, nim);
		strcpy((*Q).data[(*Q).last].nama, nama);
		(*Q).data[(*Q).last].nilai=nilai;
	}
	else
	{
		if(isfull(*Q) ==1)
		{printf("Queue Penuh\n");}
		else
		{
			(*Q).last=(*Q).last+1;
			strcpy((*Q).data[(*Q).last].nim, nim);
			strcpy((*Q).data[(*Q).last].nama, nama);
			(*Q).data[(*Q).last].nilai=nilai;
		}
	}
}
void del(queue *Q)
{
	if((*Q).last==0)
	{
		(*Q).first=-1;
		(*Q).last=-1;
	}
	else 
	{
	int i;
	for(i=(*Q).first+1;i<=(*Q).last;i++)
	{
			strcpy((*Q).data[i-1].nim, (*Q).data[i].nim);
			strcpy((*Q).data[i-1].nama, (*Q).data[i].nama);
			(*Q).data[i-1].nilai=(*Q).data[i].nilai;
	}
	}
	(*Q).last=(*Q).last-1;
}
int main ()
{
	queue Q;
	createEmpty(&Q);
	printQueue (Q);
	add("12345678","Dias",70.5,&Q);
	add("12345278","andy",70.5,&Q);
	printQueue (Q);
	del(&Q);
	printQueue (Q);
	return 0;
}


