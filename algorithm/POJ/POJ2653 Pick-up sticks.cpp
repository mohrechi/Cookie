#include<stdio.h>

struct point
{
    double x,y;
};
struct stick
{
    point u,v;
}s[100005];

double cross(point &a, point &b, point &o)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

double min(double &a, double &b)
{
    return a<b?a:b;
}

double max(double &a, double &b)
{
    return a>b?a:b;
}

bool quick(stick &a, stick &b)
{
    return max(a.u.x, a.v.x)>min(b.u.x, b.v.x) and max(a.u.y, a.v.y)>min(b.u.y, b.v.y) and max(b.u.x, b.v.x)>min(a.u.x, a.v.x) and max(b.u.y, b.v.y)>min(a.u.y, a.v.y);
}

bool check(stick &a, stick &b)
{
    if(quick(a,b))
    {
        return cross(a.u,b.u,b.v)*cross(a.v,b.u,b.v)<-1e-8 and cross(b.u,a.u,a.v)*cross(b.v,a.u,a.v)<-1e-8;
    }
    return false;
}

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf%lf",&s[i].u.x,&s[i].u.y,&s[i].v.x,&s[i].v.y);
        }
        printf("Top sticks:");
        for(int i=1;i<n;i++)
        {
            int j;
            for(j=i+1;j<=n;j++)
            {
                if(check(s[i],s[j]))
                {
                    break;
                }
            }
            if(j==n+1)
            {
                printf(" %d,",i);
            }
        }
        printf(" %d.\n",n);
    }
    return 0;
}
