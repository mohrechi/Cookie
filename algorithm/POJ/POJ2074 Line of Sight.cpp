#include<stdio.h>
#include<math.h>
#include<stdlib.h>

const double eps=1e-6;
const int MAXN=110;

struct Point
{
    double x,y;
};

struct Segment
{
    Point u,v;
}house, line, obstruction[MAXN];

struct Edge
{
    double left,right;
}edge[MAXN];

double max(double a, double b)
{
    return a>b?a:b;
};

double min(double a, double b)
{
    return a<b?a:b;
}

int dblcmp(double r)
{
    if(fabs(r)<eps) return 0;
    return r>0?1:-1;
}

int cmp(const void* a, const void* b)
{
    return dblcmp((*(Edge*)a).left-(*(Edge*)b).left);
}

double cross(Point a, Point b, Point o)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

double inter(Segment a, Segment b)
{
    int d1=dblcmp(cross(a.u,b.u,b.v));
    int d2=dblcmp(cross(a.v,b.u,b.v));
    return d1*d2<=0;
}

double getX(Segment a, double y)
{
    if(a.v.x-a.u.x==0)
    {
        return a.u.x;
    }
    double k=(a.v.y-a.u.y)/(a.v.x-a.u.x);
    double b=a.u.y-k*a.u.x;
    return (y-b)/k;
}

void getInter(Segment a, double &left, double &right)
{
    Segment temp;
    temp.u.x=house.u.x, temp.u.y=house.u.y;
    temp.v.x=a.v.x, temp.v.y=a.v.y;
    right=getX(temp, line.v.y);
    temp.u.x=house.v.x, temp.u.y=house.v.y;
    temp.v.x=a.u.x, temp.v.y=a.u.y;
    left=getX(temp, line.u.y);
    left=min(max(left,line.u.x),line.v.x);
    right=max(min(right,line.v.x),line.u.x);
}

void compress(int n)
{
    double ans=line.v.x-line.u.x;
    double res=edge[0].left-line.u.x;
    double left=edge[0].left, right=edge[0].right;
    for(int i=0;i<n;i++)
    {
        if(edge[i].left<right)
        {
            right=max(edge[i].right,right);
        }
        else
        {
            ans-=right-left;
            res=max(edge[i].left-right,res);
            left=edge[i].left;
            right=edge[i].right;
        }
    }
    ans-=right-left;
    res=max(line.v.x-right,res);
    if(ans<eps)
    {
        printf("No View\n");
    }
    else
    {
        printf("%.2lf\n",res);
    }
}

int main()
{
    while(scanf("%lf%lf%lf",&house.u.x, &house.v.x, &house.u.y), house.u.x or house.v.x or house.u.y)
    {
        house.v.y=house.u.y;
        scanf("%lf%lf%lf",&line.u.x, &line.v.x, &line.u.y);
        line.v.y=line.u.y;
        int n;
        scanf("%d",&n);
        int i=0;
        while(i<n)
        {
            scanf("%lf%lf%lf",&obstruction[i].u.x, &obstruction[i].v.x, &obstruction[i].u.y);
            if(obstruction[i].u.y>=house.u.y or obstruction[i].u.y<line.u.y)
            {
                n--;
                continue;
            }
            obstruction[i].v.y=obstruction[i].u.y;
            i++;
        }
        if(not n)
        {
            printf("%.2lf\n",line.v.x-line.u.x);
            continue;
        }
        for(i=0;i<n;i++)
        {
            getInter(obstruction[i],edge[i].left,edge[i].right);
        }
        qsort(edge,n,sizeof(*edge),cmp);
        compress(n);
    }
    return 0;
}
