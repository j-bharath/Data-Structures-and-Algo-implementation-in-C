#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void selection_sort(int arr[],int size)
{
	int i,j,min,temp;
	for(i=0;i<size-1;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(arr[j]<arr[min])
			min=j;
		}
		temp=arr[min];
		arr[min]=arr[i];
		arr[i]=temp;
	}
}

void print(int arr[],int size)
{
	int i;
	for(i=0;i<size;i++)
	printf("%d\t",arr[i]);
	printf("\n");
}

int main()
{
	int arr[10]={10,9,8,7,6,5,4,3,2,1};
	selection_sort(arr,10);
	print(arr,10);
	return 0;
}
