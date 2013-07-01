#include<iostream>
#define MaxInt 2100000000
using namespace std;

int goods[60][60][60],shopkeeper[60][60],supply[60][60],graph[150][150],weight[150][150],edge[60];
int n,m,k,MinCost,MaxFlow;

bool BellmanFord()
{
    int temp=m+n+1, length[150];
    bool flag=true;
    for(int i=1;i<=temp;i++)
    {
        length[i]=MaxInt;
        edge[i]=-1;
    }
    length[0]=0, edge[0]=-1;
    while(flag)
    {
        flag=false;
        for(int i=0;i<=temp;i++)
        {
            if(length[i]==MaxInt) continue;
            for(int j=0;j<=temp;j++)
            {
                if(length[i]+weight[i][j]<length[j] and graph[i][j]>0 and weight[i][j]<MaxInt)
                {
                    length[j]=length[i]+weight[i][j];
                    edge[j]=i;
                    flag=true;
                }
            }
        }
    }
    return length[temp]!=MaxInt;
}

void CreateGraph(int gi)
{
    int temp=m+n+1;
    for(int i=0;i<=temp;i++)
    {
        for(int j=0;j<=temp;j++)
        {
            graph[i][j]=0;
            weight[i][j]=MaxInt;
        }
    }
    MaxFlow=0;
    for(int i=1;i<=n;i++)
    {
        graph[0][i]=shopkeeper[i][gi];
        weight[0][i]=0;
        MaxFlow+=shopkeeper[i][gi];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            graph[i][j+n]=supply[j][gi];
            weight[i][j+n]=goods[gi][i][j];
        }
    }
    for(int i=n+1;i<temp;i++)
    {
        graph[i][temp]=supply[i-n][gi];
        weight[i][temp]=0;
    }
}

bool MaxFlowMinCost()
{
    int flow=0;
    while(BellmanFord())
    {
        int TempMin=MaxInt,temp=m+n+1;
        for(;;temp=edge[temp])
        {
            int pretemp=edge[temp];
            if(pretemp==-1)
            {
                break;
            }
            if(graph[pretemp][temp]<TempMin)
            {
                TempMin=graph[pretemp][temp];
            }
        }
        flow+=TempMin;
        temp=m+n+1;
        for(;;temp=edge[temp])
        {
            int pretemp=edge[temp];
            if(pretemp==-1)
            {
                break;
            }
            graph[pretemp][temp]-=TempMin;
            graph[temp][pretemp]+=TempMin;
            weight[temp][pretemp]=-weight[pretemp][temp];
            MinCost+=TempMin*weight[pretemp][temp];
        }
    }
    return flow==MaxFlow;
}

int main(int argc, char* argv[])
{
    while(cin>>n>>m>>k, n or m or k)
    {
        MinCost=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                cin>>shopkeeper[i][j];
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=k;j++)
            {
                cin>>supply[i][j];
            }
        }
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int t=1;t<=m;t++)
                {
                    cin>>goods[i][j][t];
                }
            }
        }
        int i;
        for(i=1;i<=k;i++)
        {
            CreateGraph(i);
            if(!MaxFlowMinCost())
            {
                break;
            }
        }
        if(i<=k) cout<<-1<<endl;
        else cout<<MinCost<<endl;
    }
    return 0;
}
