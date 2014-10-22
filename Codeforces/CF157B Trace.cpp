#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const double PI = acos(-1.0);

int n;
double r[MAXN];

int main()
{
    while(~scanf("%d", &n))
    {
        r[0] = 0.0;
        for(int i=1;i<=n;++i)
        {
            scanf("%lf", &r[i]);
        }
        sort(r, r + n + 1);
        double ans = 0.0;
        for(int i=n;i>0;i-=2)
        {
            ans += r[i] * r[i] - r[i - 1] * r[i - 1];
        }
        ans *= PI;
        printf("%lf\n", ans);
    }
    return 0;
}
