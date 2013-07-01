#include<stdio.h>
#include<stdlib.h>

int comp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}

main()
{
    int m,n,a[100001],i;
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(m==0&&n==0)
        {
            break;
        }
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        qsort(a,n,sizeof(int),comp);
        for(i=0;i+m<n;i+=m)
        {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[i]);
    }
    return 0;
}
