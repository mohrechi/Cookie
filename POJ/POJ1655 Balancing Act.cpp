#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int caseNum, n, minNum, treeDP[20005], answer;
bool visited[20005];
vector<int> conn[200005];

int calcTree(int x)
{
    int maxNum=0;
    for(int i=0;i<conn[x].size();++i)
    {
        if(!visited[conn[x][i]])
        {
            visited[conn[x][i]]=true;
            treeDP[x]+=calcTree(conn[x][i]);
            maxNum=max(maxNum, treeDP[conn[x][i]]);
        }
    }
    maxNum=max(maxNum, n-treeDP[x]);
    if(maxNum<minNum)
    {
        minNum=maxNum;
        answer=x;
    }
    return treeDP[x];
}

int main()
{
    int x,y;
    scanf("%d",&caseNum);
    while(caseNum--)
    {
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
        {
            conn[i].clear();
            visited[i]=false;
            treeDP[i]=1;
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            conn[x].push_back(y);
            conn[y].push_back(x);
        }
        visited[1]=true;
        minNum=1000000000;
        calcTree(1);
        printf("%d %d\n",answer,minNum);
    }
    return 0;
}
