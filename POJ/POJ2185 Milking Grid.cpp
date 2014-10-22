#include <cstdio>
#include <cstring>
static const int MAXR = 10005;
static const int MAXC = 80;
int r, c;
int next[MAXR], repeat[MAXC];
char grid[MAXR][MAXC];

int main()
{
    scanf("%d%d",&r,&c);
    for(int i=0;i<r;++i)
    {
        scanf("%s", grid[i]);
        for(int j=1;j<c;++j)
        {
            int x, y;
            for(x=0,y=0;x<c;++x,++y)
            {
                if(y == j)
                {
                    y = 0;
                }
                if(grid[i][x] != grid[i][y])
                {
                    break;
                }
            }
            if(x == c)
            {
                ++repeat[j];
            }
        }
    }
    int column;
    for(column=1;column<c;++column)
    {
        if(repeat[column] == r)
        {
            break;
        }
    }
    for(int i=0;i<r;++i)
    {
        grid[i][column] = 0;
    }
    next[0] = -1;
    for(int i=1,j=-1;i<r;++i)
    {
        while(j!=-1 && strcmp(grid[j+1], grid[i]))
        {
            j = next[j];
        }
        if(!strcmp(grid[j+1],grid[i]))
        {
            ++j;
        }
        next[i] = j;
    }
    printf("%d\n",(r-1-next[r-1])*column);
    return 0;
}
