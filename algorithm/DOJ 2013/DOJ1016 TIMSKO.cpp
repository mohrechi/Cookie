#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int m, n, k;
    while (~scanf("%d%d%d", &m, &n, &k))
    {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (m >= i * 2 && m + n - i * 3 >= k)
            {
                ans = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
