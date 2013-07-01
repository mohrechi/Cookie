#include <cstdio>
#include <algorithm>
using namespace std;

int flood[600];

int main()
{
    int t=0,m,n,i,j,end;
    double w;
    while(scanf("%d%d",&m,&n),m)
    {
        for (i=0,end=m*n;i<end;++i)
        {
            scanf("%d",flood+i);
        }
        scanf("%lf",&w);
        sort(flood,flood+end);
        int sub=flood[0];
        for (i=0;i<end;++i)
        {
            flood[i]-=sub;
        }
        if(end<1) while(true);
        int s=100;
        double high=0;
        for (i=1;i<end;++i)
        {
            if(w<=s*flood[i])
            {
                high=w/s;
                break;
            }
            w+=100*flood[i];
            s+=100;
        }
        if(i == end) high=w/s;
        printf("Region %d\nWater level is %.2lf meters.\n%.2lf percent of the region is under water.\n\n",++t,high+double(sub),double(s)/end);
    }
    return 0;
}
