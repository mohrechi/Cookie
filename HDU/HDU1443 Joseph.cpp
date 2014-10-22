#include<stdio.h>
int a[14];
bool f(int n, int m)
{
    int s=1,k=n;
    n*=2;
    for(int i=1;i<=k;++i)
    {
        s=(s+m-1)%n;
        if(s==0) s=n;
        --n;
        if(s<=k) return false;
    }
    return true;
}

int main()
{
    for(int i=1;i<14;i++)
    {
        for(int j=i+1;;j++)
        {
            if(f(i,j))
            {
                a[i]=j;
                break;
            }
        }
    }
    int n;
    while(scanf("%d",&n),n)
    {
        printf("%d\n",a[n]);
    }
    return 0;
}
