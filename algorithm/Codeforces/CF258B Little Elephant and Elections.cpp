#include <cstdio>
#include <cstring>
const int MAXN = 1000000001;
const int MAXM = 11;
const int MOD = 1000000007;

int len;
long long luckyNumber[MAXM][MAXM];
long long currentNumber[MAXM][MAXM];

void init()
{
    luckyNumber[0][0] = 1;
    luckyNumber[1][0] = 8;
    luckyNumber[1][1] = 2;
    for(int i=2;i<MAXM;++i)
    {
        luckyNumber[i][0] = (luckyNumber[i-1][0] * 8) % MOD;
        for(int j=1;j<=i;++j)
        {
            luckyNumber[i][j] = (((luckyNumber[i-1][j-1] * 2) % MOD) + ((luckyNumber[i-1][j] * 8) % MOD)) % MOD;
        }
    }
}

inline int getLuckCount(int x)
{
    if(x <= 4)
    {
        return 0;
    }
    if(x <= 7)
    {
        return 1;
    }
    return 2;
}

void getCurrentNumber(int n)
{
    memset(currentNumber, 0, sizeof(currentNumber));
    currentNumber[0][0] = 1;
    int m;
    int luckCount, noneCount;
    len = 0;
    while(n)
    {
        ++ len;
        m = n % 10;
        n /= 10;
        if(m == 4 || m == 7)
        {
            for(int i=1;i<=len;++i)
            {
                currentNumber[len][i] = currentNumber[len - 1][i - 1];
            }
        }
        else
        {
            for(int i=0;i<len;++i)
            {
                currentNumber[len][i] = currentNumber[len - 1][i];
            }
        }
        luckCount = getLuckCount(m);
        noneCount = m - luckCount;
        currentNumber[len][0] += luckyNumber[len - 1][0] * noneCount;
        for(int i=1;i<=len;++i)
        {
            currentNumber[len][i] += luckyNumber[len - 1][i] * noneCount + luckyNumber[len - 1][i - 1] * luckCount;
        }
    }
    -- currentNumber[len][0];
}

inline int getMaxLucky()
{
    for(int i=len;i>=1;--i)
    {
        if(currentNumber[len][i])
        {
            return i;
        }
    }
}

int visit[6];

long long C(long long a, long long b)
{
    long long c = 1;
    memset(visit, 0, sizeof(visit));
    for(int i=2;i<=b;++i)
    {
        int temp = i;
        for(int j=2;j<=5;++j)
        {
            while(temp % j == 0)
            {
                temp /= j;
                ++ visit[j];
            }
        }
    }
    for(int i=0;i<b;++i)
    {
        long long temp = a;
        for(int j=2;j<=5;++j)
        {
            while(visit[j] && (temp % j == 0))
            {
                -- visit[j];
                temp /= j;
            }
        }
        c = (c * temp) % MOD;
        -- a;
    }
    return c;
}

long long ans;
long long maxNumber;
int count[MAXM];

void divide(int cur, int total, int top, int depth)
{
    if(total > top)
    {
        return;
    }
    if(depth == 6)
    {
        if(total <= top)
        {
            long long way = 1;
            for(int i=0;i<=top;++i)
            {
                if(count[i])
                {
                    if(count[i] > currentNumber[len][i])
                    {
                        return;
                    }
                    way = (way * C(currentNumber[len][i], count[i])) % MOD;
                }
            }
            long long cnt = 0;
            for(int i=total+1;i<=top+1;++i)
            {
                cnt += currentNumber[len][i];
            }
            ans = (ans + (way * cnt) % MOD) % MOD;
        }
        return;
    }
    for(int i=cur;total+i<=top;++i)
    {
        ++ count[i];
        divide(i, total + i, top, depth + 1);
        -- count[i];
    }
}

int main()
{
    int n;
    init();
    while(~scanf("%d", &n))
    {
        getCurrentNumber(n);
        ans = 0;
        maxNumber = currentNumber[len][getMaxLucky()];
        divide(0, 0, getMaxLucky() - 1, 0);
        ans = (ans * 720) % MOD;
        printf("%I64d\n", ans);
    }
    return 0;
}
