#include <cstdio>
#include <cstring>
static const int MAXN = 10000;
static const int MAXM = 12;

struct Edge
{
    int v, next;
}edge[MAXN*7];
int head[MAXN], edgeNumber;
int next[MAXN];
int totalLength, subLength[MAXM];
char str[MAXN], sub[MAXM][21];
bool dp[1<<MAXM];
int n, m;

void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

void getNext(int subIndex)
{
    next[0] = -1;
    for(int i=1,j=-1;i<subLength[subIndex];++i)
    {
        while(j!=-1 && sub[subIndex][j+1] != sub[subIndex][i])
        {
            j = next[j];
        }
        if(sub[subIndex][j+1] == sub[subIndex][i])
        {
            ++ j;
        }
        next[i] = j;
    }
}

void kmp(int subIndex)
{
    getNext(subIndex);
    for(int i=0,j=-1;i<totalLength;++i)
    {
        while(j!=-1 && sub[subIndex][j+1] != str[i])
        {
            j = next[j];
        }
        if(sub[subIndex][j+1] == str[i])
        {
            ++ j;
        }
        if(j == subLength[subIndex] - 1)
        {
            addEdge(i - subLength[subIndex] + 1, subIndex);
            j = next[j];
        }
    }
}

void dfs(int u, int status)
{
    if(status == ((1<<n)-1))
    {
        dp[status] = true;
        return;
    }
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(status&(1<<v))
        {
            continue;
        }
        if(dp[status|(1<<v)])
        {
            continue;
        }
        dp[status|(1<<v)] = true;
        dfs(u + subLength[v], status|(1<<v));
    }
}

int main()
{
    while(scanf("%d%d",&n,&m), n||m)
    {
        memset(head, -1, sizeof(head));
        edgeNumber = 0;
        totalLength = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%s", sub[i]);
            subLength[i] = strlen(sub[i]);
        }
        for(int i=0;i<m;++i)
        {
            scanf("%s", str + totalLength);
            totalLength = strlen(str);
        }
        for(int i=0;i<n;++i)
        {
            kmp(i);
        }
        int ans = 0;
        for(int i=0;i<totalLength;++i)
        {
            memset(dp, false, sizeof(dp));
            dp[0] = true;
            dfs(i, 0);
            ans += dp[(1<<n)-1];
        }
        printf("%d\n", ans);
    }
    return 0;
}
