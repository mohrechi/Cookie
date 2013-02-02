#include<stdio.h>
#include<stdlib.h>
int n,a[100005],l[100005],ans;
int main()
{
    while(scanf("%d",&n),n)
    {
        int sum=0,temp=-999999999;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            if(sum>temp)
            {
                temp=sum;
            }
            l[i]=temp;
            if(sum<0)
            {
                sum=0;
            }
        }
        sum=0, ans=temp=-999999999;
        for(int i=n-1;i>0;i--)
        {
            sum+=a[i];
            if(sum>temp)
            {
                temp=sum;
            }
            if(ans<temp+l[i-1])
            {
                ans=temp+l[i-1];
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
