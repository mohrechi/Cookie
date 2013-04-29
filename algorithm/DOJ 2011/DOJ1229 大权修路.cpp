#include<stdio.h>
#include<stdlib.h>

struct link
{
    int point1;
    int point2;
    int length;
}links[100010];

int n,sum,count, trees,maxlinks,visited[10010],k;

int cmp(const void *a, const void *b)
{
    return (*(struct link*)a).length-(*(struct link*)b).length;
}

void connect(int x, int y, int length)
{
    int t,i;
    if(visited[x]!=visited[y])
    {
        sum+=length, count++;
        if(visited[x]<visited[y])
        {
            visited[x]^=visited[y];
            visited[y]^=visited[x];
            visited[x]^=visited[y];
        }
        if(visited[y]==0)
        {
            visited[y]=visited[x];
        }
        else
        {
            for(i=1,t=visited[y];i<=n;i++)
            {
                if(visited[i]==t)
                {
                    visited[i]=visited[x];
                }
            }
        }
    }
    else
    {
        if(visited[x]==0)
        {
            sum+=length, trees++;
            visited[x]=visited[y]=trees;
            count++;
        }
    }
}

int Kruskal()
{
    int i,j;
    sum=0, trees=0, count=1;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
    }
    qsort(links, maxlinks, sizeof(*links),cmp);
    for(i=0;count!=n-k&&i<maxlinks;i++)
    {
        connect(links[i].point1, links[i].point2, links[i].length);
    }
    return sum;
}

int main(int argc, char* argv[])
{
    int i,j,t,m;
    char s[10];
    while(scanf("%d%d%d",&m,&n,&k)!=EOF)
    {
        maxlinks=0;
        while(m--)
        {
            scanf("%d%d%d",&links[maxlinks].point1,&links[maxlinks].point2,&links[maxlinks].length);
            maxlinks++;
        }
        printf("%d\n",Kruskal());
    }
    return 0;
}

