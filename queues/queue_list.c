#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
	int data;
	struct Node *next;	
};

typedef struct Node node;

struct Queue
{
	node *front;
	node *rear;
};

typedef struct Queue queue;

queue *create_queue()
{
	queue *temp;
	temp=(queue*)malloc(sizeof(struct Queue));
	if(!temp)
	{
		printf("no space\n");
		return 0;
	}
	temp->front=0;
	temp->rear=0;
	return temp;
}

isEmpty(queue *q)
{
	return(q->front==0);
}

void enqueue(queue *q,int data)
{
	node *new;
	new=(node*)malloc(sizeof(struct Node));
	if(!new)
	{
		printf("no space\n");
		exit(0);
	}
	new->data=data;
	new->next=0;
	if(isEmpty(q))
	{
		q->rear=new;
		q->front=new;
	}
	else
	{
		q->rear->next=new;
		q->rear=new;
	}
}

int dequeue(queue *q)
{
	node *temp;
	int data;
	if(isEmpty(q))
	{
		printf("q is empty\n");
		return;
	}
	temp=q->front;
	q->front=q->front->next;
	data=temp->data;
	free(temp);
	return (data);
}

void print(queue *q)
{
	node *temp;
	for(temp=q->front;temp!=q->rear;temp=temp->next)
	printf("%d\t",temp->data);
	printf("%d\n",temp->data);
}

void delete(queue *q)
{
	node *temp;
	temp=q->front;
	while(temp)
	{
		q->front=q->front->next;
		free(temp);
		temp=q->front;
	}
	free(q);
}

/*int main()
{
	queue *q;
	q=create_queue();
	int i;
	for(i=0;i<10;i++)
	enqueue(q,i);
	print(q);
	printf("dequeue = %d\n",dequeue(q));
	print(q);
	delete(q);
	return 0;
}*/
