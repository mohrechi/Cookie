#include<stdio.h>
#include<memory.h>

struct point
{
    double x,y;
};

struct line
{
    point p1, p2;
}l[5005];

double mul(point po, line li)
{
    return (po.x-li.p1.x)*(li.p2.y-li.p1.y)-(po.y-li.p1.y)*(li.p2.x-li.p1.x);
}

int main()
{
    int n,m,num[5005];
    point left,right;
    while(scanf("%d",&n),n)
    {
        scanf("%d%lf%lf%lf%lf",&m,&left.x,&left.y,&right.x,&right.y);
        l[0].p1.x=left.x,l[0].p1.y=left.y;
        l[0].p2.x=left.x,l[0].p2.y=right.y;
        l[n+1].p1.x=right.x,l[n+1].p1.y=left.y;
        l[n+1].p2.x=right.x,l[n+1].p2.y=right.y;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf",&l[i].p1.x,&l[i].p2.x);
            l[i].p1.y=left.y,l[i].p2.y=right.y;
        }
        point p;
        memset(num,0,sizeof(num));
        for(int i=0;i<m;i++)
        {
            scanf("%lf%lf",&p.x,&p.y);
            int le=0,ri=n+1,mid;
            while(le+1<ri)
            {
                mid=(le+ri)>>1;
                if(mul(p,l[mid])>0)
                {
                    ri=mid;
                }
                else
                {
                    le=mid;
                }
            }
            num[le]++;
        }
        for(int i=0;i<=n;i++)
        {
            printf("%d: %d\n",i,num[i]);
        }
        printf("\n");
    }
    return 0;
}
