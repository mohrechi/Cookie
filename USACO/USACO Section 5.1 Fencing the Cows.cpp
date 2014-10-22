/*
ID: cyberzh1
LANG: C++
TASK: fc
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
FILE* fin=fopen("fc.in","r");
FILE* fout=fopen("fc.out","w");
struct Point
{
    double x,y;
}point[10005];
int n,stack[10005],top;
double ans;
int comparePosition(const void* a, const void* b)
{
    if((*(Point*)a).y==(*(Point*)b).y)
    {
        return (*(Point*)a).x-(*(Point*)b).x;
    }
    return (*(Point*)a).y-(*(Point*)b).y;
}
int dblcmp(double r)
{
    if(fabs(r)<1e-6) return 0;
    return r>0?1:-1;
}
double cross(Point a, Point b, Point o)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
double dist(Point a, Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    fscanf(fin,"%d",&n);
    for(int i=0;i<n;i++)
    {
        fscanf(fin,"%lf%lf",&point[i].x, &point[i].y);
    }
    qsort(point, n, sizeof(*point), comparePosition);
    top=2;
    stack[0]=0, stack[1]=1;
    for(int i=2;i<n;i++)
    {
        while(dblcmp(cross(point[i],point[stack[top-2]],point[stack[top-1]]))<0)
        {
            top--;
        }
        stack[top++]=i;
    }
    stack[top++]=n-2;
    for(int i=n-3;i>=0;i--)
    {
        while(dblcmp(cross(point[i],point[stack[top-2]],point[stack[top-1]]))<0)
        {
            top--;
        }
        stack[top++]=i;
    }
    ans=0;
    for(int i=0;i<top-1;i++)
    {
        ans+=dist(point[stack[i]], point[stack[i+1]]);
    }
    fprintf(fout,"%.2lf\n",ans);
    return 0;
}
