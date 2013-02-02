#include<stdio.h>

int father[50005];
bool religion[50005];

void initSet(int n)
{
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
        religion[i]=-1;
    }
}

int findSet(int x)
{
    if(father[x]==x) return x;
    return father[x]=findSet(father[x]);
}

void unionSet(int x, int y, int &n)
{
    x=findSet(x);
    y=findSet(y);
    if(x!=y)
    {
        father[y]=x;
        n--;
    }
}

int main()
{
    int n,m,cases=1;
    while(scanf("%d%d",&n,&m),n or m)
    {
        initSet(n);
        while(m--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int fx=findSet(x);
            int fy=findSet(y);
            if(religion[fx])
            {
                unionSet(fx,y,n);
            }
            else if(religion[fy])
            {
                unionSet(fy,x,n);
            }
            else
            {
                unionSet(x,y,n);
                religion[x]=true;
            }
        }
        printf("Case %d: %d\n",cases++,n);
    }
    return 0;
}
