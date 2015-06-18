#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int partition(int arr[],int left,int right)
{
	int pivot,temp,low,high;
	pivot=left;
	low=left;
	high=right;
	while(left<right)
	{
		while(arr[left]<=arr[pivot] && left<high)
		left++;
		while(arr[right]>=arr[pivot] && right>low)
		right--;
		if(left<right)
		{
			temp=arr[left];
			arr[left]=arr[right];
			arr[right]=temp;
		}
	}
	temp=arr[right];
	arr[right]=arr[pivot];
	arr[pivot]=temp;
	return right;
}

void quick_sort(int arr[],int left,int right)
{
	int pivot;
	if(left<right)
	{
		pivot=partition(arr,left,right);
		quick_sort(arr,left,pivot-1);
		quick_sort(arr,pivot+1,right);
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
	quick_sort(arr,0,9);
	print(arr,10);
	return 0;
}
