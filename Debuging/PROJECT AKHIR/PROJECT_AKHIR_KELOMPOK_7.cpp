#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000
//The Maximum Data that can be contain inside the array of data

typedef struct memoryloc//Memory Location Storage
{
	char location[100];
}Memloc;

typedef struct edge //Edge Data 
{
  int u, v, w;//u=Lokasi Awal(Start);v=Lokasi Akhir(Destination);w=Jarak (Value)
}edge;

typedef struct edge_list //Edge List
{
  edge data[MAX];
  int n;
} edge_list;

Memloc alocate[MAX];//Global Variable

edge_list elist;//Global Variable 

int Graph[MAX][MAX],n;//Global Variable

edge_list spanlist;//Global Variable 

//Function Declaration
void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();

// Applying Krushkal Algo
void kruskalAlgo() 
{
  int belongs[MAX], i, j, cno1, cno2;
  elist.n = 0;
 
  for (i = 1; i < n; i++)
    for (j = 0; j < i; j++) 
	{
      if (Graph[i][j] != 0) 
	  {
        elist.data[elist.n].u = i;
        elist.data[elist.n].v = j;
        elist.data[elist.n].w = Graph[i][j];
        elist.n++;
      }
    }
  sort();
 
  for (i = 0; i < n; i++)
    belongs[i] = i;
 
  spanlist.n = 0;
 
  for (i = 0; i < elist.n; i++) 
  {
    cno1 = find(belongs, elist.data[i].u);
    cno2 = find(belongs, elist.data[i].v);
    if (cno1 != cno2) 
	{
      spanlist.data[spanlist.n] = elist.data[i];
      spanlist.n = spanlist.n + 1;
      applyUnion(belongs, cno1, cno2);
    }
  }
}

//
int find(int belongs[], int vertexno)
{
  return (belongs[vertexno]);
}

//Union Combining Variable
void applyUnion(int belongs[], int c1, int c2) 
{
  int i;
 
  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

// Sorting algo
void sort() 
{
  int i, j;
  edge temp;
 
  for (i = 1; i < elist.n; i++)
    for (j = 0; j < elist.n - 1; j++)
      if (elist.data[j].w > elist.data[j + 1].w)
	  {
        temp = elist.data[j];
        elist.data[j] = elist.data[j + 1];
        elist.data[j + 1] = temp;
      }
}

// Printing the result
void print() {
  int i, cost = 0;
  printf("[Optimal Route to take]\n");
  for (i = 0; i < spanlist.n; i++) 
  {
    printf("[%s]->[%s] \n",alocate[spanlist.data[i].u],alocate[spanlist.data[i].v], spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }
  printf("Jarak Total Yang harus ditempuh: %dKm\n",cost);
}

int main() 
{
	//Variable
  int i, j, total_cost,jumlah,input;
  char Location[100];
  	//UI
  	printf("=========================================================\n");
  	printf("=                   [ROUTE OPTIMIZER]                   =\n");
  	printf("=========================================================\n");
	printf("\n---------------------------------------------------------\n");
	printf("-                        [MADE BY]                      -\n");
	printf("- [1]Dias Syahadatputra (2110512154)                    -\n");
	printf("- [2]Rangga Aditya Rizaldi (2110512157)                 -\n");
	printf("- [3]Stefanny (2110512137)                              -\n");
	printf("- [4]Salma Najwa Hanifah  (2110512162)                  -\n");
	printf("- [5]Jericho Akbar Friedrich (2110512133)               -\n");
	printf("---------------------------------------------------------\n");
	while(1)
	{
		int choice;
		printf("----------[Menu]----------\n");
		printf("- 1.Input Route Data     -\n"); 
		printf("- 2.Print Optimal Route  -\n");
		printf("- 3.Exit program         -\n");
		printf("--------------------------\n");
		printf("Masukan Pilihan:");scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{//inputing Data for the route
				//Memasukan Jumlah Paket yang untuk diantar
			  printf("\nMasukan Berapa Banyak Jumlah Lokasi Paket:");
			  scanf("%d",&jumlah);
			  n = jumlah;
			  printf("\n=[Masukan Nama Lokasi]=\n");
			  	//Location name
			  for(int m=0;m<jumlah;m++)
			  {
			  	printf("Location[%d]:",m+1);fflush(stdin);gets(Location);strcpy(alocate[m].location, Location);
			  }
			  int o=0;
			  printf("\n=[Masukan Data Lokasi]=\n");
			  	//Jarak antar Lokasi
			  for(int m=0;m<jumlah;m++)
			{
				
				printf("\n[Data Lokasi[%s]\n",alocate[m].location);
			  	for(o;o<jumlah;o++)
			  	{
			  		if (m==o)
			  		{
			  			continue;
					}
					else
					{
			  				printf("Jarak Dari[%s] Ke [%s]:",alocate[m].location,alocate[o].location);scanf("%d",&input);
			  				Graph[m][o]=input;
					}
				}	
				printf("\n");
			}
			kruskalAlgo();
			break;
			}
			//Printing the Optimazed route
			case 2:
			{
				print();
				break;
			}
			//exit
			case 3:
			{
				exit (0);
				break;
			}
		}
	}
	}
