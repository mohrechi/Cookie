#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
const double PI = acos(-1.0);
const double eps = 1e-8;
int h[MAXN], n;
double angle;

int dblcmp(double x)
{
    if(fabs(x) < eps)
    {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

int main()
{
    while(~scanf("%d%lf",&n,&angle))
    {
        if(dblcmp(angle) > 0)
        {
            for(int i=n-1;i>=0;--i)
            {
                scanf("%d", &h[i]);
            }
        }
        else
        {
            angle = - angle;
            for(int i=0;i<n;++i)
            {
                scanf("%d", &h[i]);
            }
        }
        double ans = 0.0;
        double per = tan(angle * PI / 180.0);
        int left = 0;
        double sum = 0.0;
        for(int i=1;i<n;++i)
        {
            if(dblcmp(h[i] - h[left] - per * (i - left)) >= 0)
            {
                sum += (i - left) * (i - left) * per * 0.5;
                ans += sum;
                sum = 0;
                left = i;
            }
            else
            {
                sum += h[left] - h[i];
            }
        }
        int right = n-1;
        sum = 0.0;
        for(int i=n-2;i>=0;--i)
        {
            if(dblcmp(h[i] - h[right] + per * (right - i - 1)) >= 0)
            {
                sum -= (right - i - 1.0) * (right - i - 1.0) * per * 0.5;
                ans += sum;
                sum = 0;
                right = i;
            }
            else if(dblcmp(h[i] - h[right] + per * (right - i)) > 0)
            {
                double x = (h[right] - h[i]) / per;
                double w = right - i - 1;
                sum += (x - w) * (h[right] - h[i]);
                sum -= x * (h[right] - h[i]) * 0.5;
                ans += sum;
                sum = 0;
                right = i;
            }
            else if(dblcmp(h[i] - h[right] + per * (right - i)) == 0)
            {
                right = i;
                sum = 0.0;
            }
            else
            {
                sum += h[right] - h[i];
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
