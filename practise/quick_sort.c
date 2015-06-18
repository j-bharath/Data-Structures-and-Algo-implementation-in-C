#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void quickSort(int arr[],int left,int right)
{
	int pivot,i;
	if(right>left)
	{
		pivot=partition(arr,left,right);
		quickSort(arr,left,pivot-1);
		quickSort(arr,pivot+1,right);
		
	}
}

int partition(int arr[],int left,int right)
{
	int temp,begin,end,pivot;
	pivot=left;
	begin=left;
	end=right;
	while(begin<end)
	{
		while(arr[begin]<=arr[pivot])
		begin++;
		while(arr[end]>arr[pivot])
		end--;
		if(begin<end)
		{
			temp=arr[begin];
			arr[begin]=arr[end];
			arr[end]=temp;
		}
	}
	temp=arr[end];
	arr[end]=arr[pivot];
	arr[pivot]=temp;
	return end;
}

int main()
{
	int size;
	scanf("%d",&size);
	int arr[size];
	int i;
	for(i=0;i<size;i++)
	scanf("%d",&arr[i]);
	quickSort(arr,0,size-1);
	for(i=left;i<=right;i++)
	printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
