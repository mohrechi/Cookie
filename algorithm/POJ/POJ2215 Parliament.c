#include<stdio.h>

int a[1005][1005];
int main(int argc, char* argv[])
{
	int t,i,j,m,n,x,y,z,k;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d%d",&m,&n);
	    for(i=1;i<=m;i++)
	    {
	        for(j=1;j<=n;j++)
	        {
	            scanf("%d",&a[i][j]);
	        }
	    }
	    scanf("%d",&m);
	    while(m--)
	    {
	        scanf("%d%d%d%d",&z,&k,&x,&y);
	        for(n=0,i=z;i<=x;i++)
	        {
	            for(j=k;j<=y;j++)
	            {
	                n+=a[i][j];
	            }
	        }
	        printf("Absolutni hodnota pohodlnosti je %d bodu.\n",n);
	    }
	    printf("\n");
	}
	return 0;
}
