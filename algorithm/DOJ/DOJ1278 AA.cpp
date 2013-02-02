#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;

int n;
long long a[MAXN], b[MAXN];

int main()
{
    long long ans;
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%lld", &a[i]);
        }
        sort(a, a + n);
        for(int i=1;i<=(n>>1);++i)
        {
            b[i] = b[n - i] = i * (n - i);
        }
        ans = 0;
        for(int i=1;i<n;++i)
        {
            ans += b[i] * (a[i] - a[i - 1]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
