#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int dirX[] = {0, -1, 0, 1};
const int dirY[] = {-1, 0, 1, 0};
const int dirX2[] = {0, 1, 1, 1};
const int dirY2[] = {1, 1, 0, -1};

int n, m, a, b;
char chess[MAXN][MAXN];

int getNum1()
{
    int count = 0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(chess[i][j] == '.')
            {
                for(int k=0;k<4;++k)
                {
                    int ii = i + dirX[k];
                    int jj = j + dirY[k];
                    if(chess[ii][jj] == '*')
                    {
                        ++ count;
                        break;
                    }
                }
            }
        }
    }
    return count;
}

int getNum2()
{
    int count = 0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            for(int k=0;k<4;++k)
            {
                int tCount = 0;
                int tx = i + dirX2[k];
                int ty = j + dirY2[k];
                while(chess[tx][ty] == '*')
                {
                    ++ tCount;
                    tx += dirX2[k];
                    ty += dirY2[k];
                }
                tx = i - dirX2[k];
                ty = j - dirY2[k];
                while(chess[tx][ty] == '*')
                {
                    ++ tCount;
                    tx -= dirX2[k];
                    ty -= dirY2[k];
                }
                if(chess[i][j] == '.')
                {
                    if(tCount >= 4)
                    {
                        ++ count;
                        break;
                    }
                }
                else
                {
                    if(tCount >= 4)
                    {
                        return -1;
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        memset(chess, '.', sizeof(chess));
        for(int i=1;i<=n;++i)
        {
            scanf("%s", chess[i] + 1);
            chess[i][m + 1] = '.';
        }
        scanf("%d%d", &a, &b);
        int num1 = getNum1();
        int num2 = getNum2();
        if(num2 == -1 || a < num1 || b < num2)
        {
            printf("-1\n");
        }
        else
        {
            int ans = 0;
            if(num1 == 0 && num2 == 0)
            {
                ans = 0;
            }
            else
            {
                if(num1)
                {
                    ans = b * 2 + num1;
                    for(int i=0;i<num2;++i)
                    {
                        ans = max(ans, i * 2 + num1 + (a - num1) * 2 + (num2 - i));
                    }
                }
                else
                {
                    ans = max(ans, a * 2 + num2);
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
