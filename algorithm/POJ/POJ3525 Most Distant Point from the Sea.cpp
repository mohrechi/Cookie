#include <cstdio>
#include <cmath>
static const double eps = 1e-8;
static const int MAXN = 105;
struct Point
{
    double x,y;
};
Point points[MAXN],p[MAXN],q[MAXN];
int pointNumber, cutPointNumber;

int dblcmp(double x)
{
    if(fabs(x) < eps)
    {
        return 0;
    }
    return x>0?1:-1;
}

void getline(Point x, Point y, double &a, double &b, double &c)
{
    a = y.y - x.y;
    b = x.x - y.x;
    c = y.x * x.y - x.x * y.y;
}

void initial()
{
    for(int i=1;i<=pointNumber;++i)
    {
        p[i] = points[i];
    }
    p[pointNumber+1] = p[1];
    p[0] = p[pointNumber];
    cutPointNumber = pointNumber;
}

Point intersect(Point x, Point y, double a, double b, double c)
{
    double u = fabs(a * x.x + b * x.y + c);
    double v = fabs(a * y.x + b * y.y + c);
    Point pt;
    pt.x=(x.x * v + y.x * u) / (u + v);
    pt.y=(x.y * v + y.y * u) / (u + v);
    return  pt;
}

void cut(double a,double b ,double c)
{
    int curCnt = 0;
    for(int i=1;i<=cutPointNumber;++i)
    {
        if(a*p[i].x + b*p[i].y + c >= 0)
        {
            q[++curCnt] = p[i];
        }
        else
        {
            if(a*p[i-1].x + b*p[i-1].y + c > 0)
            {
                q[++curCnt] = intersect(p[i],p[i-1],a,b,c);
            }
            if(a*p[i+1].x + b*p[i+1].y + c > 0)
            {
                q[++curCnt] = intersect(p[i],p[i+1],a,b,c);
            }
        }
    }
    for(int i = 1; i <= curCnt; ++i)
    {
        p[i] = q[i];
    }
    p[curCnt+1] = q[1];
    p[0] = p[curCnt];
    cutPointNumber = curCnt;
}

bool solve(double r)
{
    initial();
    for(int i=1;i<=pointNumber;++i)
    {
        Point ta, tb, tt;
        tt.x = points[i+1].y - points[i].y;
        tt.y = points[i].x - points[i+1].x;
        double k = r / sqrt(tt.x * tt.x + tt.y * tt.y);
        tt.x = tt.x * k;
        tt.y = tt.y * k;
        ta.x = points[i].x + tt.x;
        ta.y = points[i].y + tt.y;
        tb.x = points[i+1].x + tt.x;
        tb.y = points[i+1].y + tt.y;
        double a,b,c;
        getline(ta,tb,a,b,c);
        cut(a,b,c);
    }
    return cutPointNumber > 0;
}

double getArea(Point *pArray, int pNumber)
{
    double area = 0;
    for(int i=1;i<=pNumber;++i)
    {
        area += pArray[i].x * pArray[i+1].y - pArray[i].y * pArray[i+1].x;
    }
    return area / 2.0;
}

int main(int argc, char *argv[])
{
    while(scanf("%d",&pointNumber), pointNumber)
    {
        for(int i=1;i<=pointNumber;++i)
        {
            scanf("%lf%lf",&points[i].x, &points[i].y);
        }
        Point temp;
        for(int i=1;i<(pointNumber+1)>>1;++i)
        {
            temp = points[i];
            points[i] = points[pointNumber - i];
            points[pointNumber - i] = temp;
        }
        points[pointNumber+1]=points[1];
        double high = 10000000, low = 0,mid;
        while(dblcmp(high - low) > 0)
        {
            mid = (high + low) * 0.5;
            if(solve(mid))
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
        printf("%.6lf\n",high);
    }
    return 0;
}
