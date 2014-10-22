#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int main()
{
    int a[10005],n,count,temp;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        count=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(a[i]>temp)
            {
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
