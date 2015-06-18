#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue_list.c"

void reverse(queue *q)
{
	int temp;
	if(!isEmpty(q))
	{
		temp=dequeue(q);
		reverse(q);
	}
	enqueue(q,temp);
}

int main()
{
	int i;
	queue *q;
	q=create_queue();
	for(i=1;i<10;i++)
	enqueue(q,i);
	printf("before reversal\n");
	print(q);
	printf("after reversal\n");
	reverse(q);
	print(q);
	return 0;
}
