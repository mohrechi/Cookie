#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 205;
const double eps = 1e-8;

struct Point
{
    double x,y;
    inline void input()
    {
        scanf("%lf%lf", &x, &y);
    }
    inline void output()
    {
        printf("%.2lf %.2lf\n", x, y);
    }
} point[MAXN], temp;
int n, m;

double dblcmp(double r)
{
    if(fabs(r)<eps) return 0;
    return r>0?1:-1;
}

double multiply(Point a, Point b, Point o)
{
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}

double dist(Point a, Point b)
{
    return (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y);
}

bool grahamCompare(const Point &a, const Point &b)
{
    if(a.y == b.y) return a.x<b.x;
    return a.y<b.y;
}

int stack[MAXN];
int top;

void grahamScan()
{
    sort(point, point + n, grahamCompare);
    stack[0] = 0, stack[1] = 1, top = 2;
    for(int i=2;i<n;i++)
    {
        while(top > 1 && dblcmp(multiply(point[stack[top-1]], point[stack[top-2]], point[i]))<0)
        {
            --top;
        }
        stack[top++] = i;
    }
    int temp = top;
    stack[top++] = n-2;
    for(int i=n-3;i>=0;i--)
    {
        while(top > temp &&
        dblcmp(multiply(point[stack[top-1]], point[stack[top-2]], point[i]))<0)
        {
            --top;
        }
        stack[top++] = i;
    }
}

bool inside()
{
    int dir = dblcmp(multiply(point[stack[0]], point[stack[1]], temp));
    if(dir == 0)
    {
        return true;
    }
    for(int i=2;i<top;++i)
    {
        if(dir != dblcmp(multiply(point[stack[i-1]], point[stack[i]], temp)))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;++i)
        {
            point[i].input();
        }
        grahamScan();
        for(int i=0;i<m;++i)
        {
            temp.input();
            if(inside())
            {
                printf("danger!\n");
            }
            else
            {
                printf("safe!\n");
            }
        }
    }
    return 0;
}
