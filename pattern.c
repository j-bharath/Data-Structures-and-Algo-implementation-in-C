#include<stdio.h>
int main()
{
	int line,digit,j;
	for(line=0;line<5;line++)
	{
		digit=line+1;
		for(j=0;j<=line;j++)
		{
			
			printf("%d",(digit++)%2);
		}
		printf("\n");
	}
}
