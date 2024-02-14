#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;//list

void insertAtTheBegin(Node **start_ref, int data)
{
    Node *ptr1 = (Node*)malloc(sizeof(struct Node));
    ptr1->data = data;
    ptr1->next = *start_ref;
    *start_ref = ptr1;
}
  
void printList(Node *start)//print list//
{
    Node *temp = start;
    while (temp!=NULL)
    {
        printf("%d > ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void swap(Node *a,Node *b)//swap funtion
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(Node *start)//bublesort list//
{
    int swapped, i;
    Node *ptr1;
    Node *lptr = NULL;
  
    if (start == NULL)//jika isi list kosong//
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->data < ptr1->next->data)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
void deleteNode(Node** head_ref, int key)
{
    Node *temp = *head_ref, *prev;//bantu
    if (temp != NULL && temp->data == key) 
	{
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }

    while (temp != NULL && temp->data != key)
	{
        prev = temp;
        temp = temp->next;
    }
     if (temp == NULL)
        return;
	    prev->next = temp->next;
    free(temp); // Free memory
}
  
int main()
{
    Node *start = NULL;
    int t,i,d;
    int choice=0;
    while(i==0)
    {
    printf("==[MENU]==\n");
    printf("1.Print List\n");
    printf("2.Insert Value Into List\n");
    printf("3.Delete List Value\n");
    printf("4.Quit\n");
    printf("Masukan Pilihan:");scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                printf("==[LIST]==\n");
            	printList(start);break;
            }
        case 2:
            {
            	printf("=====[INSERT VALUE INTO LIST]=====\n");
            	printf("Insert Value:");scanf("%d",&t); 
				insertAtTheBegin(&start,t);bubbleSort(start);
				break;
            }
        case 3:
            {
            	printf("=====[DELETE VALUE IN LIST]=====\n");
            	printf("Insert Value to delete:");scanf("%d",&d); 
				deleteNode(&start,d);break;
            }
        case 4:
            {
				exit(0);break;
            }
        default:{printf("Pilihan tidak ada dalam menu");break;
		}
	}
	}	
}

