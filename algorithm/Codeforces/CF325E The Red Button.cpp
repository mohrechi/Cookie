#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;

int n, ans[MAXN];
bool visit[MAXN];

int main()
{
    while (~scanf("%d", &n))
    {
        if (n & 1)
        {
            printf("-1");
            continue;
        }
        memset(visit, false, sizeof(bool) * (n + 1));
        ans[n] = 0;
        for (int i = n; i > 0; --i)
        {
            visit[ans[i]] = true;
            ans[i - 1] = (ans[i] >> 1);
            if (!visit[ans[i] ^ 1])
            {
                ans[i - 1] += n >> 1;
            }
        }
        for (int i = 0; i <= n; ++i)
        {
            if (i)
            {
                printf(" ");
            }
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
