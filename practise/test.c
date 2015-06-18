#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insertionSort(int arr[],int size)
{
	int i,j,temp;
	for(i=1;i<size;i++)
	{
		temp=arr[i];
		for(j=i;j>0 && arr[j-1]>temp;j--)
		arr[j]=arr[j-1];
		arr[j]=temp;
	}
}

int main()
{
	int i,arr[]={1,4,3,5,6,2};
	insertionSort(arr,6);
	for(i=0;i<6;i++)
	printf("%d\t",arr[i]);
	return 0;
}
