#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n,a,b,c,count,ans[100];
    while(scanf("%d",&n),n)
    {
        count=0;
        for(int k=1;k<=n;k*=10)
        {
            c=(n/k)/11;
            b=n/k-c*11;
            if((b||c)&&b<10)
            {
                a=(n-b*k-c*k*11)/2;
                if(2*a+b*k+c*11*k==n)
                {
                    count++;
                    ans[count]=a+b*k+c*k*10;
                }
            }
            b--;
            if((b||c)&&b>=0)
            {
                a=(n-b*k-c*k*11)/2;
                if(2*a+b*k+c*k*11==n)
                {
                    count++;
                    ans[count]=a+b*k+c*k*10;
                }
            }
        }
        if(!count) printf("No solution.\n");
        else
        {
            qsort(ans+1,count,sizeof(*ans),cmp);
            printf("%d",ans[1]);
            for(int i=2;i<=count;i++)
            {
                if(ans[i]!=ans[i-1])
                {
                    printf(" %d",ans[i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
