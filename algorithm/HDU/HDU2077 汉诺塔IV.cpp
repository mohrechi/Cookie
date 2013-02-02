#include<stdio.h>
int main()
{
    int ans[30]={0};
    for(int i=1;i<=20;i++)
    {
        ans[i]=ans[i-1]*3+1;
    }
    for(int i=20;i>0;i--)
    {
        ans[i]=2*ans[i-1]+2;
    }
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
