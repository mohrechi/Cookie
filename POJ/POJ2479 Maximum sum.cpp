#include<stdio.h>

int caseNum, n, a[50005], l[50005];

int main()
{
    scanf("%d",&caseNum);
    while(caseNum--)
    {
        scanf("%d",&n);
        int sum=0, temp=-999999999;
        for(int i=1;i<=n;i++)
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
        sum=0, temp=-999999999;
        int ans=temp;
        for(int i=n;i>1;i--)
        {
            sum+=a[i];
            if(sum>temp)
            {
                temp=sum;
            }
            if(ans<l[i-1]+temp)
            {
                ans=l[i-1]+temp;
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
