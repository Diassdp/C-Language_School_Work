#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
#define size 10

//Data Structure
typedef struct {
	char nama[50];
	int NIP;
}Data;

//Swap Function to Swap data within thw Program
void swap(Data* xp, Data* yp)
{
    Data temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//Merge Function 
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
    	{L[i] = arr[l + i];}
    	
    for (j = 0; j < n2; j++)
       	{R[j] = arr[m + 1 + j];} 
  
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
  
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//A Function to Create Partion
int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
/*================================================*/
//A Function to imlement MergeSort 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
  
// A function to implement bubble sort
void bubbleSort(Data arr[], int n)
{
    int i, j;
    //High To Low
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if ((arr[j]).NIP>(arr[j + 1]).NIP)
            {
                swap(&arr[j], &arr[j + 1]);
        	}
    	}
	}
    //Low to High
      for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if ((arr[j]).NIP<(arr[j + 1]).NIP)
            {
                swap(&arr[j], &arr[j + 1]);
        	}
    	}
	}
}

//A Function to Implement QuickSort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//A Function to Implement InsertionSort
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
//A Function To Implement SelectionSort
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

//Utility Function To Print The Data
void printArray(Data arr[], int n)
{
    int i;
    printf("[Data Pegawai]\n\n");
    for (i = 0; i < n; i++)
    {
    	printf("[Pegawai %d] \n",i+1);
        printf("NIP:%d \n", arr[i].NIP);
        printf("NAMA:%s \n",arr[i].nama);
	}
    printf("\n");
}

//Main Code//
int main ()
{
	int choice,n,i;
	Data arr[size];
	//Inisialisasi Data 
	char *name_t[size]={"Dias","Kalo","Charles","Denis","Polo","Merlon","Steven","Kale","Niel","Belond"};
	int NIP_t[size]={21110542,21110543,21110544,21110545,21110534,21110521,21110505,21123242,4322312,21110550};
	//Copying Temporary Array To Main Data Structure
	for(i=0;i<size;i++)
	{
		(arr[i]).NIP=NIP_t[i];
		strcpy(arr[i].nama,name_t[i]);
		n++;
	}
	//Menu//
	int choice;
	printf("[Menu]\n 1.BubbleSort\n2.InsertionSort\n3.SelectionSort\n 4.MergeSort \n5.QuickSort\n");pritf("Masukan Pilihan:");scanf("%d",&choice);
	switch(choice)
	{
		case 1:{
			printf("[BubbleSort]\n")
			printf("(Before Sort)");printarray(arr,n);bubbleSort(&arr,n);printf("(After Sort)");printarray(arr,n);
			
			break;
		}
		case 2:{
			
			break;
		}
		case 3:{
			
			break;
		}
		case 4:{
			
			break;
		}
		case 5:{
			
			break;
		}
		default:{
			
			break;
		}
	}
	return 0;
}
