#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
const double eps = 1e-8;
struct point {
    double x,y;
}p[3000];int top;
bool cmpxy(point a,point b)
{
    if(fabs(a.y-b.y)>eps)
        return a.y<b.y;
    return a.x<b.x;
}
double cross(point a,point b,point c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
void tu(point *p,int n)
{
    if(n<3) return ;
    int i,m=0;top=1;
    sort(p,p+n,cmpxy);
    for(i=n;i<2*n-1;i++)
        p[i]=p[2*n-2-i];
    for(i=2;i<2*n-1;i++){
        while(top>m && cross(p[top],p[i],p[top-1])<eps)
            top--;
        p[++top] = p[i];
        if(i==n-1)  m=top;
    }
}
double getarea(point *p,int n)
{
    int i;
    double area=0;
    for(i=0;i<n;i++) area+=p[(i+1)%n].y*(p[i].x-p[(i+2)%n].x);
    return area/2;
}
int main()
{
    int t, n,i;
    scanf("%d", &t);
    for(int k=1;k<=t;++k)
    {
        double area;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        tu(p,n);
        area=getarea(p,top);
        printf("Case #%d: %.1lf\n",k, area);
    }
    return 0;
}
