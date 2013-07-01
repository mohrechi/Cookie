#include<cstdio>
using namespace std;

int n, num[500000],temp[500000];
long long ans;

void merge(int start, int end)
{
    if(start==end) return;
    int mid=(start+end)/2;
    if(end-start>1)
    {
        merge(start,mid), merge(mid,end);
    }
    int i=start, j=mid, k=0;
    while(i<mid && j<end)
    {
        if(num[i]<=num[j])
        {
            temp[k++]=num[i++];
        }
        else
        {
            ans+=mid-i;
            temp[k++]=num[j++];
        }
    }
    if(i<mid)
    {
        for(;i<mid;i++)
        {
            temp[k++]=num[i];
        }
    }
    else
    {
        for(;j<end;j++)
        {
            temp[k++]=num[j];
        }
    }
    k=0;
    for(i=start;i<end;i++)
    {
        num[i]=temp[k++];
    }
}

int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
        }
        ans=0;
        merge(0,n);
        printf("%lld\n",ans);
    }
    return 0;
}
