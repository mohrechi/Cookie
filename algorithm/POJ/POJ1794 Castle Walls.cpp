#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

struct Node
{
    int x,y;
}node[60005];

int array[60005];
int temp[60005];

bool cmp(const Node a, const Node b)
{
    if(a.y == b.y)
    {
        return a.x > b.x;
    }
    return a.y < b.y;
}

long long merge(int start, int end)
{
    if(end-start<=1)
    {
        return 0;
    }
    int mid=(start+end)>>1;
    long long ans = 0;
    ans = merge(start,mid)+ merge(mid,end);
    int i=start, j=mid, k=0;
    while(i<mid && j<end)
    {
        if(array[i]<=array[j])
        {
            temp[k++] = array[i++];
        }
        else
        {
            ans += mid - i;
            temp[k++] = array[j++];
        }
    }
    while(i<mid)
    {
        temp[k++] = array[i++];
    }
    while(j<end)
    {
        temp[k++] = array[j++];
    }
    k=0;
    for(i=start;i<end;i++)
    {
        array[i] = temp[k++];
    }
    return ans;
}

int main()
{
    int t,n,m;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<m+n;i++)
        {
            scanf("%d%d",&node[i].x, &node[i].y);
        }
        sort(node, node+m+n, cmp);
        for(int i=0;i<m+n;i++)
        {
            array[i] = node[i].x;
        }
        printf("Scenario #%d:\n",k);
        printf("%lld\n\n",merge(0,n+m));
    }
    return 0;
}

