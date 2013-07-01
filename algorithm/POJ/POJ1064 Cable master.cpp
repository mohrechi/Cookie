#include<stdio.h>

int n,m,a[11000];

int check(int value)
{
    int temp=0;
    for(int i=1;i<=n;i++)
    {
        temp+=a[i]/value;
    }
    if(temp>=m)
    {
        return 1;
    }
    return 0;
}

int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int left=1,right=0,mid;
        for(int i=1;i<=n;++i)
        {
            double value;
            scanf("%lf",&value);
            a[i]=int(100*value);
            if(a[i]>right)
            {
                right=a[i];
            }
        }
        while(left<=right)
        {
            mid=(left+right)/2;
            if(check(mid))
                left=mid+1;
            else
                right=mid-1;
        }
        printf("%.2lf\n",right*0.01);
    }
    return 0;
}
