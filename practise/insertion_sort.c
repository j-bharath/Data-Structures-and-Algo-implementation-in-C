#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void insertionSort(int size,int arr[])
{
	int i,j,k,temp;
	for(i=1;i<size;i++)
	{
		temp=arr[i];
		for(j=i-1;arr[j]>temp && j>=0;j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=temp;
		for(k=0;k<size;k++)
		printf("%d ",arr[k]);
		printf("\n");
	}
}


int main()
{
	int size,i;
	scanf("%d",&size);
	int array[size];
	for(i=0;i<size;i++)
	scanf("%d",&array[i]);
	insertionSort(size,array);
	return 0;
}
