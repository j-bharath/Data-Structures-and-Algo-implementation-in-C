#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int getRandomNum()
{
	return rand()%10;
}

void permute()
{
	int checkList[10],i,temp,randomList[10];
	for(i=0;i<10;i++)
	checkList[i]=0;
	i=0;
	while(i<10)
	{
		temp=getRandomNum();
		if(!checkList[temp])
		{
			checkList[temp]=1;
			randomList[i]=temp;
			i++;
		}
	}
	print(randomList);
}

void print(int list[])
{
	int i;
	for(i=0;i<10;i++)
	printf("%d\t",list[i]);
	printf("\n");
}

int main()
{
	char selection[5]={"yes"};
	while(strcmp(selection,"yes")==0)
	{
		permute();
		printf("so you want another permutation, enter \"yes\" or \"no\"\n");
		scanf("%s",selection);
	}
	printf("bye\n");
	return 0;
}
