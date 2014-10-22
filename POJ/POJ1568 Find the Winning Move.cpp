#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1;

int x, y;
char board[4][4];

bool isEnd()
{
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < 4; ++i)
    {
        cnt0 += board[i][i];
        cnt1 += board[i][3 - i];
    }
    if (abs(cnt0) == 4 || abs(cnt1) == 4)
    {
        return true;
    }
    for (int i = 0; i < 4; ++i)
    {
        cnt0 = 0;
        cnt1 = 0;
        for (int j = 0; j < 4; ++j)
        {
            cnt0 += board[i][j];
            cnt1 += board[j][i];
        }
        if (abs(cnt0) == 4 || abs(cnt1) == 4)
        {
            return true;
        }
    }
    return false;
}

int maxSearch(int beta, int cnt);
int minSearch(int alpha, int cnt);

int maxSearch(int beta, int cnt)
{
    if (isEnd())
    {
        return -INF;
    }
    if (cnt == 16)
    {
        return 0;
    }
    int alpha = -INF;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = 1;
                alpha = max(alpha, minSearch(alpha, cnt + 1));
                board[i][j] = 0;
                if (alpha >= beta)
                {
                    x = i;
                    y = j;
                    return alpha;
                }
            }
        }
    }
    return alpha;
}

int minSearch(int alpha, int cnt)
{
    if (isEnd())
    {
        return INF;
    }
    if (cnt == 16)
    {
        return 0;
    }
    int beta = INF;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (board[i][j] == 0)
            {
                board[i][j] = -1;
                beta = min(beta, maxSearch(beta, cnt + 1));
                board[i][j] = 0;
                if (alpha >= beta)
                {
                    return beta;
                }
            }
        }
    }
    return beta;
}

int main()
{
    char s[4];
    while (scanf("%s", s), s[0] == '?')
    {
        int cnt = 0;
        for (int i = 0; i < 4; ++i)
        {
            scanf("%s", board[i]);
            for (int j = 0; j < 4; ++j)
            {
                cnt += board[i][j] != '.';
                if (board[i][j] == 'x')
                {
                    board[i][j] = 1;
                }
                else if (board[i][j] == 'o')
                {
                    board[i][j] = -1;
                }
                else
                {
                    board[i][j] = 0;
                }
            }
        }
        if (maxSearch(INF, cnt) == INF)
        {
            printf("(%d,%d)\n", x, y);
        }
        else
        {
            puts("#####");
        }
    }
    return 0;
}
