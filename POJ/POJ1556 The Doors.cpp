#include<stdio.h>
#include<math.h>
struct point
{
    double x,y;
}p[200];
struct segment
{
    point a,b;
}s[200];
double g[200][200];
int t;
double cross(point a, point b, point o)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
int equal(double a)
{
    if(fabs(a)<1e-6) return 0;
    return a>0?1:-1;
}
double dist2(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool check(point a, point b, point c, point d)
{
    return equal(cross(a,c,d))*equal(cross(b,c,d))<=0 and equal(cross(a,b,c))*equal(cross(a,b,d))<=0;
}
double Dijkstra()
{
    double dist[200];
    bool visited[200];
    for(int i=0;i<=t;i++)
    {
        dist[i]=1e10;
        visited[i]=false;
    }
    dist[0]=0;
    for(int i=0;i<=t;i++)
    {
        double temp=1e10;
        int index;
        for(int j=0;j<=t;j++)
        {
            if(not visited[j] and temp>dist[j])
            {
                index=j;
                temp=dist[j];
            }
        }
        if(temp==1e10)
        {
            break;
        }
        visited[index]=true;
        for(int j=0;j<=t;j++)
        {
            if(not visited[j] and dist[index]+g[index][j]<dist[j])
            {
                dist[j]=dist[index]+g[index][j];
            }
        }
    }
    return dist[t];
}
int main()
{
    int n;
    while(scanf("%d",&n),n+1)
    {
        t=n*4+1;
        p[0].x=0,p[0].y=5;
        p[t].x=10,p[t].y=5;
        for(int i=0;i<n;i++)
        {
            double x,a,b,c,d;
            scanf("%lf%lf%lf%lf%lf",&x,&a,&b,&c,&d);
            p[i*4+1].x=x,p[i*4+1].y=a;
            p[i*4+2].x=x,p[i*4+2].y=b;
            p[i*4+3].x=x,p[i*4+3].y=c;
            p[i*4+4].x=x,p[i*4+4].y=d;
            s[i*3].a.x=x,s[i*3].a.y=0,s[i*3].b.x=x,s[i*3].b.y=a;
            s[i*3+1].a.x=x,s[i*3+1].a.y=b,s[i*3+1].b.x=x,s[i*3+1].b.y=c;
            s[i*3+2].a.x=x,s[i*3+2].a.y=d,s[i*3+2].b.x=x,s[i*3+2].b.y=10;
        }
        for(int i=0;i<=t;i++)
        {
            for(int j=0;j<=t;j++)
            {
                g[i][j]=1e10;
            }
        }
        for(int i=0;i<=t;i++)
        {
            for(int j=i+1;j<=t;j++)
            {
                int k;
                for(k=0;k<n*3;k++)
                {
                    if(p[i].x!=p[j].x and p[i].x!=s[k].a.x and p[j].x!=s[k].a.x and check(p[i],p[j],s[k].a,s[k].b))
                    {
                        break;
                    }
                }
                if(k>=n*3)
                {
                    g[i][j]=dist2(p[i],p[j]);
                }
            }
        }
        printf("%.2lf\n",Dijkstra());
    }
    return 0;
}
