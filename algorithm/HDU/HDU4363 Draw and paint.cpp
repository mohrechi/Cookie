#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

int dp[41][41][5][5][5][5];
bool visit[41][41][5][5][5][5];
int restNumber[] =
{
    4, 3,
    3, 2,
    3, 2, 2, 1,
    3, 2, 2, 1, 2, 1, 1, 0
};

inline int getSum(const int &a, const int &b)
{
    return (1 << a) | (1 << b);
}

inline int getSum(const int &a, const int &b, const int &c)
{
    return getSum(a, b) | (1 << c);
}

inline int getSum(const int &a, const int &b, const int &c, const int &d)
{
    return (getSum(a, b) | getSum(c, d)) & 0x0f;
}

int dfs(int h, int w, int a, int b, int c, int d)
{
    if(visit[h][w][a][b][c][d])
    {
        return dp[h][w][a][b][c][d];
    }
    visit[h][w][a][b][c][d] = true;
    __int64 validNumber = restNumber[getSum(a, b, c, d)];
    if(h > 1)
    {
        int top = getSum(a, c, d);
        int bottom = getSum(b, c, d);
        for(int i=1;i<h;++i)
        {
            for(int j=0;j<4;++j)
            {
                if((top & (1<<j)) == 0)
                {
                    validNumber += dfs(w, i, d, c, j, b);
                    validNumber -= restNumber[getSum(j, b, c, d)];
                }
                if((bottom & (1<<j)) == 0)
                {
                    validNumber += dfs(w, i, d, c, a, j);
                }
            }
        }
    }
    return dp[h][w][a][b][c][d] = (int)(validNumber % MOD);
}

int main()
{
    int caseNumber, w, h;
    scanf("%d", &caseNumber);
    while(caseNumber --)
    {
        scanf("%d%d", &w, &h);
        printf("%d\n", dfs(w, h, 4, 4, 4, 4));
    }
    return 0;
}
