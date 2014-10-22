#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const double eps = 1e-6;

int n, CF[15];

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
    while(scanf("%d", &n), n)
    {
        bool flag = false;
        for(int i=0;i<=n;++i)
        {
            scanf("%d", &CF[i]);
            flag |= i && CF[i];
        }
        if(flag)
        {
            double l = - 1.0, r = 1e6, mid;
            while(dblcmp(r - l) >= 0)
            {
                mid = (l + r) * 0.5;
                double IRR = 1.0;
                double sum = 0.0;
                for(int i=n;i>=0;--i)
                {
                    sum += CF[i] * IRR;
                    IRR *= (1.0 + mid);
                }
                if(dblcmp(sum) == 0)
                {
                    break;
                }
                if(sum < 0)
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }
            printf("%.2lf\n", mid);
        }
        else
        {
            printf("Too many\n");
        }
    }
    return 0;
}
