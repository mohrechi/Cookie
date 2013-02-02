#include <cstdio>
#include <cstring>
const int N = 15;
const int M = 23;
const int T = 120;
const int dirX[] = {0, 0, 1, -1};
const int dirY[] = {1, -1, 0, 0};

int map[N][M];
int originMap[N][M];

inline bool inside(int x, int y)
{
    if(x < 0 || x >= N)
    {
        return false;
    }
    if(y < 0 || y >= M)
    {
        return false;
    }
    return true;
}

inline bool judge(int x, int y)
{
    if(!inside(x, y))
    {
        return false;
    }
    return map[x][y] == 0;
}

int main()
{
    int n, x, y;
    while(true)
    {
        for(int i=0;i<N;++i)
        {
            for(int j=0;j<M;++j)
            {
                if(i == 0 && j == 0)
                {
                    if(scanf("%d", &originMap[i][j]) == EOF)
                    {
                        return 0;
                    }
                }
                else
                {
                    scanf("%d", &originMap[i][j]);
                }
            }
        }
        int color[10];
        int posX[4], posY[4], posNum;
        scanf("%d", &n);
        while(n--)
        {
            int ans = 0;
            int timeLimit = 120;
            memcpy(map, originMap, sizeof(map));
            for(int t=0;t<T;++t)
            {
                scanf("%d%d", &x, &y);
                -- x, -- y;
                if(timeLimit <= 0)
                {
                    continue;
                }
                memset(color, 0, sizeof(color));
                posNum = 0;
                -- timeLimit;
                if(map[x][y] == 0)
                {
                    for(int i=0;i<4;++i)
                    {
                        int tx = x + dirX[i];
                        int ty = y + dirY[i];
                        while(judge(tx, ty))
                        {
                            tx += dirX[i];
                            ty += dirY[i];
                        }
                        if(inside(tx, ty))
                        {
                            ++ color[map[tx][ty]];
                            posX[posNum] = tx;
                            posY[posNum] = ty;
                            ++ posNum;
                        }
                    }
                    bool flag = false;
                    for(int i=1;i<=9;++i)
                    {
                        if(color[i] > 1)
                        {
                            flag = true;
                            for(int j=0;j<posNum;++j)
                            {
                                if(map[posX[j]][posY[j]] == i)
                                {
                                    map[posX[j]][posY[j]] = 0;
                                    ++ ans;
                                }
                            }
                        }
                    }
                    if(!flag)
                    {
                        timeLimit -= 6;
                    }
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
