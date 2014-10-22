#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 300010;

int n, b[MAXN], bb[MAXN];

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &b[i]);
        }
        sort(b, b + n);
        bb[n - 1] = b[n - 1] + 1;
        for (int i = n - 2; i >= 0; --i)
        {
            bb[i] = max(bb[i + 1], b[i] + n - i);
        }
        int ans = 1;
        for (int i = 0; i < n - 1; ++i)
        {
            if (b[i] + n >= bb[i])
            {
                ++ ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
