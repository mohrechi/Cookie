#include<stdio.h>

int father[2005],opp[2005],rank[2005],bugNum,messNum;

void make_set()
{
    for(int i=1;i<=bugNum;i++)
    {
        father[i]=i;
        rank[i]=0;
        opp[i]=-1;
    }
}

int find_set(int x)
{
    if(father[x]!=x)
    {
        father[x]=find_set(father[x]);
    }
    return father[x];
}

void union_set(int x, int y)
{
    x=find_set(x);
    y=find_set(y);
    if(rank[x]>rank[y])
    {
        father[y]=x;
    }
    else if(rank[x]<rank[y])
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
    for(int k=1;k<=t;k++)
    {
        scanf("%d%d",&bugNum,&messNum);
        make_set();
        bool flag=false;
        for(int i=1;i<=messNum;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(find_set(x)==find_set(y))
            {
                flag=true;
            }
            else
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
        }
        printf("Scenario #%d:\n",k);
        if(flag) printf("Suspicious bugs found!\n\n");
        else printf("No suspicious bugs found!\n\n");
    }
    return 0;
}
