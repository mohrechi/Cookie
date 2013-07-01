#include <stdio.h>

int main()
{
    __int64 sum[21]={1,1};
    __int64 f[21]={0,0,1};
    __int64 res;
    int i,m,n,NumOfTest;
    for (i=2;i<=20;i++)
    {
        sum[i]=sum[i-1]*i;
        if(i>=3)
            f[i]=(i-1)*(f[i-1]+f[i-2]);
    }
    while (scanf("%d",&NumOfTest)!=EOF)
    {
        while (NumOfTest--)
        {
            scanf("%d%d",&n,&m);
            res=sum[n]/sum[m]/sum[n-m]*f[m];
            printf("%I64d\n",res);
        }
    }
    return 0;
}
