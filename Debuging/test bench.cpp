// A C++ program for Prim's Minimum
// Spanning Tree (MST) algorithm. The program is
// for adjacency matrix representation of the graph
#include <bits/stdc++.h>
using namespace std;

//Berapa Banyak Titik lokasi
#define Jumlah 4

// A utility function to find the vertex with
// minimum key value, from the set of vertices
// not yet included in MST
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < Jumlah; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}
// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int graph[Jumlah][Jumlah])
{
	int count=0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < Jumlah; i++)
    {
        printf("%d - %d : %d",parent[i],i,graph[i][parent[i]]);
        count=count+graph[i][parent[i]];
        printf("count%d\n",count);
	}
	printf("Jumlah Jarak %d",count);
}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(int graph[Jumlah][Jumlah])
{
    // Array to store constructed MST
    int parent[Jumlah];

    // Key values used to pick minimum weight edge in cut
    int key[Jumlah];

    // To represent set of vertices included in MST
    bool mstSet[Jumlah];

    // Initialize all keys as INFINITE
    for (int i = 0; i < Jumlah; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first vertex.
    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    // The MST will have Jumlah vertices
    for (int count = 0; count < Jumlah - 1; count++)
    {
        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, mstSet);
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < Jumlah; v++)
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    // print the constructed MST
    printMST(parent, graph);
}

// Driver code
int main()
{
    int graph[Jumlah][Jumlah],pilihan;
		while(1){
		printf("----------[Menu]----------\n");
		printf("- 1.Input Route Data     -\n");
		printf("- 2.Print Optimal Route  -\n");
		printf("- 3.Exit program         -\n");
		printf("--------------------------\n");
		printf("Masukan Pilihan:");scanf("%d",&pilihan);
switch(pilihan)
{
  case 1:
  	{
    	for(int i=0;i<Jumlah;i++)
    	{
      	int c=0;
      		for(int k=0;k<Jumlah;k++)
        	{
          		if(i!=0)
          	{
            	printf("Jarak Dari[%d] ke [%d]",i,k);
            	scanf("%d",&c);
            	graph[i][k]=c;
          	}
        	}
    	}
      break;
	}
  case 2:
  {primMST(graph);break;}

  case 3:
    {
      exit(0);
    }
}
}
}
