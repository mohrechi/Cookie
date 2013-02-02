#include<stdio.h>
#include<math.h>
#include<stdlib.h>

struct Point
{
    int x,y;
    Point(){}
    Point(double x0, double y0)
    {
        x=x0,y=y0;
    }
}p[10005];

Point operator ^(Point a, Point b)
{
    return Point(a.x^b.x, a.y^b.y);
}

int cross(Point a, Point b, Point o)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

int cmp(const void* a, const void* b)
{
    return -cross(*(Point*)a,*(Point*)b,p[0]);
}

double cross(Point a, Point b)
{
    return a.x*b.y-a.y*b.x;
}

int stack[10005],top,n;

void graham()
{
    int miny=p[0].y,minx=p[0].x,mp=0;
    for(int i=0;i<n;i++)
    {
        if(p[i].y<miny or (p[i].y==miny and p[i].x<minx))
        {
            miny=p[i].y, minx=p[i].x, mp=i;
        }
    }
    p[0]=p[0]^p[mp];
    p[mp]=p[mp]^p[0];
    p[0]=p[0]^p[mp];
    qsort(p+1,n-1,sizeof(*p),cmp);
    stack[0]=0, stack[1]=1, stack[2]=2,top=3;
    for(int i=3;i<n;i++)
    {
        while(cross(p[i],p[stack[top-1]],p[stack[top-2]])>=0) top--;
        stack[top++]=i;
    }
    stack[top]=0;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    graham();
    p[n].x=p[0].x,p[n].y=p[0].y;
    double area=0;
    for(int i=0;i<top;i++)
    {
        area+=cross(p[stack[i]],p[stack[i+1]]);
    }
    if(area<0)area=-area;
    printf("%d\n",(int)area/100);
    return 0;
}
