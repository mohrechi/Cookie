#include <bits/stdc++.h>
const int MAXN = 500 + 10;
const int MAXM = 1000 + 10;

int n, m;
int w[MAXN], b[MAXM];
int order[MAXN];
bool visit[MAXM];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &w[i]);
    }
    n = 0;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &b[i]);
        if (!visit[b[i]])
        {
            visit[b[i]] = true;
            order[n++] = b[i];
        }
    }
    int total = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (order[j] == b[i])
            {
                for (int k = j; k > 0; --k)
                {
                    order[k] = order[k - 1];
                }
                order[0] = b[i];
                break;
            }
            total += w[order[j]];
        }
    }
    printf("%d\n", total);
    return 0;
}
