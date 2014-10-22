#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

enum END_TYPE {WIN = 0, LOSE = 1, TIE = 2};

char board[5][5];
int score[5];

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
        return score[LOSE];
    }
    if (cnt == 16)
    {
        return score[TIE];
    }
    int alpha = -1;
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
        return score[WIN];
    }
    if (cnt == 16)
    {
        return score[TIE];
    }
    int beta = 1;
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
    int T;
    char s[12];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        if (s[0] == 'W')
        {
            score[WIN] = 1;
            score[LOSE] = score[TIE] = -1;
        }
        else if (s[0] == 'L')
        {
            score[LOSE] = 1;
            score[WIN] = score[TIE] = -1;
        }
        else
        {
            score[TIE] = 1;
            score[WIN] = score[LOSE] = -1;
        }
        int cnt = 0, step = 0;
        for (int i = 0; i < 4; ++i)
        {
            scanf("%s", board[i]);
            for (int j = 0; j < 4; ++j)
            {
                cnt += board[i][j] != '.';
                step += board[i][j] == 'x';
                step -= board[i][j] == 'o';
                if (board[i][j] == 'x') board[i][j] = 1;
                else if (board[i][j] == 'o') board[i][j] = -1;
                else board[i][j] = 0;
            }
        }
        if (step & 1)
        {
            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    board[i][j] = -board[i][j];
                }
            }
        }
        if (maxSearch(1, cnt) == 1)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}
