#include"linked_list.c"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	list *bottom;
	int select;
	printf("enter 1->push,2->pop");
	while(1)
	{
	printf("enter selection\n");
	scanf("%d",&select);
	switch(select)
	{
		case 1:
			insert(&bottom,create_node(),1);
			print_list(bottom);
			break;
		case 2:
			printf("popped element = %d\n",delete(&bottom,1));
			print_list(bottom); 
			break;
		default:
			printf("invalid choice\n");
			break;
	}
	}
	return 0;
}
