#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100;

int n, m;
char board[MAXN][MAXN];

bool dfs()
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < m - 1; ++j)
        {
            if (board[i][j] == '0' && board[i][j + 1] == '0' &&
                board[i + 1][j] == '0' && board[i + 1][j + 1] == '0')
            {
                board[i][j] = board[i][j + 1] = '1';
                board[i + 1][j] = board[i + 1][j + 1] = '1';
                if (!dfs())
                {
                    board[i][j] = board[i][j + 1] = '0';
                    board[i + 1][j] = board[i + 1][j + 1] = '0';
                    return true;
                }
                board[i][j] = board[i][j + 1] = '0';
                board[i + 1][j] = board[i + 1][j + 1] = '0';
            }
        }
    }
    return false;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", board[i]);
        }
        puts(dfs() ? "Yes" : "No");
    }
    return 0;
}
