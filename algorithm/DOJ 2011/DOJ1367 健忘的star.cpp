#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int n;
char min[100005][20];
double Log2;
int getMin(int a, int b)
{
    return a<b?a:b;
}
int main()
{
    Log2=1/log(2.0);
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&min[i][0]);
        }
        int m=log((double)n)*Log2;
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j+(1<<(i-1))<=n;j++)
            {
                min[j][i]=getMin(min[j][i-1],min[j+(1<<(i-1))][i-1]);
            }
        }
        int t,x,y;
        scanf("%d",&t);
        for(int i=1;i<=t;i++)
        {
            scanf("%d%d",&x,&y);
            if(x>y)
            {
                x^=y,y^=x,x^=y;
            }
            m=log((double)(y-x+1))*Log2;
            x=getMin(min[x][m],min[y-(1<<m)+1][m]);
            printf("%d\n",x);
        }
    }
    return 0;
}
