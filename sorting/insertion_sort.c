#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void insertion_sort(int arr[],int size)
{
	int i,j,temp;
	for(i=1;i<size;i++)
	{
		temp=arr[i];
		for(j=i-1;arr[j]>temp && j>=0;j--)
		{
			arr[j+1]=arr[j];
		}
		arr[j+1]=temp;
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
	int arr[8]={6,8,1,4,5,3,7,2};
	insertion_sort(arr,8);
	print(arr,8);
	return 0;
}
