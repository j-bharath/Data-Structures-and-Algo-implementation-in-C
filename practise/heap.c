#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct heap
{
	int size;
	int capacity;
	int *arr;
};

typedef struct heap heap;

heap *create_heap()
{
	heap *h;
	h=(heap*)malloc(sizeof(struct heap));
	if(!h)
	{
		printf("no space\n");
		exit(1);
	}
	h->capacity=1;
	h->size=0;
	h->arr=(int *)malloc(sizeof(int)*h->capacity);
	if(!h->arr)
	{
		printf("no space\n");
		exit(1);
	}
	return h;
}

int left(heap *h,int i)
{
	int l;
	l=2*i+1;
	if(l>h->size)
	return -1;
	else
	return l;
}

int right(heap *h,int i)
{
	int r;
	r=2*i+2;
	if(r>h->size)
	return -1;
	else
	return r;
}

/*int parent(int i)
{
	int temp;
	temp=(i-1)/2;
	if(i<=0 || i>=h->count )
	return -1;
	else
	return temp;
}*/

heap *resize(heap *h)
{
	h->capacity*=2;
	h->arr=(heap*)realloc(h->arr,h->capacity*sizeof(int));
	return h;
}

void insert(heap *h,int data)
{
	int temp;
	temp=h->size;
	if(temp==h->capacity)
	h=resize(h);
	while(temp>0 && h->arr[(temp-1)/2]<data)
	{
		h->arr[temp]=h->arr[(temp-1)/2];
		temp=(temp-1)/2;
	}
	h->size++;
	h->arr[temp]=data;
}

void percolate_down(heap *h,int node)
{
	int l,r,temp,max;
	l=left(h,node);
	r=right(h,node);
	if(l!=-1 && h->arr[l]>h->arr[node])
	max=l;
	else
	max=node;
	if(r!= -1 &&h->arr[r]>h->arr[max])
	max=r;
	if(max!=node)
	{
		temp=h->arr[node];
		h->arr[node]=h->arr[max];
		h->arr[max]=temp;
	}
	else return;
	percolate_down(h,max);
}

int delete(heap *h)
{
	int temp;
	if(h->size==0)
	return -1;
	temp=h->arr[0];
	h->arr[0]=h->arr[h->size];
	h->size--;
	percolate_down(h,0);
	return temp;
}

int main()
{
	heap *h;
	int temp;
	h=create_heap();
	insert(h,30);
	insert(h,29);
	insert(h,13);
	insert(h,34);
	printf("%d\n",delete(h)/*,delete(h),delete(h),delete(h)*/);
	return 0;
}
