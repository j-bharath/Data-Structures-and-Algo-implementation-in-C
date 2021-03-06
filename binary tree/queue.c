#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"treeDef.h"

queue *create_queue()
{
	queue *temp;
	temp=(queue*)malloc(sizeof(struct Queue));
	if(!temp)
	{
		printf("no space for q\n");
		exit(1);
	}
	temp->front=0;
	temp->rear=0;
	return temp;
}

int isEmpty(queue *q)
{
	return(q->front==0);
}

void enqueue(queue **q,btree *data)
{
	node *new;
	new=(node*)malloc(sizeof(struct Node));
	if(!new)
	{
		printf("no space\n");
		exit(1);
	}
	new->next=0;
	new->data=data;
	if(isEmpty(*q))
	{
		(*q)->rear=new;
		(*q)->front=new;
	}
	else
	{
		(*q)->rear->next=new;
		(*q)->rear=(*q)->rear->next;
	}
}

btree *dequeue(queue *q)
{
	node *temp;
	btree *curr;
	if(isEmpty(q))
	{
		printf("q is empty\n");
		return 0;
	}
	temp=q->front;
	curr=q->front->data;
	q->front=q->front->next;
	free(temp);
	return curr;
}

print(queue *q)
{
	node *temp;
	if(isEmpty(q))
	{
		printf("queue is empty\n");
		return;
	}
	temp=q->front;
	while(temp!=q->rear)
	{
		printf("%d\t",temp->data->tdata);
		temp=temp->next;
	}
	printf("%d\n",temp->data->tdata);
}

void delete(queue *q)
{
	node *temp;
	while(q->front)
	{
		temp=q->front;
		q->front=q->front->next;
		free(temp);
	}
	free(q);
}

/*int main()
{
	queue *q;
	q=create_queue();
	int i;
	btree *node;
	for(i=1;i<10;i++)
	{
		node=(btree*)malloc(sizeof(struct Btree));
		if(!node)
		{
			printf("no space\n");
			exit(1);
		}
		node->left=0;
		node->right=0;
		node->tdata=i;
		enqueue(&q,node);
		//node=dequeue(q);
		printf("%d\n",node->tdata);
	}
	print(q);
	node=dequeue(q);
	printf("%d\n",node->tdata);
	print(q);
	return 0;
}*/

