#include<stdio.h>
#include<stdlib.h>

int cow[10010];
int cmp(const void *a, const void* b)
{
    return *(int*)a-*(int*)b;
}
int main ()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d",&cow[i]);
        }
        qsort(cow,n,sizeof(int),cmp);
        printf("%d\n",cow[n/2]);
    }
    return 0;
}
