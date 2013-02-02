#include<stdio.h>
#include<math.h>

struct point
{
    double x,y;
}p[205];
int n;

double cross(point a, point b, point c)
{
    return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

double equal(point a, point b)
{
    return fabs(a.x-b.x)<1e-8 and fabs(a.y-b.y)<1e-8;
}

bool check(point a, point b)
{
    if(equal(a,b))
    {
        return false;
    }
    for(int i=0;i<n;i+=2)
    {
        if(cross(p[i],a,b)*cross(p[i+1],a,b)>1e-8)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        n*=2;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        bool flag=false;
        for(int i=0;i<n and not flag;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(check(p[i],p[j]))
                {
                    flag=true;
                    break;
                }
            }
        }
        if(flag) printf("Yes!\n");
        else printf("No!\n");
    }
    return 0;
}
