#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m;
struct Edge
{
    int v, s, t, i;
    bool operator <(const Edge &edge) const
    {
        if (s == edge.s)
        {
            return t < edge.t;
        }
        return s < edge.s;
    }
};
vector<Edge> edge[MAXN];
int start_pos, end_pos, start_time, end_time;
int last[MAXN], path[MAXN];

int findStart(vector<Edge> &edge, int time)
{
    int start = -1;
    int l = 0, r = edge.size() - 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (edge[mid].s >= time)
        {
            if (start == -1 || mid < start)
            {
                start = mid;
            }
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return start;
}

bool dfs(int u, int time, int depth)
{
    if (u == end_pos && time <= end_time)
    {
        printf("%d\n", depth);
        for (int i = 0; i < depth; ++i)
        {
            if (i)
            {
                putchar(' ');
            }
            printf("%d", path[i]);
        }
        putchar('\n');
        return true;
    }
    int temp = last[u];
    last[u] = time;
    int start = findStart(edge[u], time);
    if (start == -1)
    {
        return false;
    }
    for (int i = start; i < edge[u].size(); ++i)
    {
        int v = edge[u][i].v;
        int s = edge[u][i].s;
        int t = edge[u][i].t;
        if (s >= temp)
        {
            break;
        }
        if (t < last[v])
        {
            path[depth] = edge[u][i].i;
            if (dfs(v, t, depth + 1))
            {
                return true;
            }
        }
    }
    last[u] = temp;
    return false;
}

int main()
{
    int u, v, s, t;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d%d", &u, &v, &s, &t);
        edge[u].push_back({v, s, t, i + 1});
    }
    for (int i = 1; i <= n; ++i)
    {
        sort(edge[i].begin(), edge[i].end());
    }
    scanf("%d%d%d%d", &start_pos, &end_pos, &start_time, &end_time);
    memset(last, 0x3f, sizeof(last));
    if (!dfs(start_pos, start_time, 0))
    {
        puts("Impossible");
    }
    return 0;
}
