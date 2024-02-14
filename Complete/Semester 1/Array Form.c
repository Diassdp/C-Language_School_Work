#include <stdio.h>
#include <stdlib.h> 
//Swap Function
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
//function to implement bubble sort
void bubbleSort(int Array[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
	{
	// Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
		{
            if (Array[j] < Array[j+1])
			{swap(&Array[j], &Array[j+1]);}
        }
    }
}

// Function to print the array //
void printArray(int Array[], int size)
{
	int i;
	for (i=0; i < size; i++)
	{printf("%d ", Array[i]);}
	printf("\n");
}

//Main Program To Call The Top Function
void main()
{
	int Array[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(Array)/sizeof(Array[0]);
	printf("Unsorted array: \n");
	printArray(Array, n);
	bubbleSort(Array, n);
	printf("Sorted array: \n");
	printArray(Array, n);
}
