#include<stdio.h>
#include<stdlib.h>
struct point
{
    int pos,x,y;
}p[100];
int cmp1(const void* a, const void *b)
{
    if((*(point*)a).y==(*(point*)b).y)
    {
        return (*(point*)a).x-(*(point*)b).x;
    }
    return (*(point*)a).y-(*(point*)b).y;
}
int cross(point a, point b, point o)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
int dist(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int top;
int cmp2(const void* a, const void *b)
{
    int temp;
    temp=cross(p[top],(*(point*)a),(*(point*)b));
    if(temp>0)
    {
        return -1;
    }
    else if(temp==0)
    {
        return dist(p[top],(*(point*)a))-dist(p[top],(*(point*)b));
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&p[i].pos,&p[i].x,&p[i].y);
        }
        qsort(p,n,sizeof(*p),cmp1);
        top=0;
        for(int i=1;i<n;i++)
        {
            qsort(p+i,n-i,sizeof(*p),cmp2);
            top++;
        }
        printf("%d",n);
        for(int i=0;i<n;i++)
        {
            printf(" %d",p[i].pos);
        }
        printf("\n");
    }
    return 0;
}
