#include <cstdio>
#include <cstring>
static const int MAXN = 105;
static const int MAXM = 205;
int row, column;
bool grid[MAXN][MAXN];
bool way[2][MAXN][MAXN];
static const int DIR_D = 0;
static const int DIR_U = 1;
static const int DIR_R = 2;
static const int DIR_L = 3;
static const int directionX[] = {-1, 1, 0, 0};
static const int directionY[] = {0, 0, -1, 1};


struct Step
{
    int low, high, direction;
}step[MAXM];
int stepNumber;

bool validPosition(int x, int y)
{
    if(x < 1 || x > row || y < 1 || y > column)
    {
        return false;
    }
    return grid[x][y];
}

int main(int argc, char *argv[])
{
    int caseNumber;
    scanf("%d",&caseNumber);
    while(caseNumber--)
    {
        scanf("%d%d",&row, &column);
        for(int i=1;i<=row;++i)
        {
            for(int j=1;j<=column;++j)
            {
                scanf("%d", &grid[i][j]);
                grid[i][j] = !grid[i][j];
                way[0][i][j] = grid[i][j];
            }
        }
        char s[10];
        stepNumber = 0;
        while(scanf("%d%d",&step[stepNumber].low, &step[stepNumber].high), step[stepNumber].low || step[stepNumber].high)
        {
            scanf("%s", s);
            switch(*s)
            {
                case 'U': step[stepNumber++].direction = DIR_U; break;
                case 'D': step[stepNumber++].direction = DIR_D; break;
                case 'L': step[stepNumber++].direction = DIR_L; break;
                case 'R': step[stepNumber++].direction = DIR_R; break;
            }
        }
        int flag = 1;
        for(int k=stepNumber-1;k>=0;--k)
        {
            for(int i=1;i<=row;++i)
            {
                for(int j=1;j<=column;++j)
                {
                    way[flag&1][i][j] = false;
                }
            }
            for(int i=1;i<=row;++i)
            {
                for(int j=1;j<=column;++j)
                {
                    if(way[(flag+1)&1][i][j])
                    {
                        for(int s=1;s<=step[k].high;++s)
                        {
                            if(!validPosition(i + directionX[step[k].direction] * s, j + directionY[step[k].direction] * s))
                            {
                                break;
                            }
                            if(s >= step[k].low)
                            {
                                way[flag&1][i + directionX[step[k].direction] * s][j + directionY[step[k].direction] * s] = true;
                            }
                        }
                    }
                }
            }
            ++flag;
        }
        int answer = 0;
        for(int i=1;i<=row;++i)
        {
            for(int j=1;j<=column;++j)
            {
                answer += way[(flag+1)&1][i][j];
            }
        }
        printf("%d\n",answer);
    }
    return 0;
}
