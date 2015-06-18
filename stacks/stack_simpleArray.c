#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack
{
	int top;
	int size;
	int *array;
};

typedef struct Stack stack;

stack *create_stack()
{
	stack *stk;
	stk=malloc(sizeof(struct Stack));
	stk->size=5;
	stk->top=-1;
	stk->array=malloc(stk->size*sizeof(int));
	return stk;
}

int isStackEmpty(stack *stk)
{
	return(stk->top==-1);
}

int isStackFull(stack *stk)
{
	return(stk->top==stk->size-1);
}

void push(stack *stk,int data)
{
	if(isStackFull(stk))
	{
		printf("stack overflow\n");
		return;
	}
	stk->array[++stk->top]=data;
}

int pop(stack *stk)
{
	if(isStackEmpty(stk))
	{
		printf("stack underflow\n");
		return;
	}
	
	return(stk->array[stk->top--]);
}

void print(stack *stk)
{
	int i;
	for(i=0;i<stk->size;i++)
	printf("%d\t",stk->array[i]);
}

int main()
{
	int selection,data;
	stack *stk;
	stk=create_stack();
	printf("enter 1->push,2->pop,3->print");
	while(1)
	{
		printf("enter your selection\n");
		scanf("%d",&selection);
		switch(selection)		
		{
			case 1:
				printf("enter the data to push\n");
				scanf("%d",&data);
				push(stk,data);
				break;
			case 2:
				printf("%d",pop(stk));
				break;
			case 3:
				print(stk);
				break;
			default:
				printf("invalid choice\n");
				break;
		}
	}
}
