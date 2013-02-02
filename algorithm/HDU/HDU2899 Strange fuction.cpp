#include<stdio.h>
#include<math.h>

double get(double x, double y)
{
    return 6*x*x*x*x*x*x*x + 8*x*x*x*x*x*x + 7*x*x*x + 5*x*x - y * x;
}

double getDeep(double x, double y)
{
    return 42*x*x*x*x*x*x + 48*x*x*x*x*x + 21*x*x + 10*x - y;
}

int dblcmp(double x)
{
    if(fabs(x)<1e-8)
    {
        return 0;
    }
    return x>0?1:-1;
}

double find(double y)
{
    double left = 0.0;
    double right = 100.0;
    double mid;
    while(dblcmp(left-right))
    {
        mid = (left + right) * 0.5;
        if(getDeep(mid,y)<0)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    return (left + right) * 0.5;
}

int main(int argc, char* argv[])
{
    int t;
    double y;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&y);
        if(getDeep(0.0, y) > 0.0)
        {
            printf("%.4lf\n", get(0.0, y));
        }
        else if(getDeep(100.0, y) < 0.0)
        {
            printf("%.4lf\n", get(100.0, y));
        }
        else
        {
            printf("%.4lf\n", get(find(y),y));
        }
    }
    return 0;
}
