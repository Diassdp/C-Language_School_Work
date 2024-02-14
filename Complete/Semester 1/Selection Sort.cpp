#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main()
{
int arr[10]={10, 7, 34, 97, 2, 43, 23, 13, 9, 1};
int i, j, min_idx,t;
	for (i=0; i < 10-1;i++)
	{
		min_idx = i;
		for (j=i+1;j < 10;j++)
		{
            if (arr[j] < arr[min_idx])
            {min_idx = j;}
			//swap(arr[min_idx], arr[i]);
			{t=arr[min_idx];arr[min_idx]=arr[i];arr[i]=t;}
		}
	}	
	for(i=0;i<10-1;i++)
   {printf("%d ",arr[i]);}
}

