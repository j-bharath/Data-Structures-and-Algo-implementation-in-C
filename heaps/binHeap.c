#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Heap
{
	int *array;
	int size;
	int count;
};

typedef struct Heap heap;

heap *create_heap()
{
	heap *h;
	h=(heap*)malloc(sizeof(struct Heap));
	if(!h)
	{
		printf("no space\n");
		exit(1);
	}
	h->size=1;
	h->count=0;
	h->array=(int*)malloc(sizeof(int)*h->size);
	if(!h->array)
	{
		printf("no space\n");
		exit(1);
	}
	return h;
}

void resize(heap *h)
{
	int i,*old=h->array;
	h->array=(int*)malloc(2*h->size*sizeof(int));
	if(!h->array)
	{
		printf("no space\n");
		exit(1);
	}
	for(i=0;i<h->size;i++)
	h->array[i]=old[i];
	h->size*=2;
	free(old);
}

void insert(heap *h,int data)
{
	int i,temp;
	if(h->count==h->size)
	resize(h);
	h->count++;
	for(i=h->count-1;i>=0 && (data > h->array[(i-1)/2]);i=(i-1)/2)
	{
		if(i==0)
		break;
		h->array[i]=h->array[(i-1)/2];
		printf("arr=%d\t,i=%d\n",h->array[(i-1)/2],i);
	}
	h->array[i]=data;
}

void destroy(heap *h)
{
	if(h==0)
	return;
	free(h->array);
	free(h);
	h=0;
}

void print(heap *h)
{
	int i;
	for(i=0;i<=h->count-1;i++)
	printf("%d\t",h->array[i]);
}

int parent(heap *h,int i)
{
	if(i<=0 || i>=h->count)
	return -1;
	return (i-1)/2;
}

int leftchild(heap *h,int i)
{
	int child=2*i+1;
	if(child>=h->count)
	return -1;
	return child;
}

int rightchild(heap *h,int i)
{
	int child=2*i+2;
	if(child>=h->count)
	return -1;
	return child;
}

void percolate_down(heap *h,int pos)
{
	int max,temp,left,right;
	left=leftchild(h,pos);
	right=rightchild(h,pos);
	if(left!=-1 && h->array[left]>h->array[pos])
	max=left;
	else
	max=pos;
	if(right!=-1 && h->array[right]>h->array[max])
	max=right;
	if(max!=pos)
	{
		temp=h->array[max];
		h->array[max]=h->array[pos];
		h->array[pos]=temp;
	}
	else
	return;
	percolate_down(h,max);
}

void build(heap *h,int array[],int n)
{
	int i;
	if(h==0)
	return;
	while(h->size<n)
	resize(h);
	for(i=0;i<n;i++)
	h->array[i]=array[i];
	h->count=n;
	for(i=(n-1)/2;i>=0;i--)
	percolate_down(h,i);
}

int delete_node(heap *h,int i)
{
	int temp;
	if(!h)
	{
		printf("heap is empty\n");
		return ;
	}
	temp=h->array[i];
	h->array[i]=h->array[h->count-1];
	h->count--;
	percolate_down(h,i);
	return temp;
}

int main()
{
	heap *h;
	int arr[]={1,5,1,2,1,2,1,3,1,8,7,1};
	/*h=create_heap();
	insert(h,31);
	insert(h,10);
	insert(h,16);
	insert(h,9);
	insert(h,8);
	insert(h,14);
	insert(h,12);
	insert(h,3);
	insert(h,1);
	insert(h,5);
	insert(h,7);
	print(h);
	printf("\n");
	insert(h,34);
	print(h);
	printf("\n");
	destroy(h);*/
	h=create_heap();
	build(h,arr,11);
	print(h);
	printf("deleted=%d\n",delete_node(h,1));
	print(h);
	return 0;
}

