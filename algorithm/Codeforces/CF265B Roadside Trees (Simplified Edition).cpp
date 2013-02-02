#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int n, a[MAXN];

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
        }
        int ans = n + n - 1, h = 0;
        for(int i=0;i<n;++i)
        {
            ans += abs(h - a[i]);
            h = a[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
