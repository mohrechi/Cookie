#include<stdio.h>

int main(int argc, char* argv[])
{
	int m,n,t,i;
	double s;
	for(;;)
	{
	    scanf("%d%d",&n,&m);
	    if(!m&&!n) break;
	    printf("%d things taken %d at a time is ",n,m);
	    if (m>n-m)m=n-m;
        for (i=1,s=1;i<=m;i++)
        {
          s=s*(n-i+1)/i;
        }
	    printf("%.0lf exactly.\n",s);
	}
	return 0;
}
