#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 205;
const int MAXK = 14;
const int INF = 0x3f3f3f3f;
const int DIR_X[] = {0, 1, 0, -1};
const int DIR_Y[] = {1, 0, -1, 0};

//#define DEBUG

int n, m, k;
int map[MAXN][MAXN];
int dp[1 << MAXK][MAXK];
int posX[MAXK], posY[MAXK];

int qx[MAXN * MAXN];
int qy[MAXN * MAXN];
int d[MAXN][MAXN];
bool visit[MAXN][MAXN];

void spfa(int index)
{
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(d, 0x3f, sizeof(d));
    qx[0] = posX[index];
    qy[0] = posY[index];
    d[posX[index]][posY[index]] = map[posX[index]][posY[index]];
    visit[posX[index]][posY[index]] = true;
    while (front != rear)
    {
        int x = qx[front];
        int y = qy[front];
        for (int k = 0; k < 4; ++k)
        {
            int tx = x + DIR_X[k];
            int ty = y + DIR_Y[k];
            if (tx >= 1 && tx <= n)
            {
                if (ty >= 1 && ty <= m)
                {
                    if (map[tx][ty] != -1)
                    {
                        if (d[tx][ty] > d[x][y] + map[tx][ty])
                        {
                            d[tx][ty] = d[x][y] + map[tx][ty];
                            if (!visit[tx][ty])
                            {
                                visit[tx][ty] = true;
                                qx[rear] = tx;
                                qy[rear] = ty;
                                if (++rear >= MAXN * MAXN)
                                {
                                    rear = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        visit[x][y] = false;
        if (++front >= MAXN * MAXN)
        {
            front = 0;
        }
    }
}

int dist[MAXK][MAXK];
int distEdge[MAXK];

void initDist()
{
    memset(dist, 0x3f, sizeof(dist));
    memset(distEdge, 0x3f, sizeof(distEdge));
    for (int i = 0; i < k; ++i)
    {
        spfa(i);
        for (int j = 0; j < k; ++j)
        {
            dist[i][j] = min(dist[i][j], d[posX[j]][posY[j]]);
        }
        for (int j = 1; j <= n; ++j)
        {
            distEdge[i] = min(distEdge[i], d[j][1]);
            distEdge[i] = min(distEdge[i], d[j][m]);
        }
        for (int j = 1; j <= m; ++j)
        {
            distEdge[i] = min(distEdge[i], d[1][j]);
            distEdge[i] = min(distEdge[i], d[n][j]);
        }
    }
    #ifdef DEBUG
    printf("Edge Dist: \n");
    for (int i = 0; i < k; ++i)
    {
        printf("%d ", distEdge[i]);
    }
    printf("\n");
    printf("Dist: \n");
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
    #endif
}

int qs[(1 << MAXK) * MAXK];
int qk[(1 << MAXK) * MAXK];
bool dpVisit[(1 << MAXK)][MAXK];

void calc()
{
    int front = 0, rear = 0;
    memset(dp, 0x3f, sizeof(dp));
    memset(dpVisit, false, sizeof(dpVisit));
    for (int i = 0; i < k; ++i)
    {
        qs[rear] = 1 << i;
        qk[rear] = i;
        dp[1 << i][i] = distEdge[i];
        dpVisit[1 << i][i] = true;
        ++rear;
    }
    while (front != rear)
    {
        int us = qs[front];
        int uk = qk[front];
        for (int i = 0; i < k; ++i)
        {
            if ((us & (1 << i)) == 0)
            {
                if (dp[us | (1 << i)][i] > dp[us][uk] + dist[uk][i] - map[posX[uk]][posY[uk]])
                {
                    dp[us | (1 << i)][i] = dp[us][uk] + dist[uk][i] - map[posX[uk]][posY[uk]];
                    if (!dpVisit[us | (1 << i)][i])
                    {
                        dpVisit[us | (1 << i)][i] = true;
                        qs[rear] = us | (1 << i);
                        qk[rear] = i;
                        if (++rear >= (1 << MAXK) * MAXK)
                        {
                            rear = 0;
                        }
                    }
                }
            }
        }
        visit[us][uk] = false;
        if (++front >= (1 << MAXK) * MAXK)
        {
            front = 0;
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                scanf("%d", &map[i][j]);
            }
        }
        scanf("%d", &k);
        for (int i = 0; i < k; ++i)
        {
            scanf("%d%d", &posX[i], &posY[i]);
            ++posX[i];
            ++posY[i];
        }
        initDist();
        calc();
        int ans = INF;
        for (int i = 0; i < k; ++i)
        {
            ans = min(ans, dp[(1 << k) - 1][i] + distEdge[i] - map[posX[i]][posY[i]]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
