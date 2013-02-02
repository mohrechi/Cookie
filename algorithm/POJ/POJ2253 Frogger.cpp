#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Edge
{
    int u,v;
    double w;
    bool operator <(Edge x) const
    {
        return w<x.w;
    }
}edge[30000];

int n,caseNum=0,x[205],y[205],edgeNum,father[205];
double ans;

void init()
{
    for(int i=0;i<n;i++)
    {
        father[i]=i;
    }
}

int find(int x)
{
    if(x==father[x]) return x;
    return father[x]=find(father[x]);
}

void combine(int x, int y)
{
    x=find(x), y=find(y);
    father[x]=y;
}

void kruskal()
{
    for(int i=0;i<edgeNum;i++)
    {
        if(find(edge[i].u)!=find(edge[i].v))
        {
            combine(edge[i].u, edge[i].v);
            ans=edge[i].w;
            if(find(0)==find(1))
            {
                return;
            }
        }
    }
}

int main()
{
    while(cin>>n,n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
        }
        edgeNum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                edge[edgeNum].u=i, edge[edgeNum].v=j;
                edge[edgeNum++].w=sqrt((double)(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            }
        }
        sort(edge, edge+edgeNum);
        init();
        kruskal();
        cout<<"Scenario #"<<++caseNum<<endl;
        cout<<"Frog Distance = "<<fixed<<setprecision(3)<<ans<<endl<<endl;
    }
    return 0;
}
