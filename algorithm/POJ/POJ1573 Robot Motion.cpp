#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

int main()
{
    int step[15][15],n,m,x,y,s;
    bool visit[15][15];
    char map[15][15];
    while(scanf("%d%d%d",&n,&m,&y),n||m||y)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%s",map[i]+1);
        }
        memset(visit,false,sizeof(visit));
        s=0,x=1,visit[x][y]=true,step[x][y]=s;
        while(true)
        {
            switch(map[x][y])
            {
                case 'N': x--;break;
                case 'S': x++;break;
                case 'E': y++;break;
                case 'W': y--;break;
            }
            s++;
            if(visit[x][y])
            {
                printf("%d step(s) before a loop of %d step(s)\n",step[x][y], s-step[x][y]);
                break;
            }
            visit[x][y]=true;
            step[x][y]=s;
            if(x<1 || y<1 || x>n || y>m)
            {
                printf("%d step(s) to exit\n",s);
                break;
            }
        }
    }
    return 0;
}
