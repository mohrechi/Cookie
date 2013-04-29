#include<stdio.h>

main()
{
    int height[100001],i,j,n,k,b,index[100001]={0};
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&height[i]);
        for(j=i-1;j>=0;j--)
        {
            if(height[j]!=0)
            {
                if(height[i]>height[j])
                {
                    index[j]=i+1,height[j]=0;
                }
                else break;
            }
        }
    }
    for (i=0;i<n;i++)
    {
        printf("%d\n",index[i]);
    }
    return 0;
}
