#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 20;
const int INF = 100;
const int DIR_X[] = {0, 1, 0, -1};
const int DIR_Y[] = {1, 0, -1, 0};

int n, m, x, y;
int ox[MAXN], oy[MAXN];
char board[MAXN][MAXN];
bool visit[MAXN][MAXN];
int result[(1 << 10) + 5][(1 << 10) + 5];

int dfs(int i, int j)
{
    int res = 1;
    visit[i][j] = true;
    for (int k = 0; k < 4; ++k)
    {
        int ti = i + DIR_X[k];
        int tj = j + DIR_Y[k];
        if (ti >= 0 && ti < n)
        {
            if (tj >= 0 && tj < n)
            {
                if (!visit[ti][tj])
                {
                    if (board[ti][tj] == board[i][j])
                    {
                        res += dfs(ti, tj);
                    }
                }
            }
        }
    }
    return res;
}

int getScore(int status0, int status1)
{
    if (result[status0][status1] != INF)
    {
        return result[status0][status1];
    }
    int a = 0, b = 0;
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < m; ++i)
    {
        if (status0 & (1 << i))
        {
            board[ox[i]][oy[i]] = '0';
        }
        else
        {
            board[ox[i]][oy[i]] = '1';
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visit[i][j])
            {
                if (board[i][j] == '0')
                {
                    a = max(a, dfs(i, j));
                }
                else
                {
                    b = max(b, dfs(i, j));
                }
            }
        }
    }
    return result[status0][status1] = a - b;
}

int maxSearch(int, int, int);
int minSearch(int, int, int);

int maxSearch(int beta, int status0, int status1)
{
    int status = status0 | status1;
    if (status == (1 << m) - 1)
    {
        return getScore(status0, status1);
    }
    int alpha = -INF;
    for (int i = 0; i < m; ++i)
    {
        if ((status & (1 << i)) == 0)
        {
            int tmp = minSearch(alpha, status0 | (1 << i), status1);
            if (tmp > alpha)
            {
                alpha = tmp;
                if (status == 0)
                {
                    x = ox[i];
                    y = oy[i];
                }
            }
            if (alpha >= beta)
            {
                break;
            }
        }
    }
    return alpha;
}

int minSearch(int alpha, int status0, int status1)
{
    int status = status0 | status1;
    if (status == (1 << m) - 1)
    {
        return getScore(status0, status1);
    }
    int beta = INF;
    for (int i = 0; i < m; ++i)
    {
        if ((status & (1 << i)) == 0)
        {
            int tmp = maxSearch(beta, status0, status1 | (1 << i));
            if (tmp < beta)
            {
                beta = tmp;
                if (status == 0)
                {
                    x = ox[i];
                    y = oy[i];
                }
            }
            if (alpha >= beta)
            {
                break;
            }
        }
    }
    return beta;
}

int main()
{
    while (scanf("%d", &n), n)
    {
        int cnt = 0;
        m = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", board[i]);
            for (int j = 0; j < n; ++j)
            {
                cnt += board[i][j] == '0';
                cnt -= board[i][j] == '1';
                if (board[i][j] == '.')
                {
                    ox[m] = i;
                    oy[m] = j;
                    ++m;
                }
            }
        }
        for (int i = 0; i < (1 << m); ++i)
        {
            for (int j = 0; j < (1 << m); ++j)
            {
                result[i][j] = INF;
            }
        }
        int ans = cnt ? -minSearch(-INF, 0, 0) : maxSearch(INF, 0, 0);
        printf("(%d,%d) %d\n", x, y, ans);
    }
    return 0;
}
