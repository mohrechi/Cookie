#include<stdio.h>
#include<math.h>
struct point
{
    double x,y;
}p1[50],p2[50];
double max(double a, double b)
{
    return a>b?a:b;
}
int dblcmp(double r)
{
    if(fabs(r)<1e-6)
    {
        return 0;
    }
    return r>0?1:-1;
}
int cross(point &a, point &b, point &o)
{
    return dblcmp((a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x));
}
bool check(point a, point b, point c, point d)
{
    return cross(a,b,c)*cross(a,b,d)<=0;
}
double getx(point &a, point &b, point &c, point &d)
{
    double k1,k2;
    k1=(b.y-a.y)/(b.x-a.x);
    k2=(d.y-c.y)/(d.x-c.x);
    return (c.y-a.y+k1*a.x-k2*c.x)/(k1-k2);
}
double getmaxx(point &a, point &b, int n)
{
    int i=0;
    double ans=-1e10;
    while(i<n and check(a,b,p1[i],p2[i]))
    {
        i++;
    }
    if(i==0)
    {
        return -1e10;
    }
    if(i==n)
    {
        return p1[n-1].x;
    }
    if(check(a,b,p1[i-1],p1[i]))
    {
        ans=max(getx(a,b,p1[i-1],p1[i]),ans);
    }
    if(check(a,b,p2[i-1],p2[i]))
    {
        ans=max(getx(a,b,p2[i-1],p2[i]),ans);
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p1[i].x,&p1[i].y);
            p2[i].x=p1[i].x, p2[i].y=p1[i].y-1;
        }
        double maxx=-1e10;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                maxx=max(maxx,getmaxx(p1[i],p2[j],n));
                maxx=max(maxx,getmaxx(p2[i],p1[j],n));
                if(fabs(maxx-p1[n-1].x)<1e-8)
                {
                    flag=true;
                    break;
                }
            }
            if(flag)
            {
                break;
            }
        }
        if(flag)
        {
            printf("Through all the pipe.\n");
        }
        else
        {
            printf("%.2lf\n",maxx);
        }
    }
    return 0;
}
