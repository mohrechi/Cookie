#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,a[205];
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int i;
        for(i=0;i<n;i++)
        {
            int j;
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    if(a[i]==a[j])
                    {
                        break;
                    }
                }
            }
            if(j==n)
            {
                break;
            }
        }
        printf("%d\n",a[i]);
    }
    return 0;
}
