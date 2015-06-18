#include<stdio.h>
#include"dynArray.c"
#include<string.h>
int main()
{
	stack *stk,*minstk;
	int input[20],i=0;
	stk=create_stack();
	minstk=create_stack();
	FILE *fp;
	fp=fopen("input.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%d",&input[i++]);
	}
	input[i-1]=-999;
	while(i<20)
	input[i++]=-999;
	for(i=0;input[i]!=-999;i++)
	{
		printf("\ni=%d, input = %d",i,input[i]);
		push(stk,input[i]);
		if(isEmpty(minstk))
		push(minstk,input[i]);
		else if(minstk->array[minstk->top] >= input[i])
		push(minstk,input[i]);
	}
	printf("\n");
	print(minstk);
	return 0;
}
