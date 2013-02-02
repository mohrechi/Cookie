#include <cstdio>
#include <cstring>
const int MAXN = 20;
double p[MAXN];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%lf", &p[i]);
        }
        double ans = 0.0;
        for(int i=1;i<(1<<n);++i)
        {
            int cnt = 0;
            double sum = 0.0;
            for(int j=0;j<n;++j)
            {
                if(i&(1<<j))
                {
                    sum += p[j];
                    ++ cnt;
                }
            }
            if(cnt&1)
            {
                ans += 1.0 / sum;
            }
            else
            {
                ans -= 1.0 / sum;
            }
        }
        printf("%lf\n", ans);
    }
    return 0;
}
