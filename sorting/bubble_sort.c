#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void bubble_sort(int arr[],int size)
{
	int i,j,temp;
	for(i=size-1;i>=0;i--)
	{
		for(j=0;j<=i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
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
	bubble_sort(arr,10);
	print(arr,10);
	return 0;
}
