#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lcs[100][100];

int LCS(char x[],int n,char y[],int m)
{
	int i,j;
	for(i=0;i<=m;i++)
	lcs[i][n]=0;
	for(j=0;j<=n;j++)
	lcs[m][j]=0;
	for(i=m-1;i>=0;i--)
	{
		for(j=n-1;j>=0;j--)
		{
			lcs[i][j]=lcs[i+1][j+1];
			if(x[i]==y[j])
			{
				lcs[i][j]++;
				printf("i=%d,j=%d\n",i,j);
			}
			if(lcs[i][j+1]>lcs[i][j])
			lcs[i][j]=lcs[i][j+1];
			if(lcs[i+1][j]>lcs[i][i])
			lcs[i][j]=lcs[i+1][j];
		}
	}
	return lcs[0][0];
}

int main()
{
	char x[7]={'a','b','c','b','d','a','b'};
	char y[6]={'b','d','c','a','b','a'};
	printf("%s\n",y);
	printf("%d\n",LCS(x,7,y,6));
	return 0;
}
