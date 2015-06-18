#include <stdio.h>
#include <string.h>
#include <stdlib.h>




/* Head ends here */
void print(int size,int arr[])
{
	int i;
	for(i=0;i<size;i++)
	printf("%d ",arr[i]);
	printf("\n");
}
void insertionSort(int ar_size, int *  ar) 
{
	int i,temp;
	temp=ar[ar_size-1];
	for(i=ar_size-2;ar[i]>temp && i>=0;i--)
	{
		ar[i+1]=ar[i];
		print(ar_size,ar);
	}
	ar[i+1]=temp;
	print(ar_size,ar);
}

/* Tail starts here */
int main()
{
	int size;
	scanf("%d",&size);
	int arr[size],i;
	for(i=0;i<size;i++)
	scanf("%d",&arr[i]);
	insertionSort(size,arr);
	return 0;
}
/*int main() 
{
	int ar_size;
	scanf("%d", &ar_size);
	int ar[ar_size], ar_i;
	for(ar_i = 0; ar_i < ar_size; ar_i++) { 
	scanf("%d", &ar[ar_i]); 
	insertionSort(ar_size,ar);
	return 0;
}*/
