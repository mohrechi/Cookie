#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 15;
const int dirX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dirY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int m, n;
char map[MAXN][MAXN];
int num[MAXN][MAXN];
int mX[MAXN];
int mY[MAXN];
int mNum;
bool visit[MAXN];

void setMine(int x, int y, int n)
{
    for(int k=0;k<8;++k)
    {
        int tx = x + dirX[k];
        int ty = y + dirY[k];
        num[tx][ty] += n;
    }
}

bool dfs(int pos)
{
    if(pos == mNum)
    {
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(map[i][j] != '#')
                {
                    if(map[i][j] - '0' != num[i][j])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    int x = mX[pos];
    int y = mY[pos];
    if(dfs(pos + 1))
    {
        return true;
    }
    setMine(x, y, 1);
    if(dfs(pos + 1))
    {
        return true;
    }
    setMine(x, y, -1);
    return false;
}

int main()
{
    while(~scanf("%d%d", &m, &n))
    {
        mNum = 0;
        memset(map, 0, sizeof(map));
        for(int i=1;i<=m;++i)
        {
            scanf("%s", map[i] + 1);
            for(int j=1;j<=n;++j)
            {
                if(map[i][j] == '#')
                {
                    mX[mNum] = i;
                    mY[mNum] = j;
                    ++ mNum;
                }
            }
        }
        memset(num, 0, sizeof(num));
        if(dfs(0))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
