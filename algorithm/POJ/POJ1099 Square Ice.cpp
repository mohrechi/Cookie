#include <iostream>
#include <stdio.h>
using namespace std;
#define right(i) (i==1||i==5||i==6)
#define left(i) (i==1||i==3||i==4)
#define up(i) (i==2||i==3||i==6)
#define down(i) (i==2||i==4||i==5)

const int debug = 0;
int mat[11][11];
int n;
struct Node
{
    int x, y;
}p[121];
int dirx[] = {-1,0,1,0};
int diry[] = {0,-1,0,1};

bool inside(int x, int y)
{
    return x>=0 && x<n && y>=0 && y<n;
}

void print(void)
{
    int i, j;
    for(i=0; i<4*n+3; i++)
    {
        printf("*");
    }
    printf("\n");
    for(i=0; i<n; i++)
    {
        if(i)
        {
            printf("*");
            for(j=0; j<n; j++)
            {
                if(up(mat[i][j]))
                {
                    printf("  | ");
                }
                else
                {
                    printf("    ");
                }
            }
            printf(" *\n");
        }
        printf("*");
        for(j=0; j<n; j++)
        {
            if(left(mat[i][j]))
            {
                printf("H-");
            }
            else if(j && right(mat[i][j-1]))
            {
                printf("H ");
            }
            else
            {
                printf("  ");
            }
            printf("O");
            if(right(mat[i][j]))
            {
                printf("-");
            }
            else if(j<n-1 && left(mat[i][j+1]))
            {
                printf(" ");
            }
            else
            {
                printf(" ");
            }
        }
        if(right(mat[i][n-1]))
        {
            printf("H");
        }
        else
        {
            printf(" ");
        }
        printf("*\n");
        if(i!=n-1)
        {
            printf("*");
            for(j=0; j<n; j++)
            {
                if(down(mat[i][j]))
                {
                    printf("  | ");
                }
                else
                {
                    printf("    ");
                }
            }
            printf(" *\n");
            printf("*");
            for(j=0; j<n; j++)
            {
                if(down(mat[i][j]) || up(mat[i+1][j]))
                {
                    printf("  H ");
                }
                else
                {
                    printf("    ");
                }
            }
            printf(" *\n");
        }
    }
    for(i=0; i<4*n+3; i++)
    {
        printf("*");
    }
    printf("\n");
}

bool check(int x, int y, int i)
{
    if(x==0)
    {
        if(up(i))
        {
            return 0;
        }
    }
    if(x==n-1)
    {
        if(down(i))
        {
            return 0;
        }
    }
    int a = x+dirx[3], b = y+diry[3];
    if(right(i))
    {
        if(inside(a, b) && left(mat[a][b]))
        {
            return 0;
        }
    }
    a = x+dirx[1], b = y+diry[1];
    if(left(i))
    {
        if(inside(a, b) && right(mat[a][b]))
        {
            return 0;
        }
    }
    a = x+dirx[0], b = y+diry[0];
    if(up(i))
    {
        if(inside(a, b) && down(mat[a][b]))
        {
            return 0;
        }
    }
    a = x+dirx[2], b = y+diry[2];
    if(down(i))
    {
        if(inside(a, b) && up(mat[a][b]))
        {
            return 0;
        }
    }
    return 1;
}

bool found;
int blank;

void dfs(int id)
{
    if(found)
    {
        return;
    }
    if(id==blank)
    {
        found = 1;
        return;
    }
    int k;
    for(k=3; k<=6; k++)
    {
        if(check(p[id].x, p[id].y, k))
        {
            mat[p[id].x][p[id].y] = k;
            dfs(id+1);
            if(found)
            {
                return;
            }
            mat[p[id].x][p[id].y] = 0;
        }
    }
}

void solve(void)
{
    if(!mat[0][0])
    {
        mat[0][0] = 4;
    }
    if(!mat[0][n-1])
    {
        mat[0][n-1] = 5;
    }
    if(!mat[n-1][0])
    {
        mat[n-1][0] = 3;
    }
    if(!mat[n-1][n-1])
    {
        mat[n-1][n-1] = 6;
    }
    found = blank = 0;
    int i, j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(!mat[i][j])
            {
                p[blank].x = i, p[blank++].y = j;
            }
        }
    }
    dfs(0);
    print();
}

int main(void)
{
    int i, j, k=0;
    while(cin >> n && n)
    {
        blank = 0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                cin >> mat[i][j];
                if(mat[i][j]==-1)
                {
                    mat[i][j] = 2;
                }
            }
        }
        if(k)
        {
            printf("\n");
        }
        printf("Case %d:\n\n", ++k);
        solve();
    }
    return 0;
}
