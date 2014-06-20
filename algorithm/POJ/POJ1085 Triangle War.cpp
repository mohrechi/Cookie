#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int END = (1 << 18) - 1;

int EDGE[11][11] = {
    {0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,2,3,4,0,0,0,0,0},
    {0,1,2,0,0,5,6,0,0,0,0},
    {0,0,3,0,0,7,0,9,10,0,0},
    {0,0,4,5,7,0,8,0,11,12,0},
    {0,0,0,6,0,8,0,0,0,13,14},
    {0,0,0,0,9,0,0,0,15,0,0},
    {0,0,0,0,10,11,0,15,0,16,0},
    {0,0,0,0,0,12,13,0,16,0,17},
    {0,0,0,0,0,0,0,14,0,17,0}
};
int TRI[9] = {7, 152, 52, 352, 34304, 3200, 71680, 12544, 155648};

inline int getScore(int status, int x)
{
    int score = 0;
    int next = status | x;
    for (int i = 0; i < 9; ++i)
    {
        if ((status & TRI[i]) != TRI[i])
        {
            if ((next & TRI[i]) == TRI[i])
            {
                ++score;
            }
        }
    }
    return score;
}

int maxSearch(int, int, int, int);
int minSearch(int, int, int, int);

int maxSearch(int status, int beta, int a, int b)
{
    if (a >= 5) return 1;
    if (b >= 5) return -1;
    if (status == END) return a > b ? 1 : -1;
    int alpha = -1;
    int remain = (~status) & END;
    while (remain)
    {
        int x = remain & (-remain);
        int next = status | x;
        int score = getScore(status, x);
        if (score > 0)
        {
            alpha = max(alpha, maxSearch(next, beta, a + score, b));
        }
        else
        {
            alpha = max(alpha, minSearch(next, alpha, a, b));
        }
        if (alpha >= beta)
        {
            break;
        }
        remain -= x;
    }
    return alpha;
}

int minSearch(int status, int alpha, int a, int b)
{
    if (a >= 5) return 1;
    if (b >= 5) return -1;
    if (status == END) return a > b ? 1 : -1;
    int beta = 1;
    int remain = (~status) & END;
    while (remain)
    {
        int x = remain & (-remain);
        int next = status | x;
        int score = getScore(status, x);
        if (score > 0)
        {
            beta = min(beta, minSearch(next, alpha, a, b + score));
        }
        else
        {
            beta = min(beta, maxSearch(next, beta, a, b));
        }
        if (alpha >= beta)
        {
            break;
        }
        remain -= x;
    }
    return beta;
}

int main()
{
    int T, m, x, y;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d", &m);
        int a = 0, b = 0, status = 0;
        bool isA = true;
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d", &x, &y);
            int score = getScore(status, 1 << EDGE[x][y]);
            status |= 1 << EDGE[x][y];
            if (isA)
            {
                a += score;
            }
            else
            {
                b += score;
            }
            if (score == 0)
            {
                isA = !isA;
            }
        }
        bool flag;
        if (isA)
        {
            flag = maxSearch(status, 1, a, b) > 0;
        }
        else
        {
            flag = minSearch(status, -1, a, b) > 0;
        }
        printf("Game %d: %c wins.\n", t, flag ? 'A' : 'B');
    }
    return 0;
}
