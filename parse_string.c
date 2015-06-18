#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
int main()
{ 
	char line[30];
	int i;
	gets(line);
	for(i=0;line[i]!='\0';i++)
	{
		if(48<=line[i] && line[i]<=57)
		printf("%c",line[i]);
	}
	return 0;
}
