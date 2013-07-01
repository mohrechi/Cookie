#include <cstdio>
#include <cmath>
static const double eps = 1e-8;
static const int MAXN = 1505;
struct Point
{
    double x,y;
};
Point points[MAXN],p[MAXN],q[MAXN];
int pointNumber, cutPointNumber;

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

void solve()
{
    initial();
    for(int i=1;i<=pointNumber;++i)
    {
        double a,b,c;
        getline(points[i],points[i+1],a,b,c);
        cut(a,b,c);
    }
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
    int caseNumber;
    scanf("%d",&caseNumber);
    while(caseNumber--)
    {
        scanf("%d",&pointNumber);
        for(int i=1;i<=pointNumber;++i)
        {
            scanf("%lf%lf",&points[i].x, &points[i].y);
        }
        points[pointNumber+1]=points[1];
        solve();
        printf("%.2lf\n", fabs(getArea(p, cutPointNumber)));
    }
    return 0;
}
