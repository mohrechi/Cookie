#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int T, ans;
    long long a, b, c, d, e, s, m;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &m);
        s = a + b + c + d + e;
        if (s >= m)
        {
            ans = 0;
        }
        else
        {
            if (s <= 0)
            {
                ans = -1;
            }
            else
            {
                ans = 0;
                while (s < m)
                {
                    ++ans;
                    s <<= 1;
                }
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
