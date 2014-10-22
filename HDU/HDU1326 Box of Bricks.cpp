#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[100],n,sum,ans,t=0;
    scanf("%d",&n);
    while(n)
    {
        sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        sum/=n;
        ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>sum)
            {
                ans+=a[i]-sum;
            }
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",++t,ans);
    }
    return 0;
}
