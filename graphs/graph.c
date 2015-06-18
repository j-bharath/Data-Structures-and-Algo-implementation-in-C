#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Graph
{
	int e;
	int v;
	int **adj;
};

typedef struct Graph graph;

struct queue
{
	int size;
	int front;
	int rear;
	int *array;
};

typedef struct queue queue;

void fill_adj(graph *g)
{
	FILE *fp;
	int u,v,i,j;
	for(i=0;i<g->v;i++)
		for(j=0;j<g->v;j++)
			g->adj[i][j]=0;
	fp=fopen("input.txt","r");
	
	fscanf(fp,"%d%d",&u,&v);
	while(!feof(fp))
	{
		fscanf(fp,"%d%d",&u,&v);
		printf("%d\t%d\n",u,v);
		g->adj[u][v]=1;
		g->adj[v][u]=1;
	}
	fclose(fp);
}

print(graph *g)
{
	int i,j;
	printf("  \t");
	for(i=0;i<g->v;i++)
	printf("%2d\t",i);
	for(i=0;i<g->v;i++)
	{
		printf("%2d\t",i);
		for(j=0;j<g->v;j++)
		printf("%2d\t",g->adj[i][j]);
		printf("\n");
	}
}

void dfs(graph *g,int node,int visited[])
{
	int i;
	visited[node]=1;
	printf("%d-->",node);
	for(i=0;i<g->v;i++)
	if(g->adj[node][i]==1 && !visited[i])
	dfs(g,i,visited);
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

void bfs(graph *g,int node,int visited[])
{
	queue *q;
	int temp,i;
	q=create_queue();
	enqueue(q,node);
	while(!isempty(q))
	{
		temp=dequeue(q);
		visited[temp]=1;
		printf("%d-->",temp);
		for(i=0;i<g->v;i++)
		{
			if(g->adj[temp][i]==1 && !visited[i])
			enqueue(q,i);
		}
	}
}

int main()
{
	FILE *fp;
	graph *g;
	int i,*visited;
	g=(graph*)malloc(sizeof(struct Graph));
	fp=fopen("input.txt","r");
	if(!g)
	{
		printf("no space\n");
		exit(1);
	}
	fscanf(fp,"%d%d",&g->v,&g->e);
	fclose(fp);
	g->adj=(int**)malloc(g->v*sizeof(int*));
	for(i=0;i<g->v;i++)
	g->adj[i]=(int*)malloc(g->v*sizeof(int));
	if(!g->adj)
	{
		printf("no space\n");
		exit(1);
	}
	fill_adj(g);
	//printf("%d\n",g->adj[0][0]);
	print(g);
	visited=(int*)malloc(g->v*sizeof(int));
	for(i=0;i<g->v;i++)
	visited[i]=0;
	for(i=0;i<g->v;i++)
	if(!visited[i])
	dfs(g,i,visited);
	printf("\n");
	for(i=0;i<g->v;i++)
	visited[i]=0;
	for(i=0;i<g->v;i++)
	if(!visited[i])
	bfs(g,i,visited);
	printf("\n");
	return 0;
}
