#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main()
{
	int n,i,j,temp,num,position,count,chances;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		temp=1;
		position=0;
		count=0;
		chances=0;
		for(j=0;j<32;j++)
		{
			
			if(temp & num)
			{
				chances+=position-count;
				count++;
			}
			temp=temp*2;
			position++;
		}
		if(chances%2)
		printf("First Player\n");
		else
		printf("Second Player\n");
	}
	return 0;
}
