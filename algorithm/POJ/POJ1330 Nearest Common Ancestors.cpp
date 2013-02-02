#include<stdio.h>
#include<vector>
using namespace std;

vector<int> tree[10005];
bool haveFather[10005],visited[10005];
int answer[10005],result;

bool dfs1(int x, int target)
{
    if(x==target) return true;
    for(int i=0;i<tree[x].size();i++)
    {
        if(!visited[tree[x][i]])
        {
            visited[tree[x][i]]=true;
            if(dfs1(tree[x][i], target))
            {
                return true;
            }
            visited[tree[x][i]]=false;
        }
    }
    return false;
}

bool dfs2(int depth, int x, int target)
{
    if(x==target)
    {
        for(int i=0;i<depth;i++)
        {
            if(visited[answer[i]])
            {
                result=answer[i];
            }
        }
        return true;
    }
    for(int i=0;i<tree[x].size();i++)
    {
        answer[depth]=tree[x][i];
        if(dfs2(depth+1, tree[x][i], target))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int caseNum, nodeNum;
    int x, y, root;
    scanf("%d",&caseNum);
    while(caseNum--)
    {
        scanf("%d",&nodeNum);
        for(int i=1;i<=nodeNum;i++)
        {
            tree[i].clear();
            haveFather[i]=false;
            visited[i]=false;
        }
        for(int i=1;i<nodeNum;i++)
        {
            scanf("%d%d",&x,&y);
            tree[x].push_back(y);
            haveFather[y]=true;
        }
        root=1;
        while(haveFather[root]) ++root;
        scanf("%d%d",&x,&y);
        visited[root]=true;
        answer[0]=root;
        dfs1(root, x);
        dfs2(1, root, y);
        printf("%d\n",result);
    }
    return 0;
}
