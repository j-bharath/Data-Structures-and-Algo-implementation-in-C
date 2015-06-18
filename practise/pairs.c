#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void merge(int arr[],int left,int mid,int right)
{
	int i,j,k;
	int temp[right-left+1];
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

void sort(int arr[],int left,int right)
{
	int mid;
	if(right>left)
	{
		mid=(right+left)/2;
		sort(arr,left,mid);
		sort(arr,mid+1,right);
		merge(arr,left,mid+1,right);
	}
}

int binSearch(int arr[],int left,int right,int key)
{
	int mid;
	if(left<=right)
	{
		mid=(left+right)/2;
		if(key==arr[mid])
		return 1;
		else if(key<arr[mid])
		return(binSearch(arr,left,mid-1,key));
		else
		return(binSearch(arr,mid+1,right,key));
	}
	return 0;
}

int main()
{
	int n,k,count;
	count=0;
	scanf("%d%d",&n,&k);
	int arr[n];
	int i;
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	sort(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		if(binSearch(arr,0,n-1,arr[i]+k))
		count++;
	}
	printf("%d",count);
	return 0;
}
