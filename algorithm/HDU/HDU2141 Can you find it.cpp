#include <iostream>
using namespace std;

__int64 a[501],b[501],c[501],ab[250001];


int cmp(const void *a,const void *b)
{
    return *((__int64 *)a)-*((__int64 *)b);
}

int search(__int64 ss,int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(ab[mid]==ss)
            return 1;
        else if(ab[mid]>ss)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return 0;
}
int main()
{
    int l,n,m,w,s;
    __int64 ss;
    int i,j,h;
    int num=1;
    int lnum;
    while(scanf("%d%d%d",&l,&n,&m)!=EOF)
    {
        for(i=0;i<l;i++)
            scanf("%I64d",&a[i]);
        for(i=0;i<n;i++)
            scanf("%I64d",&b[i]);
        for(i=0;i<m;i++)
            scanf("%I64d",&c[i]);
        lnum=0;
        for(i=0;i<l;i++)
             for(j=0;j<n;j++)
             {
                 ab[lnum++]=a[i]+b[j];
             }
        qsort(ab,lnum,sizeof(ab[0]),cmp);
        scanf("%d",&w);
        printf("Case %d:\n",num++);
        for(h=1;h<=w;h++)
        {
            scanf("%d",&s);
            for(i=0;i<m;i++)
            {
                ss=s-c[i];
                if(search(ss,0,lnum-1))
                    break;
            }
            if(i!=m)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
