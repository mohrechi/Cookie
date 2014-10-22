#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 205;
const double PI = acos(-1.0);
const double G = 9.8;
const double step = PI / 1000;

int main()
{
    int n;
    double h, l1, r1, l2, r2;
    double v[MAXN];
    while (scanf("%d", &n), n)
    {
        scanf("%lf%lf%lf%lf%lf", &h, &l1, &r1, &l2, &r2);
        for (int i = 0; i < n; ++i)
        {
            scanf("%lf", &v[i]);
        }
        int ans = 0;
        for (double angle = - PI / 2 + step; angle < PI / 2; angle += step)
        {
            bool flag = true;
            int count = 0;
            for (int i = 0; i < n; ++i)
            {
                double vx = v[i] * cos(angle);
                double vy = v[i] * sin(angle);
                double vt = sqrt(2 * G * h + vy * vy);
                double t = (vt - vy) / G;
                double s = vx * t;
                if (s >= l1 && s <= r1)
                {
                    ++count;
                }
                if (s >= l2 && s <= r2)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans = max(ans, count);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
