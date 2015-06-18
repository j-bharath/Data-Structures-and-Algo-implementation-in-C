#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int merge(int arr[],int left,int mid,int right)
{
	int i,j,k;long long int count;
	int temp[right-left+1];
	k=0;i=left;j=mid;count=0;
	while(i<mid && j<=right)
	{
		if(arr[i]<=arr[j])
		temp[k++]=arr[i++];
		else
		{
			temp[k++]=arr[j++];
			count+=mid-i;
		}
	}
	while(i<mid)
	temp[k++]=arr[i++];
	while(j<=right)
	temp[k++]=arr[j++];
	for(i=left,k=0;i<=right;i++,k++)
	arr[i]=temp[k];
	return count;
}

int mergesort(int arr[],int left,int right)
{
	int mid;long long int count;
	count=0;
	if(left<right)
	{
		mid=(left+right)/2;
		count=mergesort(arr,left,mid);
		count+=mergesort(arr,mid+1,right);
		count+=merge(arr,left,mid+1,right);
	}
	return count;
}


int main()
{
	int size,i,t,j;long long int count;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		count=0;
		scanf("%d",&size);
		int arr[size];
		for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
		count=mergesort(arr,0,size-1);
		printf("%lld\n",LLONG_MAX);
	}
	return 0;
}
