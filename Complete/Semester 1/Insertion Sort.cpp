#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main()
{
int arr[10]={10, 7, 34, 97, 2, 43, 23, 13, 9, 1};
int i, key, j;
	for (i = 1; i < 10;i++)
	{
		key=arr[i];
		j = i - 1;
		while (j >= 0 && arr[j]>key)
		{arr[j+1]=arr[j];j=j-1;}
		arr[j+1]=key;
	}	
	for(i=0;i<10-1;i++)
   {printf("%d ",arr[i]);}
}

