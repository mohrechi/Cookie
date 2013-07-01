#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
#define Max 210
#define INF 99999999

int m,s,cnt;
int pre[Max],degree[Max];
int map[Max][Max],flag[Max][Max];
bool vis[Max];
queue <int> Q;

int BFS()
{
    int i,tmp,min,tmppre;
    for(i=0;i<=m+1;i++)
    {
        vis[i]=false;
        pre[i]=-1;
    }
    vis[0]=true;
    while(!Q.empty())
        Q.pop();
    Q.push(0);
    while(!Q.empty())
    {
        tmp=Q.front();
        Q.pop();
        for(i=1;i<=m+1;i++)
        {
            if(i==tmp || vis[i] || !map[tmp][i])
                continue;
            vis[i]=true;
            pre[i]=tmp;
            Q.push(i);
        }
    }
    if(pre[m+1]==-1)
        return -1;
    min=INF,tmp=m+1;
    while((tmppre=pre[tmp]) != -1)
    {
        if(map[tmppre][tmp]<min)
            min=map[tmppre][tmp];
        tmp=tmppre;
    }
    return min;
}

bool Edmonds_Karp(int cnt)
{
    int i,tmp,val,tmppre,total;
    while((val=BFS()) !=-1)
    {
        tmp=m+1;
        while((tmppre=pre[tmp]) != -1)
        {
            map[tmppre][tmp]-=val;
            map[tmp][tmppre]+=val;
            flag[tmppre][tmp]+=val;
            flag[tmp][tmppre]=-flag[tmppre][tmp];
            tmp=tmppre;
        }
    }
    total=0;
    for(i=1;i<=m;i++)
        total+=flag[0][i];
    return total==cnt;
}
int main()
{
    int i,n,start,end,type;
    bool mark;
    cin>>n;
    while(n--)
    {
        cin>>m>>s;
        mark=true;
        memset(degree,0,sizeof(degree));
        memset(map,0,sizeof(map));
        memset(flag,0,sizeof(flag));
        for(i=0;i<s;i++)
        {
            cin>>start>>end>>type;
            degree[start]++;
            degree[end]--;
            if(type!=1)
                map[start][end]++;
        }
        for(i=1;i<=m;i++)
        {
            if(abs(degree[i])%2==1)
            {
                mark=false;
                break;
            }
            else
                degree[i]=degree[i]/2;
        }
        if(mark)
        {
            cnt=0;
            for(i=1;i<=m;i++)
            {
                if(degree[i]<0)
                    map[i][m+1]=abs(degree[i]);
                else if(degree[i]>0)
                {
                    map[0][i]=degree[i];
                    cnt+=degree[i];
                }
            }
            if(!Edmonds_Karp(cnt))
                mark=false;
        }
        if(mark)
            cout<<"possible"<<endl;
        else
            cout<<"impossible"<<endl;
    }
    return 1;
}
