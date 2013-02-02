#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct area
{
    int from;
    int to;
}link[50005];

bool compare(const area &a, const area &b)
{
    if(a.from!=b.from)
    {
        return a.from<b.from;
    }
    return a.to<b.to;
}

int main()
{
    int n,min=2100000000,max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&link[i].from,&link[i].to);
        if(link[i].from<min) min=link[i].from;
        if(link[i].to>max) max=link[i].to;
    }
    sort(link,link+n,compare);
    int tempMax,least=0;
    while(true)
    {
        min=link[least].from;
        tempMax=link[least].to;
        printf("%d ",min);
        for(;least<n;least++)
        {
            if(link[least].from>tempMax)
            {
                break;
            }
            if(link[least].to>tempMax)
            {
                tempMax=link[least].to;
            }
        }
        printf("%d\n",tempMax);
        if(least==n)
        {
            break;
        }
    }
    return 0;
}
