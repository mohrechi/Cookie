#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
#define MAXN 205

int n,m;
char s[MAXN][MAXN];
bool visit[MAXN][MAXN];
struct Node
{
    int x,y,time;
    friend bool operator < (const Node a, const Node b)
    {
        return a.time > b.time;
    }
};
int stepX[4] = {-1,0,1,0};
int stepY[4] = {0,-1,0,1};

int main(int argc, char *argv[])
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                s[i][j] = '#';
                visit[i][j] = false;
            }
        }
        priority_queue<Node> que;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",s[i]+1);
            for(int j=1;j<=m;j++)
            {
                if(s[i][j] == 'r')
                {
                    Node node;
                    node.x = i;
                    node.y = j;
                    node.time = 0;
                    que.push(node);
                    visit[i][j] = true;
                }
            }
        }
        bool flag = false;
        while(!que.empty() && !flag)
        {
            Node t = que.top();
            for(int k=0;k<4;k++)
            {
                int tx = t.x + stepX[k];
                int ty = t.y + stepY[k];
                if(!visit[tx][ty])
                {
                    visit[tx][ty] = true;
                    if(s[tx][ty] == '.')
                    {
                        Node node;
                        node.x = tx;
                        node.y = ty;
                        node.time = t.time + 1;
                        que.push(node);
                    }
                    else if(s[tx][ty] == 'x')
                    {
                        Node node;
                        node.x = tx;
                        node.y = ty;
                        node.time = t.time + 2;
                        que.push(node);
                    }
                    else if(s[tx][ty] == 'a')
                    {
                        flag = true;
                        printf("%d\n",t.time + 1);
                        break;
                    }
                }
            }
            que.pop();
        }
        if(!flag)
        {
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        }
    }
    return 0;
}
