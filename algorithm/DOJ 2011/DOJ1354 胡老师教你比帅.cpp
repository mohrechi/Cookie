#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a, const void* b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    int w[10005],n,k;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&w[i]);
        }
        qsort(w+1,n,sizeof(int),cmp);
        printf("%d\n",w[k]);
    }
    return 0;
}
