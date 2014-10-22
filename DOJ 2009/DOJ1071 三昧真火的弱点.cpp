#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int n;
double sum1[MAXN], sum2[MAXN];

int main()
{
    while(~scanf("%d", &n))
    {
        sum1[0] = 0;
        sum2[0] = 0;
        double a;
        for(int i=1;i<=n;++i)
        {
            scanf("%lf", &a);
            sum1[i] = sum1[i - 1] + a;
            sum2[i] = sum2[i - 1] + a * a;
        }
        double ans = 0.0;
        for(int i=1;i<=n;++i)
        {
            for(int j=i;j<=n;++j)
            {
                double num = j - i + 1;
                double normsum = sum1[j] - sum1[i - 1];
                double sqrtsum = sum2[j] - sum2[i - 1];
                double cov = (sqrtsum - normsum * normsum / num) / num;
                ans = max(ans, cov);
            }
        }
        printf("%.0lf\n", ans);
    }
    return 0;
}
