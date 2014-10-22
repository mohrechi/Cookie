#include<stdio.h>

int abs(int x)
{
    return x>0?x:-x;
}

int main()
{
    long long sum=0;
    int n,a[10005];
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
        for(int j=0;j<i;++j)
        {
            sum+=abs(a[i]-a[j]);
        }
    }
    printf("%lld\n",sum*2);
    return 0;
}
