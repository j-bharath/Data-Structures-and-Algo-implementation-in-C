#include<stdio.h>
#include<stdlib.h>

int main()
{
    int m,n,k,t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d%d%d",&n,&m,&k);
        if(n==1 && m==1)
        printf("0\n");
        else if((n==1 && m==2) || (n==2 && m==1))
        printf("0\n");
        else if(n==1 || m==1)
        printf("%d\n",k);
        else if(!(k%2))
        printf("%d\n",k/2);
        else
        printf("%d\n",k/2+1);
    }
    return 0;
}
