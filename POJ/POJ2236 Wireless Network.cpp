#include<stdio.h>

int father[1005],belong[1005],x0[1005],y0[1005];
bool repaired[1005],g[1005][1005];

int dist2(int x1, int y1, int x2, int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void initSet(int n)
{
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
        belong[i]=-1;
        repaired[i]=false;
    }
}

void initGraph(int n,int d)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(dist2(x0[i],y0[i],x0[j],y0[j])<=d)
            {
                g[i][j]=g[j][i]=true;
            }
            else
            {
                g[i][j]=g[j][i]=false;
            }
        }
    }
}

int findSet(int x)
{
    if(father[x]==x) return x;
    return father[x]=findSet(father[x]);
}

void unionSet(int x, int y)
{
    x=findSet(x);
    y=findSet(y);
    if(x!=y)
    {
        father[y]=x;
    }
}

int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    initSet(n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x0[i],&y0[i]);
    }
    initGraph(n,d*d);
    char s[20];
    int x,y;
    while(scanf("%s%d",s,&x)!=EOF)
    {
        if(*s=='O')
        {
            repaired[x]=true;
            for(int i=1;i<=n;i++)
            {
                if(g[x][i] and repaired[i])
                {
                    unionSet(x,i);
                }
            }
        }
        else
        {
            scanf("%d",&y);
            x=findSet(x);
            y=findSet(y);
            if(x==y) printf("SUCCESS\n");
            else printf("FAIL\n");
        }
    }
    return 0;
}
