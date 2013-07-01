#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int n, treeDP[1600][2];
bool visited[1600];
vector<int>connection[1600];

void calcTree(int x)
{
    for(int i=0;i<connection[x].size();++i)
    {
        if(!visited[connection[x][i]])
        {
            visited[connection[x][i]]=true;
            calcTree(connection[x][i]);
        }
    }
    for(int i=0;i<connection[x].size();++i)
    {
        treeDP[x][0]+=treeDP[connection[x][i]][1];
        treeDP[x][1]+=min(treeDP[connection[x][i]][0], treeDP[connection[x][i]][1]);
    }
}

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            visited[i]=false;
            treeDP[i][0]=0;
            treeDP[i][1]=1;
            connection[i].clear();
        }
        int node, edgeNum, target, root;
        for(int i=0;i<n;i++)
        {
            scanf("%d:(%d)",&node,&edgeNum);
            if(!i) root=node;
            while(edgeNum--)
            {
                scanf("%d",&target);
                connection[node].push_back(target);
            }
        }
        visited[root]=true;
        calcTree(root);
        printf("%d\n",min(treeDP[root][0], treeDP[root][1]));
    }
    return 0;
}
