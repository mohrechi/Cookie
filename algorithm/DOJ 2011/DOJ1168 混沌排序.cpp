#include<stdio.h>
#include<stdlib.h>
int cmp(const void* a, const void* b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n,m,a[1005],b[1005],front,rear,top;
    while(scanf("%d%d",&n,&m),n || m)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        qsort(a,n,sizeof(int),cmp);
        front=0,rear=n,top=0;
        while(true)
        {
            int i;
            for(i=0;i<m;i++)
            {
                b[top++]=a[front++];
            }
            if(top>=n)
            {
                break;
            }
            for(i=rear-m;i<rear;i++)
            {
                b[top++]=a[i];
            }
            rear-=m;
            if(top>=n)
            {
                break;
            }
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
