#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<memory.h>

int n,m,wood[20005],max,min;

int avail(int mid)
{
    int temp=0;
    for(int j=0;j<n;j++)
    {
        temp+=wood[j]/mid;
    }
    return temp;
}

int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        max=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&wood[i]);
            max+=wood[i];
        }
        if(max<m)
        {
            printf("-1\n");
            continue;
        }
        max/=m;
        int left=1,right=max,mid;
        while(right-left>1)
        {
            mid=(left+right)/2;
            if(avail(mid)>=m)
            {
                left=mid;
            }
            else
            {
                right=mid;
            }
        }
        if(avail(right)>=m) printf("%d\n",right);
        else printf("%d\n",left);
    }
    return 0;
}
