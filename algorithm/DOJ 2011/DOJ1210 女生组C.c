#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
    return(*(int *)a-*(int *)b);
}

main()
{
    int n,m,a[100005],q,i,j,left,right,mid;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(m==0&&n==0)break;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        qsort(a+1,n,sizeof(int),cmp);
        while(m--)
        {
            scanf("%d",&q);
            j=0,left=1,right=n;
            while(left<=right)
            {
                mid=(left+right)/2;
                if(a[mid]==q)
                {
                    j=1;
                    break;
                }
                if(a[mid]>q)
                {
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            if(j==0)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
        }
    }
    return 0;
}
