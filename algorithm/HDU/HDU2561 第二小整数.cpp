#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t,n,a[15];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                {
                    a[i]^=a[j],a[j]^=a[i],a[i]^=a[j];
                }
            }
        }
        printf("%d\n",a[1]);
    }
    return 0;
}
