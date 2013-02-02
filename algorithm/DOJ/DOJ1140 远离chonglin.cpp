#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 10005;

struct Vector
{
    double x, y;

    inline void init()
    {
        x = 0.0;
        y = 0.0;
    }

    inline void input()
    {
        scanf("%lf%lf", &x, &y);
    }

    double length() const
    {
        return sqrt(x * x + y * y);
    }
} vec[MAXN * 2], sum[MAXN * 2];

bool operator < (const Vector &a, const Vector &b)
{
    return a.x * b.y > a.y * b.x;
}

Vector operator + (const Vector &a, const Vector &b)
{
    Vector c;
    c.x = a.x + b.x;
    c.y = a.y + b.y;
    return c;
}

Vector operator - (const Vector &a, const Vector &b)
{
    Vector c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    return c;
}

Vector operator * (const Vector &a, const double b)
{
    Vector c;
    c.x = a.x * b;
    c.y = a.y * b;
    return c;
}

double operator * (const Vector &a, const Vector &b)
{
    return a.x * b.x + a.y * b.y;
}

double getAngle(const Vector &a, const Vector &b, const Vector &c)
{
    Vector aa = a - c;
    Vector bb = b - c;
    return acos(aa * bb / aa.length() / bb.length());
}

double getDist(const Vector &a, const Vector &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool judge(const Vector &a, const Vector &b)
{
    return a.x * b.y >= a.y * b.x;
}

int main()
{
    int n;
    Vector source;
    while(~scanf("%d", &n))
    {
        source.input();
        vec[0] = source;
        for(int i=1;i<=n;++i)
        {
            vec[i].input();
        }
        ++ n;
        sort(vec, vec + n);
        Vector total;
        total.init();
        for(int i=0;i<n;++i)
        {
            total = total + vec[i];
        }
        for(int i=0;i<n;++i)
        {
            vec[i + n] = vec[i];
        }
        sum[0] = vec[0];
        for(int i=1;i<(n<<1);++i)
        {
            sum[i] = sum[i - 1] + vec[i];
        }
        int start = 0, end = 0;
        Vector ans;
        ans.init();
        while(start < n)
        {
            if(end < start)
            {
                end = start;
            }
            while(end + 1 < start + n && judge(vec[start], vec[end + 1]))
            {
                ++ end;
            }
            Vector cut = sum[end] - sum[start] + vec[start];
            Vector temp = cut * 2 - total;
            if(temp.length() > ans.length())
            {
                ans = temp;
            }
            ++ start;
        }
        printf("%.3lf\n", ans.length());
    }
    return 0;
}
