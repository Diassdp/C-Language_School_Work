#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main ()
{
int arr[10]={10, 7, 34, 97, 2, 43, 23, 13, 9, 1};int i,j,t;
    for (i=0; i<10-1;i++)
    {
		for (j=0;j <10-i-1;j++)
		{
            if (arr[j] > arr[j+1])
            {
			//swap(arr[j], arr[j+1]);
			{t=arr[j];arr[j]=arr[j+1];arr[j+1]=t;}//swap
			}
            
    	}
	}
   for(i=0;i<10-1;i++)
   {printf("%d ",arr[i]);}
}
