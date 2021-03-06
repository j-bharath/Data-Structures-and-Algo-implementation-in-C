#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int v;
int e;

struct list
{
	int vertex;
	struct list *next;
};

typedef struct list list;

struct queue
{
	int size;
	int front;
	int rear;
	int *array;
};

typedef struct queue queue;

list *create_list()
{
	list *g;
	int i;
	g=(list*)malloc(v*sizeof(struct list));
	if(!g)
	{
		printf("no space\n");
		exit(1);
	}
	for(i=0;i<v;i++)
	{
		g[i].vertex=i;
		g[i].next=0;
	}
	return g;
}

void insert(list *g,int a,int b)
{
	list *node;
	node=(list*)malloc(sizeof(struct list));
	if(!node)
	{
		printf("no space\n");
		exit(1);
	}
	node->vertex=b;
	node->next=g[a].next;
	g[a].next=node;
}

void print(list *g)
{
	int i;
	list *temp;
	for(i=0;i<v;i++)
	{
		printf("%2d\t",g[i].vertex);
		temp=g[i].next;
		while(temp)
		{
			printf("%d-->",temp->vertex);
			temp=temp->next;
		}
		printf("\n");
	}
}

void dfs(list *node,int i,int visited[])
{
	list *temp;
	visited[node[i].vertex]=1;
	printf("%d-->",node[i].vertex);
	if(!node[i].next)
	return;
	temp=node[i].next;
	while(temp)
	{
		if(!visited[temp->vertex])
			dfs(node,temp->vertex,visited);
		temp=temp->next;
	}
}

queue *create_queue()
{
	queue *q;
	q=(queue*)malloc(sizeof(struct queue));
	if(!q)
	{
		printf("no space\n");
		exit(1);
	}
	q->size=1;
	q->front=-1;
	q->rear=-1;
	q->array=(int*)malloc(q->size*sizeof(int));
	if(!q->array)
	{
		printf("no space\n");
		exit(1);
	}
	return q;
}

int isempty(queue *q)
{
	return(q->front==-1);
}

int isfull(queue *q)
{
	return((q->rear+1)%q->size==q->front);
}

void resize(queue *q)
{
	q->size=2*q->size;
	q->array=realloc(q->array,q->size*sizeof(int));
}

void enqueue(queue *q,int data)
{
	if(isfull(q))
	resize(q);
	q->rear=(q->rear+1)%q->size;
	q->array[q->rear]=data;
	if(q->front==-1)
	q->front=0;
}

int dequeue(queue *q)
{
	int temp;
	if(isempty(q))
	{
		printf("q empty\n");
		return ;
	}
	temp=q->array[q->front];
	q->front=q->front%q->size;
	if(q->front==q->rear)
	q->front=-1;
	else
	q->front=(q->front+1)%q->size;
	return temp;
}

delete(queue *q)
{
	if(q->array)
	free(q->array);
	free(q);
}



int main()
{
	FILE *fp;
	list *g;
	queue *q;
	int a,b,i;
	fp=fopen("input.txt","r");
	fscanf(fp,"%d %d",&v,&e);
	int visited[v];
	g=create_list();
	for(i=0;i<e;i++)
	{
		fscanf(fp,"%d%d",&a,&b);
		insert(g,a,b);
		//insert(g,b,a);
	}
	print(g);
	for(i=0;i<v;i++)
	visited[i]=0;
	for(i=0;i<v;i++)
		if(!visited[i])
			dfs(g,i,visited);
	printf("\n");
	for(i=0;i<v;i++)
	visited[i]=0;	
	fclose(fp);
	return 0;
}











