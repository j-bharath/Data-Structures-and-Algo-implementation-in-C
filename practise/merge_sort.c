#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int left,int mid,int right,int arr[])
{
	int temp[right-left+1];
	int i,j,k;
	i=left;j=mid;k=0;
	while(i<mid && j<=right)
	{
		if(arr[i]<=arr[j])
		temp[k++]=arr[i++];
		else
		temp[k++]=arr[j++];
	}
	while(i<mid)
	temp[k++]=arr[i++];
	while(j<=right)
	temp[k++]=arr[j++];
	for(i=left,k=0;i<=right;i++,k++)
	arr[i]=temp[k];
}

void mergeSort(int left,int right,int arr[])
{
	int mid;
	if(left<right)
	{
		mid=(left+right)/2;
		mergeSort(left,mid,arr);
		mergeSort(mid+1,right,arr);
		merge(left,mid+1,right,arr);
	}
}

int main()
{
	int arr[]={5,8,1,3,7,9,2};
	mergeSort(0,6,arr);
	int i;
	for(i=0;i<7;i++)
	printf("%d ",arr[i]);
	printf("\n");
	return 0;
}
