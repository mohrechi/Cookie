#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int k[MAXN], w[MAXN];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &k[i]);
        }
        for(int i=0;i<n;++i)
        {
            scanf("%d", &w[i]);
        }
        sort(k, k + n);
        sort(w, w + n);
        double ans = 0.0;
        for(int i=0;i<n;++i)
        {
            ans += (k[i] + 1) * w[i] * 0.5;
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
