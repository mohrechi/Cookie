#include<stdio.h>
int a[1000000];
int find(int x)
{
    if(1==x) return 1;
    if(x<1000000)
    {
        if(a[x]) return a[x];
        if(x&1) return a[x]=find(3*x+1)+1;
        else return a[x]=find(x>>1)+1;
    }
    if(x&1) return find(3*x+1)+1;
    else return find(x>>1)+1;
}

int main()
{
    int c,d,m;
    while(scanf("%d%d",&c,&d)!=EOF)
    {
        m=0;
        if(c<=d)
        {
            for(int i=c;i<=d;++i)
            {
                if(find(i)>m)
                {
                    m=find(i);
                }
            }
        }
        else
        {
            for(int i=d;i<=c;++i)
            {
                if(find(i)>m)
                {
                    m=find(i);
                }
            }
        }
        printf("%d %d %d\n",c,d,m);
    }
}
