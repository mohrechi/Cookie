#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int t,n,a[1005];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        qsort(a,n,sizeof(int),cmp);
        int *fastest=&a[0],*faster=&a[1],*slower=&a[n-2],*slowest=&a[n-1];
        int sum=0;
        while(n)
        {
            if(n==1 or n==2)
            {
                sum+=*slowest;
                break;
            }
            if(n==3)
            {
                sum+=*slowest+*slower+*fastest;
                break;
            }
            if(2**faster>=*fastest+*slower)
            {
                sum+=*slowest+*slower+2**fastest;
            }
            else
            {
                sum+=2**faster+*fastest+*slowest;
            }
            slowest-=2, slower-=2, n-=2;
        }
        printf("%d\n",sum);
    }
    return 0;
}
