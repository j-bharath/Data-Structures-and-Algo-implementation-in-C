#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Queue
{
	int front,rear;
	int size;
	int *array;
};

typedef struct Queue queue;

queue *create_queue()
{
	queue *q;
	q=(queue*)malloc(sizeof(struct Queue));
	if(!q)
	{
		printf("no memory\n");
		exit(1);
	}
	q->size=10;
	q->front=-1;
	q->rear=-1;
	q->array=(int*)malloc(q->size*sizeof(int));
	if(!q->array)
	{
		printf("no memory\n");
		exit(1);
	}
	return q;
}

int isEmpty(queue *q)
{
	return(q->front==-1); 
}

int isFull(queue *q)
{
	return(q->front==(q->rear+1)%q->size);
}

int qsize(queue *q)
{
	return((q->size+q->front-q->rear)%q->size);
}

void enqueue(queue *q,int data)
{
	if(isFull(q))
	{
		printf("queue full\n");
		return;	
	}
	q->rear=(q->rear+1)%q->size;
	q->array[q->rear]=data;
	if(q->front==-1)
	q->front=0;	
}

int dequeue(queue *q)
{
	int data;
	if(isEmpty(q))
	{
		printf("q is empty\n");
		return ;
	}	
	data=q->array[q->front];
	if(q->front==q->rear)
	q->front=-1;
	else
	q->front=(q->front+1)%q->size;
	return data;
}

void print(queue *q)
{
	int i;
	if(isEmpty(q))
	{
		printf("q is empty\n");
		return;
	}
	for(i=q->front;i!=q->rear;i=(i+1)%q->size)
	printf("%d\t",q->array[i]);
	printf("%d\n",q->array[i]);
}

int main()
{
	queue *q;
	q=create_queue();
	int i;
	for(i=1;i<10;i++)
	enqueue(q,i);
	print(q);
	for(i=1;i<10;i++)
	{
		printf("dequeue = %d\n",dequeue(q));
		print(q);
	}
	return 0;
}
