#include<stdio.h>
#include<stdlib.h>

struct link
{
    int point1;
    int point2;
    int length;
}links[1000009];

int n,sum,count, trees,maxlinks,visited[109];

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
            for(i=0,t=visited[y];i<n;i++)
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
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    qsort(links, maxlinks, sizeof(*links),cmp);
    for(i=0;count!=n&&i<maxlinks;i++)
    {
        connect(links[i].point1, links[i].point2, links[i].length);
    }
    return sum;
}

int main(int argc, char* argv[])
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        maxlinks=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&k);
                if(j>i)
                {
                    links[maxlinks].point1=i;
                    links[maxlinks].point2=j;
                    links[maxlinks].length=k;
                    maxlinks++;
                }
            }
        }
        printf("%d\n",Kruskal());
    }
    return 0;
}
