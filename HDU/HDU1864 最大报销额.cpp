#include<stdio.h>
#include<memory.h>

int m,n,dp[3000001];
int price[32];
int k;

void search()
{
    int i,j,t;
    memset(dp,0,sizeof(dp));
    for(i=0;i<k;i++)
    {
        t=price[i];
        for(j=m;j>=t;j--)
        {
            if(dp[j]<dp[j-t]+t)
                dp[j]=dp[j-t]+t;
        }
    }
}

int main()
{
    int i,j,f;
    int a,b,c;
    char ch;
    double fl,q;
    bool tag;
    while(scanf("%lf%d",&q,&n)!=EOF)
    {
        if(n==0) break;
        m=(int)(q*100);
        k=0;
        memset(price,0,sizeof(price));
        for(i=0;i<n;i++)
        {
            scanf("%d",&f);
            a=0,b=0,c=0;
            tag=true;
            for(j=0;j<f;j++)
            {
                scanf(" %c:%lf",&ch,&fl);
                if(ch=='A')
                    a+=(int)(fl*100);
                else if(ch=='B')
                    b+=(int)(fl*100);
                else if(ch=='C')
                    c+=(int)(fl*100);
                else
                    tag=false;
            }
            if(a>60000 || b>60000 || c>60000 || a+b+c>100000)
            tag=false;
            if(tag)
                price[k++]=a+b+c;
            }
            search();
            printf("%.2lf\n",(double)dp[m]/100.0);
        }
    return 0;
}
