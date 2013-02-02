#include<stdio.h>

int father[100005],opp[100005],rank[100005],n,m;

void make_set()
{
    for(int i=1;i<=n;i++)
    {
        father[i]=i;
        rank[i]=0;
        opp[i]=-1;
    }
}

int find_set(int x)
{
    if(father[x]==x) return x;
    return find_set(father[x]);
}

void union_set(int x, int y)
{
    x=find_set(x);
    y=find_set(y);
    if(rank[x]>rank[y])
    {
        father[y]=x;
    }
    else if(rank[y]>rank[x])
    {
        father[x]=y;
    }
    else
    {
        father[y]=x;
        rank[x]++;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        make_set();
        for(int i=0;i<m;i++)
        {
            char s[20];
            int x,y;
            scanf("%s%d%d",s,&x,&y);
            if(*s=='D')
            {
                if(opp[x]!=-1)
                {
                    union_set(opp[x],y);
                }
                if(opp[y]!=-1)
                {
                    union_set(x,opp[y]);
                }
                opp[x]=y;
                opp[y]=x;
            }
            else
            {
                x=find_set(x);
                y=find_set(y);
                if(x==y)
                {
                    printf("In the same gang.\n");
                }
                else if(x==find_set(opp[y]))
                {
                    printf("In different gangs.\n");
                }
                else
                {
                    printf("Not sure yet.\n");
                }
            }
        }
    }
    return 0;
}
