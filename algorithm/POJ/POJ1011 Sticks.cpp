#include<stdio.h>
#include<algorithm>
using namespace std;

bool cmp(const int &a, const int &b)
{
    return a>b;
}

int n,sticks[100],sum,maxl,len;
bool visited[100];

bool connect(int unvisited, int needs, int pos, int start)
{
    if(needs==0)
    {
        if(unvisited==0)
        {
            return true;
        }
        start=0;
        while(visited[start])
        {
            start++;
        }
        if(connect(unvisited,len,start,start))
        {
            return true;
        }
        return false;
    }
    if(pos==n)
    {
        return false;
    }
    for(int i=pos;i<n;i++)
    {
        if(visited[i] or sticks[i]>needs)
        {
            continue;
        }
        if(i>0 and sticks[i]==sticks[i-1] and visited[i-1]==false)
        {
            continue;
        }
        visited[i]=true;
        if(connect(unvisited-1,needs-sticks[i],pos+1,start))
        {
            return true;
        }
        visited[i]=false;
        if(sticks[i]==needs or i==start)
        {
            break;
        }
    }
    return false;
}

int main(void)
{
    while(scanf("%d",&n),n)
    {
        sum=0,maxl=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&sticks[i]);
            visited[i]=false;
            sum+=sticks[i];
            if(sticks[i]>maxl)
            {
                maxl=sticks[i];
            }
        }
        sort(sticks, sticks+n, cmp);
        for(len=maxl;len<sum;len++)
        {
            if(sum%len!=0)
            {
                continue;
            }
            if(connect(n,0,0,0))
            {
                break;
            }
        }
        printf("%d\n",len);
    }
    return 0;
}
