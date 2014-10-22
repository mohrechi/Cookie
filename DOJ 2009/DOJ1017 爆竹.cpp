#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int dirX[] = {0, 1, 0, -1};
const int dirY[] = {1, 0, -1, 0};

int map[MAXN][MAXN];
int dist[MAXN][MAXN];
int queue[MAXN * MAXN];

int main()
{
    int t, n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        int front = 0, rear = 0;
        memset(dist, -1, sizeof(dist));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                scanf("%d", &map[i][j]);
                if(map[i][j])
                {
                    queue[rear ++] = i * 1000 + j;
                    dist[i][j] = 0;
                }
            }
        }
        while(front < rear)
        {
            int x = queue[front] / 1000;
            int y = queue[front] % 1000;
            for(int k=0;k<4;++k)
            {
                int tx = x + dirX[k];
                int ty = y + dirY[k];
                if(tx >= 0 && tx < n)
                {
                    if(ty >= 0 && ty < m)
                    {
                        if(dist[tx][ty] == -1)
                        {
                            dist[tx][ty] = dist[x][y] + 1;
                            queue[rear++] = tx * 1000 + ty;
                        }
                    }
                }
            }
            ++ front;
        }
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(map[i][j] == 0)
                {
                    ans += dist[i][j];
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
