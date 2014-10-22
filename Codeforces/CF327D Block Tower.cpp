#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 505;
const int DIR_X[] = {1, 0, -1, 0};
const int DIR_Y[] = {0, 1, 0, -1};

int n, m;
char map[MAXN][MAXN];
bool visit[MAXN][MAXN];

struct Node
{
    char op;
    int x, y;
    inline void output()
    {
        printf("%c %d %d\n", op, x, y);
    }
} node[MAXN * MAXN * 3];
int nodeNum;

inline void addNode(char op, int x, int y)
{
    node[nodeNum].op = op;
    node[nodeNum].x = x;
    node[nodeNum].y = y;
    ++nodeNum;
}

inline bool isInside(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void dfs(int x, int y, int depth)
{
    visit[x][y] = true;
    addNode('B', x, y);
    for (int i = 0; i < 4; ++i)
    {
        int tx = x + DIR_X[i];
        int ty = y + DIR_Y[i];
        if (isInside(tx, ty))
        {
            if (map[tx][ty] == '.')
            {
                if (!visit[tx][ty])
                {
                    dfs(tx, ty, depth + 1);
                }
            }
        }
    }
    if (depth)
    {
        addNode('D', x, y);
        addNode('R', x, y);
    }
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", map[i] + 1);
        }
        nodeNum = 0;
        memset(visit, false, sizeof(visit));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (map[i][j] == '.')
                {
                    if (!visit[i][j])
                    {
                        dfs(i, j, 0);
                    }
                }
            }
        }
        printf("%d\n", nodeNum);
        for (int i = 0; i < nodeNum; ++i)
        {
            node[i].output();
        }
    }
    return 0;
}
