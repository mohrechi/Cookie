#include<stdio.h>

int main()
{
    unsigned long long f3[100],f4[100],min;
    f3[1]=1;
    for(int i=2;i<=64;i++)
    {
        f3[i]=(f3[i-1]+1)*2-1;
    }
    f4[1]=1;
    for(int i=2;i<=64;i++)
    {
        min=-1;
        for(int j=1;j<i;j++)
        {
            if(2*f4[j]+f3[i-j]<min || min==-1)
            {
                min=2*f4[j]+f3[i-j];
            }
        }
        f4[i]=min;
    }
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",f4[n]);
    }
    return 0;
}
