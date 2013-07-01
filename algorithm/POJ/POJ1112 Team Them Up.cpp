#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAXN 105

int n;
bool graph[MAXN][MAXN];
bool visit[MAXN];
int color[MAXN];
int set[MAXN][2][MAXN];
int setNumber;
bool dp[2][MAXN*2];
int path[MAXN][MAXN*2][2];
int result[2][MAXN];

void input()
{
    scanf("%d",&n);
    memset(graph, false, sizeof(graph));
    for(int i=1;i<=n;i++)
    {
        int j;
        while(scanf("%d",&j),j)
        {
            graph[i][j] = true;
        }
    }
}

void reverse()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(graph[i][j] && graph[j][i])
            {
                graph[i][j] = graph[j][i] = false;
            }
            else
            {
                graph[i][j] = graph[j][i] = true;
            }
        }
        graph[i][i] = false;
    }
}

bool paint(int x, bool c)
{
    set[setNumber][color[x] = c][0] ++;
    set[setNumber][color[x]][set[setNumber][color[x]][0]] = x;
    for(int i=1;i<=n;i++)
    {
        if(graph[x][i])
        {
            if(-1 == color[i])
            {
                if(!paint(i, c^1))
                {
                    return false;
                }
            }
            else if(color[x] == color[i])
            {
                return false;
            }
        }
    }
    return true;
}

void find()
{
    memset(dp[1], false, sizeof(dp[1]));
    dp[1][100] = true;
    for(int i=0;i<setNumber;i++)
    {
        memset(dp[i&1],false,sizeof(dp[i&1]));
        for(int j=-100;j<=100;j++)
        {
            if(dp[(i+1)&1][j+100])
            {
                int temp = set[i][0][0] - set[i][1][0];
                if(j+temp >= -100 && j+temp <= 100)
                {
                    dp[i&1][j+temp+100] = true;
                    path[i][j+temp+100][0] = 0;
                    path[i][j+temp+100][1] = j+100;
                }
                if(j-temp >= -100 && j-temp <= 100)
                {
                    dp[i&1][j-temp+100] = true;
                    path[i][j-temp+100][0] = 1;
                    path[i][j-temp+100][1] = j+100;
                }
            }
        }
    }
}

void output(int array[])
{
    printf("%d",array[0]);
    for(int i=1;i<=array[0];i++)
    {
        printf(" %d",array[i]);
    }
    printf("\n");
}

void answer()
{
    int final;
    for(int i=0;i<=100;i++)
    {
        if(dp[(setNumber+1)&1][100+i])
        {
            final = 100 + i;
            break;
        }
        if(dp[(setNumber+1)&1][100-i])
        {
            final = 100 - i;
            break;
        }
    }
    result[0][0] = result[1][0] = 0;
    for(int i=setNumber-1;i>=0;i--)
    {
        for(int j=1;j<=set[i][path[i][final][0]][0];j++)
        {
            result[0][0] ++;
            result[0][result[0][0]] = set[i][path[i][final][0]][j];
        }
        path[i][final][0] = (path[i][final][0]+1)&1;
        for(int j=1;j<=set[i][path[i][final][0]][0];j++)
        {
            result[1][0] ++;
            result[1][result[1][0]] = set[i][path[i][final][0]][j];
        }
        final = path[i][final][1];
    }
    output(result[0]);
    output(result[1]);
}

int main(int argc, char *argv[])
{
    input();
    reverse();
    memset(color, -1, sizeof(color));
    memset(set, 0, sizeof(set));
    bool flag = true;
    setNumber = 0;
    for(int i=1;i<=n;i++)
    {
        if(-1 == color[i])
        {
            if(paint(i,0))
            {
                ++ setNumber;
            }
            else
            {
                flag = false;
                break;
            }
        }
    }
    if(flag)
    {
        find();
        answer();
    }
    else
    {
        printf("No solution\n");
    }
    return 0;
}
