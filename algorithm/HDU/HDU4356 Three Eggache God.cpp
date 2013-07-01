#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2010;
const int MOD = 1000000007;

__int64 factorial[MAXN];
__int64 n, ans, c[MAXN];
__int64 w[MAXN], a[MAXN];
__int64 cnt[MAXN];

void init()
{
    factorial[0] = 1;
    for(int i=1;i<MAXN;++i)
    {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
}

class TreeArray
{
public:
    inline void init()
    {
        for(int i=1;i<=n;++i)
        {
            c[i] = lowbit(i);
        }
    }

    inline void resume(int x)
    {
        while(x <= n)
        {
            ++ c[x];
            x += lowbit(x);
        }
    }

    inline void remove(int x)
    {
        while(x <= n)
        {
            -- c[x];
            x += lowbit(x);
        }
    }

    inline int getNotSmaller(const int &x) const
    {
        return query(n) - query(x - 1);
    }

private:
    int c[MAXN];
    inline int lowbit(const int &x) const
    {
        return x & (-x);
    }

    inline int query(int x) const
    {
        int sum = 0;
        while(x > 0)
        {
            sum += c[x];
            x -= lowbit(x);
        }
        return sum;
    }
}treeArray;

__int64 solve()
{
    __int64 ans = 0;
    __int64 num1, num2, num3;
    treeArray.init();
    for(int i=1;i<=n;++i)
    {
        num1 = treeArray.getNotSmaller(w[i] + 1);
        num2 = treeArray.getNotSmaller(a[i]);
        num3 = min(num1, num2);
        ans += (num3 * factorial[n - i]) % MOD;
        ans %= MOD;
        cnt[i] = (treeArray.getNotSmaller(w[i] + 1) * factorial[n - i]) % MOD;
        for(int j=i+1;j<=n;++j)
        {
            num2 = treeArray.getNotSmaller(a[j]);
            num3 = num1 * num2 - min(num1, num2);
            ans += (num3 * factorial[n - i - 1]) % MOD;
            ans %= MOD;
        }
        treeArray.remove(w[i]);
    }
    __int64 sum = 0;
    for(int i=n-1;i>=1;--i)
    {
        if(w[i] >= a[i])
        {
            ans = (ans + sum) % MOD;
        }
        sum = (sum + cnt[i]) % MOD;
    }
    return ans;
}

int main()
{
    init();
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%I64d", &n);
        for(int i=1;i<=n;++i)
        {
            scanf("%I64d", &w[i]);
        }
        for(int i=1;i<=n;++i)
        {
            scanf("%I64d", &a[i]);
        }
        printf("Case #%d: %I64d\n", cas, solve());
    }
    return 0;
}
