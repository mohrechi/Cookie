#include<stdio.h>
struct point
{
    double x,y;
};
struct segment
{
    point u,v;
};
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
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        segment s[4];
        segment l;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&l.u.x,&l.u.y,&l.v.x,&l.v.y,&s[0].u.x,&s[0].u.y,&s[2].u.x,&s[2].u.y);
        if(l.u.x>=min(s[0].u.x,s[2].u.x) and l.u.x<=max(s[0].u.x,s[2].u.x) and l.u.y>=min(s[0].u.y,s[2].u.y) and l.u.y<=max(s[0].u.y,s[2].u.y))
        {
            if(l.v.x>=min(s[0].u.x,s[2].u.x) and l.v.x<=max(s[0].u.x,s[2].u.x) and l.v.y>=min(s[0].u.y,s[2].u.y) and l.v.y<=max(s[0].u.y,s[2].u.y))
            {
                printf("T\n");
                continue;
            }
        }
        if(l.u.x==l.v.x and (l.u.x==s[0].u.x or l.u.x==s[2].u.x))
        {
            if(max(l.u.y,l.v.y)<min(s[0].u.y,s[2].u.y) or min(l.u.y,l.v.y)>max(s[0].u.y,s[2].u.y))
            {
                printf("F\n");
            }
            else
            {
                printf("T\n");
            }
            continue;
        }
        if(l.u.y==l.v.y and (l.u.y==s[0].u.y or l.u.y==s[2].u.y))
        {
            if(max(l.u.x,l.v.x)<min(s[0].u.x,s[2].u.x) or min(l.u.x,l.v.x)>max(s[0].u.x,s[2].u.x))
            {
                printf("F\n");
            }
            else
            {
                printf("T\n");
            }
            continue;
        }
        s[0].v.x=s[2].u.x, s[0].v.y=s[0].u.y;
        s[1].u.x=s[0].v.x, s[1].u.y=s[0].v.y;
        s[1].v.x=s[2].u.x, s[1].v.y=s[2].u.y;
        s[2].v.x=s[0].u.x, s[2].v.y=s[2].u.y;
        s[3].u.x=s[2].v.x, s[3].u.y=s[2].v.y;
        s[3].v.x=s[0].u.x, s[3].v.y=s[0].u.y;
        int i;
        for(i=0;i<4;i++)
        {
            if(cross(s[i].u,l.u,l.v)*cross(s[i].v,l.u,l.v)<-1e-8 and cross(l.u,s[i].u,s[i].v)*cross(l.v,s[i].u,s[i].v)<-1e-8)
            {
                break;
            }
        }
        if(i==4) printf("F\n");
        else printf("T\n");
    }
    return 0;
}
