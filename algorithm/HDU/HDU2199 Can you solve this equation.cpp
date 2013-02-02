#include<stdio.h>
#include<math.h>

double get(double x)
{
    return 8*x*x*x*x + 7*x*x*x + 2*x*x + 3*x + 6;
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
        if(get(mid)<y)
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
        if(y<get(0.0) || y>get(100.0))
        {
            printf("No solution!\n");
        }
        else
        {
            printf("%.4lf\n", find(y));
        }
    }
    return 0;
}
