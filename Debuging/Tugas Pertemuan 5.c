#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 10
typedef struct 
{
	char nama[50];
	char pesanan[50][50];
	int count;
}kafe;

typedef struct 
{
	int first;
	int last;
	kafe data[max];
}queue;
	
void createEmpty(queue *Q)
{
	(*Q).first= -1;
	(*Q).last= -1;
}

void printQueue(int count,queue Q)
{
	int c;
	if(Q.first !=-1)
	{
		printf("-===========[ANTRIAN KAFE]===========-\n");
		int i,k;
		for(i=Q.last;i>=Q.first;i--)
		{
			printf("\n======================\n");
			printf("ANTRIAN KE 	:[%i]\n",i+1);
			printf("NAMA		:%s",Q.data[i].nama);
			printf("\n======[PESANAN]======\n");
			for(k=0;k<Q.data[i].count-1;k++)
			{printf("%d,%s \n",k+1,Q.data[i].pesanan[k]);}
			printf("\n======================\n");
		}
	}
	else{printf("\n[Antrian Kosong]\n");}
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

void add(int count,char nama[],char pesanan[50][50],queue *Q)
{
	int i;
	if(isEmpty(*Q)==1)
	{
		(*Q).first=0;(*Q).last=0;
		strcpy((*Q).data[(*Q).last].nama, nama);
		for(i=0;i<count-1;i++)
		{
		strcpy((*Q).data[(*Q).last].pesanan[i],pesanan[i]);
		}
		(*Q).data[(*Q).last].count=count;
	}	
	else
	{
		if(isfull(*Q) ==1)
		{printf("\n[Antiran Penuh]\n");}
		else
		{
			(*Q).last=(*Q).last+1;
			strcpy((*Q).data[(*Q).last].nama, nama);
			for(i=0;i<count-1;i++)
			{
			strcpy((*Q).data[(*Q).last].pesanan[i],pesanan[i]);
			}
			(*Q).data[(*Q).last].count=count;
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
	int k;
	for(i=(*Q).first+1;i<=(*Q).last;i++)
	{
			strcpy((*Q).data[i-1].nama, (*Q).data[i].nama);
	}
	}
	(*Q).last=(*Q).last-1;
}

int main ()
{
	char t_nama[50];char t_pesanan[50][50];
  	int choice,choice2,count=0;
  	int i;
  	queue Q;
  	createEmpty(&Q);
  	while(1)
    {
    	printf("=====[CAFE UWU]=====\n");
    	printf("1.Masuk Antrian\n");
    	printf("2.Keluar Dari Antrian\n");
    	printf("3.Print Queue\n");
    	printf("3.EXIT MENU\n");
    	printf("MASUKAN PILIHAN: ");scanf("%d",&choice);
    	switch(choice)
    	{
    		case 1:
    			printf("=====[PELANGGAN ]=====\n");
    			printf("NAMA PELANGGAN:");fflush(stdin);gets(t_nama);
    			for(i=0;i<10;i++)
				{
    			printf("\n=====[MENU CAFE]=====\n");
    			printf("1.Caramel Cappucino\n");
    			printf("2.Ice Tea\n");
    			printf("3.Lemon Tea\n");
    			printf("4.Black Coffe\n");
    			printf("5.Espresso\n");
    			printf("6.Lemon Cake\n");
    			printf("7.Black Forest Cake\n");
    			printf("8.Ice Cream Mochi\n");
    			printf("9.Ice Cream\n");
    			printf("10.Finish Selection\n");
    			printf("MASUKAN PILIHAN:");scanf("%d",&choice2);
    			if(choice2==1){strcpy(t_pesanan[i],"Caramel Cappucino");}
    			else if(choice2==2){strcpy(t_pesanan[i],"Ice Tea");}
    			else if(choice2==3){strcpy(t_pesanan[i],"Lemon Tea");}
    			else if(choice2==4){strcpy(t_pesanan[i],"Black Coffe");}
    			else if(choice2==5){strcpy(t_pesanan[i],"Espresso");}
    			else if(choice2==6){strcpy(t_pesanan[i],"Lemon Cake");}
    			else if(choice2==7){strcpy(t_pesanan[i],"Black Forest Cake");}
    			else if(choice2==8){strcpy(t_pesanan[i],"Ice Cream Mochi");}
    			else if(choice2==9){strcpy(t_pesanan[i],"Ice Cream");}
    			else if(choice2==10){i=10;}
				count++;
    			}
    			add(count,t_nama,t_pesanan,&Q);count=0;break;
    			case 2:del(&Q);break;
    			case 3:printQueue(count,Q);break;
		}	
    }
   return 0; 
}
