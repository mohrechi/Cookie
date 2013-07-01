#include<stdio.h>
#include<stdlib.h>

int n,a[10005],b[10005];
int cmp(const void* a, const void* b)
{
    return *(int*)b-*(int*)a;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d",&a[i]);
        }
        qsort(a,n,sizeof(int),cmp);
        int j=-1;
        for(int i=0;i<=n/2;i++)
        {
            b[++j]=a[i];
            b[++j]=a[n-i-1];
        }
        printf("%d",b[0]);
        for(int i=1;i<n;i++)
        {
            printf(" %d",b[i]);
        }
        printf("\n");
    }
    return 0;
}
