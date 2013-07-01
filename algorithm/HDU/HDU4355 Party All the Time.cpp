#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 50010;
const double INF = 1e10;
const double eps = 2e-4;

int n;
double x[MAXN];
double w[MAXN];

double getTotal(double pos)
{
    double total = 0.0;
    double err;
    for(int i=0;i<n;++i)
    {
        err = fabs(x[i] - pos);
        total += w[i] * err * err * err;
    }
    return total;
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            scanf("%lf%lf", &x[i], &w[i]);
        }
        double l = x[0];
        double r = x[n-1];
        while(r - l > eps)
        {
            double ll = (l * 2 + r) / 3;
            double rr = (l + r * 2) / 3;
            if(getTotal(ll) > getTotal(rr))
            {
                l = ll;
            }
            else
            {
                r = rr;
            }
        }
        printf("Case #%d: %.0lf\n", cas, getTotal(l));
    }
    return 0;
}
