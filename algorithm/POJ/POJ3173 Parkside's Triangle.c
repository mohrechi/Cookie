#include<stdio.h>

int main(int argc, char* argv[])
{
	int m,n,i,j,t,a;
	scanf("%d%d",&m,&n);
	for(i=1,t=n;i<=m;i++)
	{
	    for(j=1;j<i;j++) printf("  ");
	    printf("%d",t);
	    a=t+i;
	    if(a>9) a-=9;
	    for(j=i,t=a;j<m;j++,t+=j)
	    {
	        while(t>9) t-=9;
	        printf(" %d",t);
	    }
	    printf("\n");
	    t=a+1;
	    if(t>9) t-=9;
	}
	return 0;
}
