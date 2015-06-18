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
		printf("not enuf space\n");
		exit(1);
	}
	q->size=1;
	q->front=-1;
	q->rear=-1;
	q->array=(int *)malloc(q->size*sizeof(int));
	if(!(q->array))
	{
		printf("not enuf space\n");
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
	return((q->rear+1)%q->size==q->front);
}

int queue_size(queue *q)
{
	return((q->size-q->rear+q->front+1)%q->size);
}

void resize(queue *q)
{
	int i,size;
	size=q->size;
	q->size*=2;
	q->array=realloc(q->array,q->size*(sizeof(int)));
	if(!q->array)
	{
		printf("resize memory not sufficient\n");
		exit(1);
	}
	if(q->front > q->rear)
	{
		for(i=0;i<q->front;i++)
		q->array[i+size]=q->array[i];
		q->rear=q->rear+size;
	}
	printf("queue size= %d\n",q->size);
}

void enqueue(queue *q,int data)
{
	
	if(isFull(q))
	resize(q);
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
		printf("queue empty\n");
		return;	
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
		printf("queue empty\n");
		return;
	}
	else
	{
		for(i=q->front;i!=q->rear;i=(i+1)%q->size)
		printf("%d\t",q->array[i]);	
	}
	printf("%d\n",q->array[i]);
}

/*int main()
{
	queue *q;
	q=create_queue();
	int selection,data;
	printf("enter 1->enqueue,2->dequeue,3->print\n");
	while(1)
	{
		printf("enter selection\n");
		scanf("%d",&selection);
		switch(selection)
		{
			case 1:
				printf("enter data to enqueue\n");
				scanf("%d",&data);
				enqueue(q,data);
				break;
			case 2:
				data=dequeue(q);
				printf("dequeued %d\n",data);
				break;
			case 3:
				print(q);
				break;
			default:
				printf("invalid choice");
				break;
		}
	}
}*/
