#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
#define MAXN 25
int n,m,x,y,ans;
char map[MAXN][MAXN];
bool color[MAXN][MAXN];
int stepX[] = {0,0,-1,1,-1,1,-1,1};
int stepY[] = {-1,1,0,0,-1,-1,1,1};

void dfs(int x, int y)
{
    if(x>0)
    {
        if(y>0)
        {
            if(x<=n)
            {
                if(y<=m)
                {
                    if('X' == map[x][y])
                    {
                        if(!color[x][y])
                        {
                            color[x][y] = true;
                            for(int i=0;i<8;i++)
                            {
                                dfs(x+stepX[i], y+stepY[i]);
                            }
                        }
                    }
                }
            }
        }
    }
}

void get()
{
    ans = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(color[i][j])
            {
                for(int k=0;k<4;k++)
                {
                    if(!color[i+stepX[k]][j+stepY[k]])
                    {
                        ++ ans;
                    }
                }
            }
        }
    }
}

void printColor()
{
    printf("Color: \n");
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            printf("%2d",color[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    while(scanf("%d%d%d%d",&n,&m,&x,&y), n||m||x||y)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%s",map[i]+1);
        }
        memset(color,false,sizeof(color));
        dfs(x,y);
        get();
        printf("%d\n",ans);
    }
    return 0;
}
