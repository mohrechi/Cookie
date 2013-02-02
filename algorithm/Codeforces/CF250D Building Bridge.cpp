#include <cmath>
#include <cstdio>
#include <cstring>
const int MAXN = 100005;

int n, m;
double A, B;
double a[MAXN];
double b[MAXN];
double L[MAXN];

double getLen(double a, double b, double c, double d)
{
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

double getLen(int i, int j)
{
    return sqrt(a[i] * a[i] + A * A) + getLen(A, a[i], B, b[j]) + L[j];
}

int main()
{
    while(~scanf("%d%d%lf%lf", &n, &m, &A, &B))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%lf", &a[i]);
        }
        for(int i=1;i<=m;++i)
        {
            scanf("%lf", &b[i]);
        }
        for(int i=1;i<=m;++i)
        {
            scanf("%lf", &L[i]);
        }
        double ans = 1e100;
        int nn, mm;
        for(int i=1;i<=m;++i)
        {
            int l = 1, r = n;
            double ml = 1e100;
            int pos;
            while(l <= r)
            {
                int mid = (l + r) >> 1;
                int ll = (l + mid) >> 1;
                int rr = (r + mid + 1) >> 1;
                double lll = getLen(ll, i);
                double lrr = getLen(rr, i);
                if(lll > lrr)
                {
                    l = ll + 1;
                    if(lrr < ml)
                    {
                        ml = lrr;
                        pos = rr;
                    }
                }
                else
                {
                    r = rr - 1;
                    if(lll < ml)
                    {
                        ml = lll;
                        pos = ll;
                    }
                }
            }
            if(ml < ans)
            {
                ans = ml;
                nn = pos;
                mm = i;
            }
        }
        printf("%d %d\n", nn, mm);
    }
    return 0;
}
