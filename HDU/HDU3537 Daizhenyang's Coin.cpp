#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;

int getSG(int n)
{
    int t = n, cnt = 0;
    while (t)
    {
        cnt += t & 1;
        t >>= 1;
    }
    if (cnt & 1) return n << 1;
    else return (n << 1) + 1;
}


int main()
{
    int n, a[MAXN];
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i == 0 || a[i] != a[i - 1])
            {
                ans ^= getSG(a[i]);
            }
        }
        puts(ans ? "No" : "Yes");
    }
    return 0;
}
