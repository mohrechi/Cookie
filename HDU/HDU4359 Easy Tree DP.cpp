#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 400;
const int MOD = 1000000007;

bool visit[MAXN][MAXN];
__int64 treeNum[MAXN][MAXN];
bool vc[MAXN][MAXN];
__int64 nc[MAXN][MAXN];

__int64 c(__int64 x, __int64 y)
{
    if(vc[x][y])
    {
        return nc[x][y];
    }
    if(x == 0 || y == 0)
    {
        return 1;
    }
    vc[x][y] = true;
    if(y > (x >> 1))
    {
        return nc[x][y] = c(x, x - y);
    }
    return nc[x][y] = (c(x - 1, y - 1) + c(x - 1, y)) % MOD;
}

__int64 dfs(__int64 num, __int64 depth)
{
    if(depth <= 0)
    {
        return 0;
    }
    if(num == 1)
    {
        return 1;
    }
    if(visit[num][depth])
    {
        return treeNum[num][depth];
    }
    __int64 res = (num * ((dfs(num - 1, depth - 1) << 1) % MOD)) % MOD;
    for(int i=1;i<num-1;++i)
    {
        res += (num * ((c(num - 2, num - i - 1) * ((dfs(i, depth - 1) * dfs(num - i - 1, depth - 1)) % MOD)) % MOD)) % MOD;
        res %= MOD;
    }
    visit[num][depth] = true;
    return treeNum[num][depth] = res;
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        __int64 n, d;
        scanf("%I64d%I64d",&n,&d);
        __int64 ans = (dfs(n, d) - dfs(n, d - 1) + MOD) % MOD;
        printf("Case #%d: %I64d\n", cas, ans);
    }
    return 0;
}
