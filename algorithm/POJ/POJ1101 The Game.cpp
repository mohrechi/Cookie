#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define MAXN 80
bool graph[MAXN][MAXN];
int step[MAXN][MAXN];
int stepX[4] = {-1,0,1,0};
int stepY[4] = {0,-1,0,1};
int n,m;

void printStep()
{
    printf("Step: \n");
    for(int i=0;i<=m+1;i++)
    {
        for(int j=0;j<=n+1;j++)
        {
            printf("%4d", step[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool search(int stepNumber)
{
    bool flag = false;;
    for(int i=0;i<=m+1;i++)
    {
        for(int j=0;j<=n+1;j++)
        {
            if(stepNumber == step[i][j])
            {
                for(int k=0;k<4;k++)
                {
                    int tx = i;
                    int ty = j;
                    while(tx >= 0 &&
                          ty >= 0 &&
                          tx <= m+1 &&
                          ty <= n+1 &&
                          !graph[tx][ty])
                    {
                        if(-1 == step[tx][ty])
                        {
                            step[tx][ty] = stepNumber + 1;
                            flag = true;
                        }
                        tx += stepX[k];
                        ty += stepY[k];
                    }
                }
            }
        }
    }
    return flag;
}

int main(int argc, char *argv[])
{
    int boardNumber = 0;
    while(scanf("%d%d",&n,&m),n||m)
    {
        getchar();
        memset(graph, false, sizeof(graph));
        char s[100];
        for(int i=1;i<=m;i++)
        {
            gets(s+1);
            for(int j=1;j<=n;j++)
            {
                if('X' == s[j])
                {
                    graph[i][j] = true;
                }
            }
        }
        printf("Board #%d:\n",++boardNumber);
        int pairNumber = 0;
        int sx,sy,ex,ey;
        while(scanf("%d%d%d%d",&sy,&sx,&ey,&ex), sx||sy||ex||ey)
        {
            memset(step, -1, sizeof(step));
            step[sx][sy] = 0;
            graph[sx][sy] = graph[ex][ey] = false;
            int stepNumber = 0;
            while(search(stepNumber++));
            printf("Pair %d: ",++pairNumber);
            if(-1 == step[ex][ey])
            {
                printf("impossible.\n");
            }
            else
            {
                printf("%d segments.\n",step[ex][ey]);
            }
            graph[sx][sy] = graph[ex][ey] = true;
        }
        printf("\n");
    }
    return 0;
}
