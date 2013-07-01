#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
const int N = 10010;
const int M = 50010;
int n,m, head[N],fhead[N];
struct node
{
    int to,next;
    int fto, fnext;
};
node edge[M];

bool vis[N];
int fa[N];
int num[N];
int sig;
int outnum[N];
int cnt[N];
void dfsone(int cur)
{
    vis[cur] = true;
    for(int i = head[cur]; i != -1; i = edge[i].next)
    {
        if(!vis[edge[i].to])
        {
            dfsone(edge[i].to);
        }
    }
    num[sig++] = cur;
    return ;
}
void dfstwo(int cur, int fat)
{
    cnt[fat]++;
    vis[cur] = true;
    fa[cur] = fat;
    for(int i = fhead[cur]; i != -1; i = edge[i].fnext)
    {
        if(!vis[edge[i].fto])
        {
            dfstwo(edge[i].fto, fat);
        }
    }
}
int main()
{
    while(~scanf("%d %d", &n, &m))
    {
        memset(head,-1,sizeof(head));
        memset(fhead, - 1, sizeof(fhead));
        for(int i = 0; i < m; i++)
        {
            int a,b; scanf("%d %d", &a, &b);
            edge[i].to = b; edge[i].next = head[a];
            head[a] = i;
            edge[i].fto = a; edge[i].fnext = fhead[b];
            fhead[b] = i;
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 1; i <= n; i++)fa[i] = i;
        sig = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!vis[i]) dfsone(i);
        }
        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));

        sig = 1;
        for(int i = n-1; i >= 0; i--)
        {
            if(!vis[num[i]])
            {
                dfstwo(num[i], sig++);
            }
        }

        memset(outnum, 0, sizeof(outnum));
        for(int i = 1; i <= n; i++)
        {
            for(int j = head[i]; j != -1; j = edge[j].next)
            {
                if(fa[i] != fa[edge[j].to])
                outnum[fa[i]]++;
            }
        }
        int znum = 0;
        int ans = n;
        for(int i = 1; i < sig; i++)
        {
            if(!outnum[i]) { znum++;  ans = cnt[i];}
            if(znum > 1) { ans = 0;break;}
        }
        printf("%d\n", ans);
    }
    return 0 ;
}
