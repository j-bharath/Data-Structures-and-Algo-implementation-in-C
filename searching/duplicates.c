#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int arr[]={3,2,1,2,2,3};
	int i,index;
	for(i=0;i<6;i++);
	{
		index=abs(arr[i]);
		if(arr[index]<0)
		{
			printf("duplicate exist\n");
			return 0;
		}
		else
		arr[index]*= -1;
	}
	printf("no duplicates\n");
	return 0;
}
