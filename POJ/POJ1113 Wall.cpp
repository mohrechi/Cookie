#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

struct point
{
    int x;
    int y;
}points[1100];

int n;

int crossmulty(point a, point b, point c)
{
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}

int cmp(const void *a, const void *b)
{
    if((*(point*)a).y==(*(point*)b).y) return (*(point*)a).x-(*(point*)b).x;
    return (*(point*)a).y-(*(point*)b).y;
}

double Distance(point a, point b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double Graham()
{
    double sum=0;
    int top=1,stack[1100];
    stack[0]=0, stack[1]=1;
    for(int i=2;i<n;i++)
    {
        while(top>=1 and crossmulty(points[i], points[stack[top]], points[stack[top-1]])>=0)
        {
            top--;
        }
        stack[++top]=i;
    }
    stack[++top]=n-2;
    int temp=top;
    for(int i=n-3;i>=0;i--)
    {
        while(top>=temp and crossmulty(points[i], points[stack[top]], points[stack[top-1]])>=0)
        {
            top--;
        }
        stack[++top]=i;
    }
    for(int i=0;i<top;i++)
    {
        sum+=Distance(points[stack[i]],points[stack[i+1]]);
    }
    return sum;
}

int main()
{
    int r;
    double dis;
    scanf("%d%d",&n,&r);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&points[i].x,&points[i].y);
    }
    qsort(points,n,sizeof(*points),cmp);
    dis=2*r*3.1415926;
    dis+=Graham();
    printf("%.0lf\n",dis);
    return 0;
}
