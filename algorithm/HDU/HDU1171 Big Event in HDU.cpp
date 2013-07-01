#include<stdio.h>
#include<string.h>
int c1[250000],c2[250000];
int main()
{
    int i,j,k;
    int a[101],b[101],n,sum;
    while(scanf("%d",&n))
    {
        if(n<0)break;
        if(n==0)continue;
        sum=0;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        c1[0]=1;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
            sum+=a[i]*b[i];
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<=sum;j++)
            {
                if(c1[j])
                {
                    for(k=0;k*a[i]+j<=sum&&k<=b[i];k++)
                    {
                        c2[j+k*a[i]]+=c1[j];
                    }
                }
            }
            for(j=0;j<=sum;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        for(i=sum/2;i<=sum;i++)
        {
            if(c1[i])
            {
                i=(i>sum-i?i:sum-i);
                printf("%d %d\n",i,sum-i);
                break;
            }
        }
    }
    return 0;
}
