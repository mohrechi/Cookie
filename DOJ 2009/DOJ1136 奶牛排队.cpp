#include <cstdio>
#include <algorithm>
using namespace std;
static const int MAXN = 100005;

int a[MAXN];

int main()
{
    long long ans, temp;
    int n;
    while(~scanf("%d", &n))
    {
        ans = 0;
        temp = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for(int i=1;i<n;++i)
        {
            temp += (a[i] - a[i-1]) * i;
            ans += temp;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
