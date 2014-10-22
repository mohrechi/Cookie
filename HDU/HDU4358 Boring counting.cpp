#pragma comment(linker, "/STACK:102400000,102400000")

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 100010;

struct Edge
{
    int v, next;
}edge[MAXN * 2];
int edgeNumber, head[MAXN];

inline void initEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(const int &u, const int &v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

int n, k, a[MAXN];
map<int, int> cnt[MAXN];
int ans[MAXN], use[MAXN];

void addNumber(int u, int x, int time)
{
    if(cnt[use[u]].find(x) == cnt[use[u]].end())
    {
        cnt[use[u]][x] = time;
        if(time == k)
        {
            ++ ans[u];
        }
    }
    else
    {
        if(cnt[use[u]][x] == k)
        {
            -- ans[u];
        }
        else if(cnt[use[u]][x] == k - time)
        {
            ++ ans[u];
        }
        cnt[use[u]][x] = cnt[use[u]][x] + time;
    }
}

void dfs(int u, int father)
{
    ans[u] = 0;
    bool flag = true;
    int maxSize = 0, index;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(v != father)
        {
            flag = false;
            dfs(v, u);
            if(cnt[use[v]].size() > maxSize)
            {
                maxSize = cnt[use[v]].size();
                index = v;
            }
        }
    }
    if(flag)
    {
        cnt[u].clear();
        cnt[u][a[u]] = 1;
        if(k == 1)
        {
            ++ ans[u];
        }
        use[u] = u;
    }
    else
    {
        use[u] = use[index];
        ans[u] = ans[index];
        addNumber(u, a[u], 1);
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            if(v != father && v != index)
            {
                for(map<int, int>::iterator it=cnt[use[v]].begin();it!=cnt[use[v]].end();++it)
                {
                    addNumber(u, it->first, it->second);
                }
            }
        }
    }
}

int main()
{
    int caseNumber, u, v, q;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        if(cas > 1)
        {
            printf("\n");
        }
        scanf("%d%d", &n, &k);
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &a[i]);
        }
        initEdge();
        for(int i=1;i<n;++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        scanf("%d", &q);
        dfs(1, -1);
        printf("Case #%d:\n", cas);
        while(q--)
        {
            scanf("%d", &u);
            printf("%d\n", ans[u]);
        }
    }
    return 0;
}
