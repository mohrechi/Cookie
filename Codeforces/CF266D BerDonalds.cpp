#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200 + 10;

int n, m;
int dist[MAXN][MAXN];
bool path[MAXN][MAXN];

struct Node
{
    int distU, distV;
    bool operator <(const Node &node) const
    {
        if (distU == node.distU)
        {
            return distV < node.distV;
        }
        return distU < node.distU;
    }
} node[MAXN];

int main()
{
    int u, v, w;
    scanf("%d%d", &n, &m);
    memset(dist, 0x3f, sizeof(dist));
    memset(path, false, sizeof(path));
    while (m--)
    {
        scanf("%d%d%d", &u, &v, &w);
        dist[u][v] = dist[v][u] = w;
        path[u][v] = path[v][u] = true;
    }
    for (int i = 1; i <= n; ++i)
    {
        dist[i][i] = 0;
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    double ans = 1e100;
    node[0].distU = -1;
    node[0].distV = 0x3f3f3f3f;
    for (int u = 1; u <= n; ++u)
    {
        for (int v = u + 1; v <= n; ++v)
        {
            if (!path[u][v])
            {
                continue;
            }
            for (int i = 1; i <= n; ++i)
            {
                node[i].distU = dist[u][i];
                node[i].distV = dist[v][i];
            }
            sort(node + 1, node + n + 1);
            m = 0;
            int maxV = 0;
            for (int i = 1; i <= n; ++i)
            {
                maxV = max(maxV, node[i].distV);
                while (node[i].distU >= node[m].distU && node[i].distV >= node[m].distV)
                {
                    --m;
                }
                node[++m] = node[i];
            }
            ans = min(ans, (double)maxV);
            for (int i = 1; i < m; ++i)
            {
                if (node[i + 1].distV < node[i].distV)
                {
                    ans = min(ans, node[i].distU + (dist[u][v] + node[i + 1].distV - node[i].distU) * 0.5);
                }
            }
            ans = min(ans, (double)node[m].distU);
        }
    }
    printf("%.1f\n", ans);
    return 0;
}
