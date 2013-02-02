#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100001;
const int MOD = 1000000007;

char a[MAXN];
long long dp[MAXN];
long long sum[MAXN];
int last[128];

int main()
{
    while(~scanf("%s", a + 1))
    {
        dp[0] = 1;
        sum[0] = 1;
        memset(last, 0, sizeof(last));
        int n = strlen(a + 1);
        for(int i=1;i<=n;++i)
        {
            dp[i] = (sum[i - 1] - sum[last[a[i]] - 1] + MOD) % MOD;
            sum[i] = (sum[i - 1] + dp[i]) % MOD;
            last[a[i]] = i;
        }
        sum[n] = (sum[n] + MOD - 1) % MOD;
        printf("%lld\n", sum[n]);
    }
    return 0;
}
