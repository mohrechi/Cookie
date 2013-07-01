#include <cstdio>
#include <cstring>
const int DIMENTION = 5;
const int MAXN = 100005;
const double INF = 1e100;

struct Point
{
    double d[DIMENTION];
}point[MAXN];
int n;
double mind[1<<DIMENTION], maxd[1<<DIMENTION];

inline double min(double x, double y)
{
    return x < y ? x : y;
}

inline double max(double x, double y)
{
    return x > y ? x : y;
}



int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<DIMENTION;++j)
            {
                scanf("%lf", &point[i].d[j]);
            }
        }
        for(int i=0;i<(1<<DIMENTION);++i)
        {
            mind[i] = INF;
            maxd[i] = -INF;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<(1<<DIMENTION);++j)
            {
                double sum = 0.0;
                for(int k=0;k<DIMENTION;++k)
                {
                    if(j&(1<<k))
                    {
                        sum += point[i].d[k];
                    }
                    else
                    {
                        sum -= point[i].d[k];
                    }
                }
                mind[j] = min(mind[j], sum);
                maxd[j] = max(maxd[j], sum);
            }
        }
        double ans = -INF;
        for(int i=0;i<(1<<DIMENTION);++i)
        {
            ans = max(ans, maxd[i] - mind[i]);
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
