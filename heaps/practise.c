#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct heap
{
	int *array;
	int size;
	int count;
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
	h->size=1;
	h->count=0;
	h->array=(int*)malloc(sizeof(int)*h->size);
	return h;
}

int parent(heap *h,int child)
{
	if(child<=0 || child>=h->count)
	return -1;
	return (child-1)/2;
}

int lchild(heap *h,int parent)
{
	int child=2*parent+1;
	if(child>=h->count)
	return -1;
	return child;
}

int rchild(heap *h,int parent)
{
	int child=2*parent+2;
	if(child>=h->count)
	return -1;
	return child;
}

void percolate_down(heap *h,int node)
{
	if(!h)
	return;
}

void resize(heap *h)
{
	int *old,i;
	old=h->array;
	h->array=(int*)malloc(2*h->size*sizeof(int));
	for(i=0;i<h->count;i++)
	h->array[i]=old[i];
	h->size*=2;
	free(old);
}

void insert(heap *h,int data)
{
	int i;
	if(h->count==h->size)
	resize(h);
	h->count++;
	for(i=h->count-1;i>0 && data>h->array[(i-1)/2];i=(i-1)/2)
	h->array[i]=h->array[(i-1)/2];
	h->array[i]=data;
}

void delete(heap *h)
{
	
}

void print(heap *h)
{
	int i;
	for(i=0;i<h->count;i++)
	printf("%d\t",h->array[i]);
}

void destroy(heap *h)
{
	if(!h)
	return;
	if(h->array)
	free(h->array);
	free(h);
}

int main()
{
	heap *h;
	h=create_heap();
	/*insert(h,31);
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
	return 0;
}
