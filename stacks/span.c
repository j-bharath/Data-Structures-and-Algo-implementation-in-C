#include<stdio.h>
#include<stdlib.h>
#include"dynArray.c"
#include<string.h>

SPAN(int a[],int n)
{
	stack *st;
	st=create_stack();
	int s[n];
	int i,p;
	for(i=0;i<n;i++)
	{
		while((!isEmpty(st)) && (a[i] > (a[st->array[st->top]])))
		{
			printf("a[%d] = %d popped = %d\n",i,a[i],a[pop(st)]);
		}
		if(isEmpty(st))
		p=-1;
		else
		p=st->array[st->top];
		s[i]=i-p;
		push(&st,i);
		print(st);
		//getchar();
	}
	for(i=0;i<n;i++)
	{
		printf("span[%d] = %d",i,s[i]);
		printf("\n");
	}
}

int main()
{
	FILE *fp;
	fp=fopen("span.txt","r");
	int n,i;
	fscanf(fp,"%d",&n);
	int a[n];
	i=0;
	while(!feof(fp))
	fscanf(fp,"%d",&a[i++]);
	//printf("n=%d\n",n);
	//for(i=0;i<n;i++)
	//printf("%d\t",a[i]);
	SPAN(a,n);
	return 0;
}

