#include<stdio.h>
struct point
{
    double x,y;
}p[70];
struct segment
{
    point u,v;
}s[35];
double min(double &a, double &b)
{
    return a<b?a:b;
}
double max(double &a, double &b)
{
    return a>b?a:b;
}
double cross(point &a, point &b, point &c)
{
    return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}
double quick(segment &a, segment &b)
{
    return max(a.u.x,a.v.x)>min(b.u.x,b.v.x) and max(a.u.y,a.v.y)>min(b.u.y,b.v.y) and max(b.u.x,b.v.x)>min(a.u.x,a.v.x) and max(b.u.y,b.v.y)>min(a.u.y,a.v.y);
}
double check(segment &a, segment &b)
{
    if(quick(a,b))
    {
        return cross(a.u,a.v,b.u)*cross(a.u,a.v,b.v)<-1e-6 and cross(b.u,b.v,a.u)*cross(b.u,b.v,a.v)<-1e-6;
    }
    return false;
}
int main()
{
    int n;
    scanf("%d",&n);
    if(n==0)
    {
        printf("Number of doors = 1\n");
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf%lf%lf",&s[i].u.x,&s[i].u.y,&s[i].v.x,&s[i].v.y);
        p[i*2].x=s[i].u.x, p[i*2].y=s[i].u.y;
        p[i*2+1].x=s[i].v.x, p[i*2+1].y=s[i].v.y;
    }
    segment temp;
    scanf("%lf%lf",&temp.u.x,&temp.u.y);
    int min=0x7FFFFFFF;
    for(int i=0;i<n*2;i++)
    {
        temp.v.x=p[i].x, temp.v.y=p[i].y;
        int j,count=1;
        for(j=0;j<n;j++)
        {
            if(check(temp,s[j]))
            {
                count++;
            }
        }
        if(count<min)
        {
            min=count;
        }
    }
    printf("Number of doors = %d\n",min);
    return 0;
}
