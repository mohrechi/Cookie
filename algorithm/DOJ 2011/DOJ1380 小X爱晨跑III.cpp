#include<stdio.h>
#include<stdlib.h>
int park[100005],n,q,sum[100005];
int main()
{
    while(scanf("%d%d",&n,&q)!=EOF)
    {
        sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&park[i]);
            sum[i]=sum[i-1]+park[i];
        }
        for(int i=0;i<q;i++)
        {
            int x,y,ans;
            scanf("%d%d",&x,&y);
            if(x>y)
            {
                x^=y,y^=x,x^=y;
            }
            ans=sum[y];
            for(int j=1;j<x;j++)
            {
                ans-=park[j];
            }
            printf("%d\n",ans);
        }
        printf("\n");
    }
    return 0;
}
