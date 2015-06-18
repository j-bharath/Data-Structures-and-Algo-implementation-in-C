#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define lfactor 10


struct node
{
    int key;
    int data;
    struct node *next;
};

typedef struct node node;

struct hashnode
{
    int length;
    node *next;
};

typedef struct hashnode hashnode;

struct hashtable
{
    int count;
    int tsize;
    hashnode *table;
};

typedef struct hashtable hashtable;

int hash(int data,int size)
{
    return(data%size);
}

hashtable *createtable(int size)
{
    hashtable *h;
    int i;
    h=(hashtable*)malloc(sizeof(struct hashtable));
    if(!h)
    {
        printf("no space\n");
        exit(1);
    }
    h->count=0;
    h->tsize=size/lfactor;

    h->table=(hashnode*)malloc(sizeof(struct hashnode)*(h->tsize));
        
    if(!h->table)
    {
        printf("no space\n");
        exit(1);
    }
   
    for(i=0;i<h->tsize;i++)
    {
        h->table[i].next=0;
        h->table[i].length=0;
    }
    return h;
}

int search(hashtable *h,int data)
{
	int index;
	index=hash(data,h->tsize);
	node *temp;
	temp=h->table[index].next;
	while(temp)
	{
		if(temp->data==data)
		return 1;
		temp=temp->next;
	}
	return 0;
}

int insert(hashtable *h,int data)
{
	int index;
	
	index=hash(data,h->tsize);
	if(search(h,data))
	return 0;
	node *temp;
	temp=(node *)malloc(sizeof(struct node));
	if(!temp)
	{
		printf("no space\n");
		exit(1);
	}
	temp->key=index;
	temp->data=data;
	temp->next=h->table[index].next;
	h->table[index].next=temp;
	h->table[index].length++;
	h->count++;
	//if((h->count/h->tsize)>lfactor)
	//rehash(h);
	return 1;
}



int main()
{
    hashtable *h;
    int i;
    h=createtable(100);
    for(i=0;i<20;i++)
    insert(h,i);
    printf("%d\n",search(h,15));
    return 0;
}
