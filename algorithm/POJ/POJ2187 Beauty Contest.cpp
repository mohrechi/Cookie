#include <iostream>
#include <algorithm>
#include <cmath>
#define MAXP 50005
using namespace std;

const double eps = 1e-8;

struct Point
{
    double x,y;
};

int n,top,stack[MAXP];
Point point[MAXP];

double dblcmp(double r)
{
    if(fabs(r)<eps) return 0;
    return r>0?1:-1;
}

double multiply(Point a, Point b, Point o)
{
    return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x);
}

double dist(Point a, Point b)
{
    return (a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y);
}

bool grahamCompare(const Point &a, const Point &b)
{
    if(a.y == b.y) return a.x<b.x;
    return a.y<b.y;
}

void grahamScan()
{
    sort(point, point + n, grahamCompare);
    stack[0] = 0, stack[1] = 1, top = 2;
    for(int i=2;i<n;i++)
    {
        while(top > 1 && dblcmp(multiply(point[stack[top-1]], point[stack[top-2]], point[i]))<0)
        {
            --top;
        }
        stack[top++] = i;
    }
    int temp = top;
    stack[top++] = n-2;
    for(int i=n-3;i>=0;i--)
    {
        while(top > temp && dblcmp(multiply(point[stack[top-1]], point[stack[top-2]], point[i]))<0)
        {
            --top;
        }
        stack[top++] = i;
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>point[i].x>>point[i].y;
    }
    grahamScan();
    double maxDist = 0;
    for(int i=0;i<top;i++)
    {
        for(int j=i+1;j<top;j++)
        {
            maxDist = max(maxDist, dist(point[stack[i]], point[stack[j]]));
        }
    }
    cout<<(int)maxDist<<endl;
    return 0;
}
