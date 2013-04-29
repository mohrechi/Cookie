#include<stdio.h>
#include<stdlib.h>
struct House
{
    int d,p;
}house[1005];
int n,t,w[1005];
int cmp1(const void *a, const void* b)
{
    return *(int*)a-*(int*)b;
}
int cmp2(const void* a, const void* b)
{
    return ((*(House*)a).p-(*(House*)a).d*t)-((*(House*)b).p-(*(House*)b).d*t);
}
int main()
{
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&w[i]);
        }
        for(int j=0;j<n;j++)
        {
            scanf("%d",&house[j].d);
        }
        for(int k=0;k<n;k++)
        {
            scanf("%d",&house[k].p);
        }
        qsort(w,n,sizeof(int),cmp1);
        qsort(house,n,sizeof(*house),cmp2);
        for(int i=0;i<n;i++)
        {
            ans+=w[i]*(house[i].p-house[i].d*t);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
