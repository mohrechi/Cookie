#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct Period
{
    int start,end;
}p[10010];

bool operator < (const Period &a, const Period &b)
{
    return a.start < b.start;
}

int main()
{
    int n,continuous,idle;
    int k = 0;
    while(~scanf("%d",&n))
    {
        continuous=0,idle=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&p[i].start,&p[i].end);
        }
        sort(p, p + n);
        int start,end;
        start=p[0].start,end=p[0].end;
        for(int i=1;i<n;i++)
        {
            if(p[i].start<=end)
            {
                end = max(end, p[i].end);
            }
            else
            {
                continuous = max(continuous, end - start);
                idle = max(idle, p[i].start - end);
                start=p[i].start;
                end=p[i].end;
            }
        }
        continuous = max(continuous, end - start);
        printf("%d %d\n",continuous,idle);
    }
    return 0;
}
