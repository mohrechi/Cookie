#include<iostream>
#include<vector>
using namespace std;

int n,treeDP[10005][3];
vector <int> connect[10005],tree[10005];
bool visited[10005];

inline int min(int x, int y)
{
    return x<y?x:y;
}

void makeTree(int x)
{
    for(int i=0;i<connect[x].size();++i)
    {
        if(!visited[connect[x][i]])
        {
            visited[connect[x][i]]=true;
            tree[x].push_back(connect[x][i]);
            makeTree(connect[x][i]);
        }
    }
}

void calcTree(int x)
{
    for(int i=0;i<tree[x].size();++i)
    {
        calcTree(tree[x][i]);
    }
    if(tree[x].size()==0)
    {
        treeDP[x][0]=0;
        treeDP[x][1]=treeDP[x][2]=1;
        return;
    }
    int sum1=0, sum2=0;
    for(int i=0;i<tree[x].size();++i)
    {
        sum1+=treeDP[tree[x][i]][1];
        sum2+=min(treeDP[tree[x][i]][0], treeDP[tree[x][i]][1]);
    }
    treeDP[x][0]=sum1;
    treeDP[x][1]=min(treeDP[x][1],sum2+1);
    treeDP[x][2]=min(treeDP[x][2],sum2+1);
    for(int i=0;i<tree[x].size();++i)
    {
        treeDP[x][1]=min(treeDP[x][1],sum1-treeDP[tree[x][i]][1]+treeDP[tree[x][i]][2]);
    }
}

int main()
{
    cin>>n;
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        connect[x].push_back(y);
        connect[y].push_back(x);
        treeDP[i][0]=treeDP[i][1]=treeDP[i][2]=1000000000;
    }
    treeDP[n][0]=treeDP[n][1]=treeDP[n][2]=1000000000;
    visited[1]=true;
    makeTree(1);
    calcTree(1);
    cout<<treeDP[1][1]<<endl;
    return 0;
}
