#include<stdio.h>
#include<stdlib.h>
unsigned int a[2000005];
int get(long long n)
{
    if(n==1)
    {
        return 0;
    }
    if(n<=2000000)
    {
        if(a[n])
        {
            return a[n];
        }
    }
    if(n&1)
    {
        if(n<=2000000) return a[n]=get(3*n+1)+1;
        else return get(3*n+1)+1;
    }
    else
    {
        if(n<=2000000) return a[n]=get(n/2)+1;
        else return get(n/2)+1;
    }
}
int main()
{
    int x,y,max;
    while(scanf("%d%d",&x,&y)!=EOF)
    {
        if(x>y)
        {
            x^=y,y^=x,x^=y;
        }
        max=0;
        for(int i=x;i<=y;i++)
        {
            get(i);
            if(a[i]>max)
            {
                max=a[i];
            }
        }
        printf("%d\n",max);
    }
    return 0;
}
