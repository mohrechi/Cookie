#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;

int n;
double alpha, beta, vmax, fuel;
double slope[MAXN], length[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lf%lf%lf%lf", &alpha, &beta, &vmax, &fuel);
        scanf("%d", &n);
        double x, y;
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf%lf", &x, &y);
            slope[i] = y / x;
            length[i] = sqrt(x * x + y * y) * 0.001;
        }
        double left = 0.0, right = vmax;
        double ans = 1e100;
        for (int k = 0; k < 100; ++k)
        {
            double mid = (left + right) * 0.5;
            double totalFuel = 0;
            for (int i = 0; i < n; ++i)
            {
                double cost = max(0.0, alpha * mid + beta * slope[i]);
                totalFuel += cost * length[i];
            }
            if (totalFuel <= fuel)
            {
                ans = mid;
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        if (ans < 1e50)
        {
            double totalTime = 0.0;
            for (int i = 0; i < n; ++i)
            {
                double cost = alpha * ans + beta * slope[i];
                if (cost < 0.0)
                {
                    double v = min(- beta * slope[i] / alpha, vmax);
                    totalTime += length[i] / v;
                }
                else
                {
                    totalTime += length[i] / ans;
                }
            }
            printf("%.6lf\n", totalTime);
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
