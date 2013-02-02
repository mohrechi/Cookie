#include<stdio.h>

int father[50005],belong[50005],n,m,count;

void make_set()
{
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
    }
}

int find_set(int x)
{
    if(father[x]==x)return x;
    int t=father[x];
    father[x]=find_set(father[x]);
    belong[x]=(belong[t]+belong[x])%3;
    return father[x];
}

int main()
{
    scanf("%d%d",&n,&m);
    make_set();
    count=0;
    while(m--)
    {
        int z,x,y;
        scanf("%d%d%d",&z,&x,&y);
        if(x>n or y>n or (z==2 and x==y))
        {
            count++;
        }
        else
        {
            int rx=find_set(x);
            int ry=find_set(y);
            if(rx==ry)
            {
                if((belong[x]-belong[y]+3)%3!=z-1)
                {
                    count++;
                }
            }
            else
            {
                father[rx]=ry;
                belong[rx]=(belong[y]-belong[x]+z+2)%3;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}
