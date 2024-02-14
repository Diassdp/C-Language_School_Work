#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 10
typedef struct
{
	char nim[10];
	char nama[50];
	float nilai;
}nilaimatkul;

typedef struct
{
	int top;
	nilaimatkul data[max];
}stack;

void CreateEmpty(stack *S)
{
	(*S).top=-1;
}

int isempty(stack S)
{
	int hasil=0;
	if (S.top == -1)
	{
		hasil =1;
	}
	return hasil;
}

int isfull(stack S)
{
	int hasil=0;
	if (S.top==max-1)
	{
		hasil=1;
	}
	return hasil;
}

void push(char nim[],char nama[],float nilai, stack *S)
{
	if (isfull(*S)==1)
	{
		printf("Stack Penuh\n");
	}
	else 
	{
		if(isempty(*S)==1)
		{
			(*S).top=0;
			strcpy((*S).data[0].nim,nim);
			strcpy((*S).data[0].nama,nama);
			(*S).data[0].nilai=nilai;
		}
		else
		{
			(*S).top=(*S).top+1;
			strcpy((*S).data[(*S).top].nim,nim);
			strcpy((*S).data[(*S).top].nama,nama);
			(*S).data[(*S).top].nilai=nilai;
		}
		
	}
}

void pop(stack *S)
{
  if((*S).top==0)
  {
    (*S).top=-1;
  }
  else
  {
  if((*S).top!=-1)
  {(*S).top=(*S).top-1;}
    else
  {printf("tidak Bisa pop dikarenakan stack kosong");}
  }
}
void printStack (stack S)
{
	if (S.top!=-1)
	{
	printf("\n===================[ISI STACK]===================\n");
	int i;
	for(i=S.top;i>=0;i--)
	{
		printf("\n========================\n");
		printf("Elemen ke:%d\n", i);
		printf("nim :%s\n", S.data[i].nim);
		printf("nama :%s\n", S.data[i].nama);
		printf("nilai :%.2f\n", S.data[i].nilai);
		printf("========================\n");
	}
	}
	else 
	{printf("STACK KOSONG\n");}	
}

int main ()
{
//Temporary Data Storage//
  int choice;
  char nim_str[10],nama_str[50];
  float nilai_float;
  
  stack S;
  CreateEmpty(&S);
  while(1)
    {
      printf("==========[STACK MENU]==========\n");
      printf("1.PRINT STACK\n");
      printf("2.PUSH STACK\n");
      printf("3.POP STACK\n");
      printf("4.EXIT\n");
      printf("MASUKAN PILIHAN:");scanf("%d",&choice);
      switch(choice)
        {
          case 1:
          printStack (S);break;
          case 2:
          printf("MASUKAN NIM:");scanf("%s",&nim_str);
          printf("MASUKAN NAMA:");fflush(stdin);gets(nama_str);
          printf("MASUKAN NILAI:");scanf("%f",&nilai_float);
          push(nim_str,nama_str,nilai_float,&S);fflush(stdin);break;
          case 3:
		  pop(&S);break;
          case 4:
		  printf("\nGoodbye\n");exit(0);break;
          default:
          printf("TIDAK ADA DALAM PILIHAN");break;
        }
    }
	return 0;
}
