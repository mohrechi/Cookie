#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
int n, m;
bool h[MAXN], v[MAXN];

int main()
{
    int x, y;
    while (~scanf("%d%d", &n, &m))
    {
        memset(h, true, sizeof(h));
        memset(v, true, sizeof(v));
        h[1] = h[n] = false;
        v[1] = v[n] = false;
        while (m--)
        {
            scanf("%d%d", &x, &y);
            h[x] = v[y] = false;
        }
        int total = 0;
        for (int i = 1; i <= n; ++i)
        {
            total += h[i];
            total += v[i];
        }
        if (n & 1)
        {
            total -= h[(n >> 1) + 1] && v[(n >> 1) + 1];
        }
        printf("%d\n", total);
    }
    return 0;
}
