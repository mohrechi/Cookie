#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    double l,r,m,sum,s,a,b;
    bool flag;
    scanf("%d%lf",&n,&a);
    l=0.0, r=a;
    sum=1e10;
    while(r-l>1e-8)
    {
        flag=true;
        m=(l+r)/2.0;
        b=m;
        for(int i=2;i<=n;i++)
        {
            if((i-2)*(i-1)+(i-1)*b-(i-2)*a<0)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            s=(double)(n-2)*(n-1)+(n-1)*b-(n-2)*a;
            if(s<sum) sum=s;
            r=m;
        }
        else
        {
            l=m;
        }
    }
    if(s<sum) sum=s;
    printf("%.2lf\n",sum);
    return 0;
}
