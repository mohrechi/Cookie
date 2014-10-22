#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e6 + 10;

int n;
char s[MAXN];

bool judge(int x)
{
    int cur = 0, lastMax = 0;
    for (int i = 0; s[i]; ++i)
    {
        if (s[i] == 'L')
        {
            --cur;
            if (cur == x)
            {
                ++cur;
            }
        }
        else
        {
            ++cur;
            if (i == n - 1)
            {
                return cur > lastMax;
            }
            lastMax = max(lastMax, cur);
        }
    }
}

int main()
{
    scanf("%s", s);
    n = strlen(s);
    if (s[n - 1] == 'L')
    {
        for (int i = 0; i < n; ++i)
        {
            s[i] = s[i] == 'L' ? 'R' : 'L';
        }
    }
    int l = -n, r = -1, mid, ans = 0;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (judge(mid))
        {
            r = mid - 1;
            ans = min(ans, mid);
        }
        else
        {
            l = mid + 1;
        }
    }
    ans = -ans;
    printf("%d\n", ans == n ? 1 : ans);
    return 0;
}
