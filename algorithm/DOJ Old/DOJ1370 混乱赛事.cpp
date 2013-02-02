#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int main()
{
    int n,m,times[200];
    char win[10];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(times,0,sizeof(times));
        for(int i=0;i<m;i++)
        {
            scanf("%s",win);
            times[*win]++;
            scanf("%s",win);
        }
        for(int i='A';i<'A'+n;i++)
        {
            printf("%c %d\n",i,times[i]);
        }
    }
    return 0;
}
