#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp(const void *a,const void *b)
{
    return(strcmp((char*)a,(char*)b));
}

char n1[100000][50],n2[100000][50];
main()
{
    int n,i,j,k,z=0,left,right,mid;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        for(i=0;i<n;i++)
        {
            scanf("%s",n1[i]);
        }
        n--;
        qsort(n1,n+1,sizeof(n1[0]),cmp);
        k=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",n2[i]);
            left=0,right=n;
            while(left<=right)
            {
                mid=(left+right)/2;
                j=strcmp(n2[i],n1[mid]);
                if(j==0)
                {
                    k+=mid;
                    break;
                }
                if(j<0)
                {
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
        }
        printf("Case %d :%s\n\n",++z,n1[n*(n+1)/2-k]);
    }
    return 0;
}
