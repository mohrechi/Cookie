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

void solve(double r)
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
}

double dist(const Point &p1, const Point &p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main(int argc, char *argv[])
{
    double r;
    scanf("%d%lf",&pointNumber,&r);
    for(int i=1;i<=pointNumber;++i)
    {
        scanf("%lf%lf",&points[i].x, &points[i].y);
    }
    points[pointNumber+1]=points[1];
    solve(r);
    int ansx = 0,ansy = 0;
    double res = 0;
    for(int i=1;i<=cutPointNumber;++i)
    {
        for(int j=i+1;j<=cutPointNumber;++j)
        {
            double tmp = dist(p[i],p[j]);
            if(tmp > res)
            {
                res = tmp;
                ansx = i;
                ansy = j;
            }
        }
    }
    printf("%.4lf %.4lf %.4lf %.4lf\n",p[ansx].x,p[ansx].y,p[ansy].x,p[ansy].y);
    return 0;
}
