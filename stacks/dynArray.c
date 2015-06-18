#include<stdio.h>
#include<stdlib.h>

struct Stack
{
	int top;
	int size;
	int *array;
};

typedef struct Stack stack;

stack *create_stack()
{
	stack *st;
	st=(stack*)malloc(sizeof(struct Stack));
	if(!st)return 0;
	st->top=-1;
	st->size=1;
	st->array=(int*)malloc(st->size * sizeof(int));
	if(!st->array)return 0;
	return st;
}

void delete(stack *st)
{
	if(st->array)
	free(st->array);
	free(st);
}

stack double_stack(stack *st)
{
	st->size*=2;	
	st->array=realloc(st->array,st->size * sizeof(int));
}

int isFull(stack *st)
{
	return(st->top==st->size-1);
}

int isEmpty(stack *st)
{
	return(st->top==-1);
}

void push(stack *st,int data)
{
	if(isFull(st))
	double_stack(st);
	st->array[++(st->top)]=data;
}

int pop(stack *st)
{
	if(isEmpty(st))
	{
		printf("error :stack empty");
		return 0;
	}
	return(st->array[st->top--]);
}

void print(stack *st)
{
	int i;
	for(i=0;i <=st->top;i++)
	printf("%d\t",st->array[i]);
	printf("\n");
}


/*int main()
{
	int i;
	stack *st;
	st=create_stack();
	if(!st)
	exit(0);
	for(i=0;i<=100000;i++)
	push(st,i);
	print(st);
}*/
/*int main()
{
	int selection,data;
	stack *st;
	st=create_stack();
	if(!st)
	exit(0);
	printf("enter 1->push,2->pop,3->print");
	while(1)
	{	
		printf("enter selection\n");
		scanf("%d",&selection);
		switch(selection)
		{
			case 1:
				printf("enter data to push\n");
				scanf("%d",&data);
				push(st,data);
				printf("stack size= %d\n",st->size);
				break;
			case 2:
				printf("poped = %d\n",pop(st));
				break;
			case 3:
				print(st);
				break;
			default:
				printf("invalid choice\n");
				break;
		}
	}
	return 0;
}*/










