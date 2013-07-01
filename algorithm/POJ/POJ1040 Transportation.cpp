#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

struct Order
{
    int u,v,num,earning;
}order[100];
int capacity, stopNum, orderNum, maxEarning, station[100];

void dfs(int start, int earning)
{
    if(earning>maxEarning)
    {
        maxEarning=earning;
    }
    for(;start<orderNum;start++)
    {
        int i;
        for(i=order[start].u;i<order[start].v;i++)
        {
            station[i]+=order[start].num;
            if(station[i]>capacity)
            {
                break;
            }
        }
        if(i==order[start].v)
        {
            dfs(start+1, earning+order[start].earning);
            i--;
        }
        for(;i>=order[start].u;i--)
        {
            station[i]-=order[start].num;
        }
    }
}

int main()
{
    while(scanf("%d%d%d",&capacity,&stopNum,&orderNum),capacity or stopNum or orderNum)
    {
        for(int i=0;i<orderNum;i++)
        {
            scanf("%d%d%d",&order[i].u,&order[i].v,&order[i].num);
            order[i].earning=order[i].num*(order[i].v-order[i].u);
        }
        memset(station,0,sizeof(station));
        maxEarning=0;
        dfs(0,0);
        printf("%d\n",maxEarning);
    }
    return 0;
}
