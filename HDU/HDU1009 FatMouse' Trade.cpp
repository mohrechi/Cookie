#include<stdio.h>
#include<stdlib.h>
struct Room
{
    int j,f,w;
}room[1005];
int n,m;
double ans;
int cmp(const void* a, const void* b)
{
    return (*(Room*)b).w-(*(Room*)a).w;
}
int main()
{
    while(scanf("%d%d",&n,&m),n+1||m+1)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&room[i].j,&room[i].f);
            if(room[i].f)room[i].w=room[i].j*1000/room[i].f;
            else room[i].w=0x7FFFFFFF;
        }
        qsort(room,m,sizeof(*room),cmp);
        ans=0;
        for(int i=0;i<m;i++)
        {
            if(n>=room[i].f)
            {
                ans+=room[i].j;
                n-=room[i].f;
            }
            else
            {
                ans+=(double)room[i].j*n/room[i].f;
                break;
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
