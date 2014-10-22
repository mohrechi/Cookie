#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

struct point
{
    double x,y;
};

struct line
{
    point p1, p2;
}l[1005];

double mul(point po, line li)
{
    return (po.x-li.p1.x)*(li.p2.y-li.p1.y)-(po.y-li.p1.y)*(li.p2.x-li.p1.x);
}

int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int n,m,num[1005],result[1005];
    point left,right;
    while(scanf("%d",&n),n)
    {
        scanf("%d%lf%lf%lf%lf",&m,&left.x,&left.y,&right.x,&right.y);
        l[0].p1.x=left.x,l[0].p1.y=left.y;
        l[0].p2.x=left.x,l[0].p2.y=right.y;
        l[n+1].p1.x=right.x,l[n+1].p1.y=left.y;
        l[n+1].p2.x=right.x,l[n+1].p2.y=right.y;
        int a[1005],b[1005];
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&b[i]);
        }
        qsort(a,n,sizeof(int),cmp);
        qsort(b,n,sizeof(int),cmp);
        for(int i=1;i<=n;i++)
        {
            l[i].p1.x=a[i-1];
            l[i].p1.y=left.y;
            l[i].p2.x=b[i-1];
            l[i].p2.y=right.y;
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
        printf("Box\n");
        memset(result,0,sizeof(result));
        for(int i=0;i<=n;i++)
        {
            result[num[i]]++;
        }
        for(int i=1;i<=m;i++)
        {
            if(result[i])
            {
                printf("%d: %d\n",i,result[i]);
            }
        }
    }
    return 0;
}
