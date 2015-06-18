#include<stdio.h>
#include"dynArray.c"
void pushAtEnd(stack *st,int data)
{
	int temp;
	if(isEmpty(st))
	{
		push(&st,data);
		return;
	}
	temp=pop(st);
	pushAtEnd(st,data);
	push(&st,temp);
}

void reverse(stack *st)
{
	int data;
	if(isEmpty(st))
	return;
	data=pop(st);
	reverse(st);
	pushAtEnd(st,data);
}



int main()
{
	FILE *fp;
	stack *st;
	st=create_stack();
	int i=0;
	fp=fopen("input.txt","r");
	int buffer[10];
	while(!feof(fp))
	{
		fscanf(fp,"%d",&buffer[i++]);
	}
	buffer[i-1]=-1;
	for(i=0;buffer[i]!=-1;i++)
	push(&st,buffer[i]);
	print(st);
	reverse(st);
	printf("\n");
	print(st);
	return 0;
}
