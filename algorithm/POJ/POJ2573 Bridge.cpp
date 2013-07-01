#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    int t,n,a[1005],b[10005],top=0;
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
        if(n==1)
        {
            sum+=*slowest;
            b[top++]=*slowest;
            break;
        }
        if(n==2)
        {
            sum+=*slowest;
            b[top++]=*slower;
            b[top++]=*slowest;
            break;
        }
        if(n==3)
        {
            sum+=*slowest+*slower+*fastest;
            b[top++]=*fastest;
            b[top++]=*slowest;
            b[top++]=*fastest;
            b[top++]=*fastest;
            b[top++]=*slower;
            break;
        }
        if(2**faster>=*fastest+*slower)
        {
            sum+=*slowest+*slower+2**fastest;
            b[top++]=*fastest;
            b[top++]=*slowest;
            b[top++]=*fastest;
            b[top++]=*fastest;
            b[top++]=*slower;
            b[top++]=*fastest;
        }
        else
        {
            sum+=2**faster+*fastest+*slowest;
            b[top++]=*fastest;
            b[top++]=*faster;
            b[top++]=*fastest;
            b[top++]=*slower;
            b[top++]=*slowest;
            b[top++]=*faster;
        }
        slowest-=2, slower-=2, n-=2;
    }
    printf("%d\n",sum);
    if(top==1)
    {
        printf("%d\n",b[0]);
    }
    else
    {
        printf("%d %d\n",b[0],b[1]);
    }
    if(top>2)
    {
        for(int i=2;i<top;i+=3)
        {
            printf("%d\n%d %d\n",b[i],b[i+1],b[i+2]);
        }
    }
    return 0;
}
