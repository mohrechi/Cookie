#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

struct point
{
    double x,y;
    int belong;
}p[200005];

int check[200005];

int cmp1(const void* a, const void* b)
{
    return (*(point*)a).x - (*(point*)b).x;
}

int cmp2(const void* a, const void* b)
{
    return p[*(int*)a].y-p[*(int*)b].y;
}

double dist2(point &a, point &b)
{
    if(a.belong!=b.belong)
    {
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
    return 0x7FFFFFFF;
}

double closestPair(int left, int right)
{
    if(left>=right)
    {
        return 0x7FFFFFFF;
    }
    if(left+1==right)
    {
        return dist2(p[left],p[right]);
    }
    int mid=(left+right)>>1;
    double min1=closestPair(left,mid-1);
    double min2=closestPair(mid,right);
    double min=min1<min2?min1:min2;
    int len=0;
    for(int i=mid-1;i>=left and p[mid].x-p[i].x<min;i--)
    {
        check[len++]=i;
    }
    for(int i=mid;i<=right and p[i].x-p[mid].x<min;i++)
    {
        check[len++]=i;
    }
    qsort(check,len,sizeof(*check),cmp2);
    for(int i=0;i<len;i++)
    {
        int j=0;
        while(i+j<len)
        {
            double temp=dist2(p[check[i]],p[check[i+j]]);
            if(temp<min)
            {
                min=temp;
            }
            j++;
        }
    }
    return min;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x, &p[i].y);
            p[i].belong=0;
        }
        n<<=1;
        for(;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x, &p[i].y);
            p[i].belong=1;
        }
        qsort(p,n,sizeof(*p),cmp1);
        printf("%.3lf\n",closestPair(0,n));
    }
    return 0;
}
