#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int MOD = 1000000007;

char x[MAXN];
long long dp[MAXN];

int main()
{
    while (~scanf("%s", x))
    {
        int n = strlen(x);
        for (int i = 0; i < n >> 1; ++i)
        {
            swap(x[i], x[n - i - 1]);
        }
        dp[0] = 0;
        for (int i = 0; i < n; ++i)
        {
            dp[i + 1] = (dp[i] << 1) % MOD;
            if (x[i] == '1')
            {
                long long add = 1;
                for (int j = 0; j < i; ++j)
                {
                    add <<= 2;
                    add %= MOD;
                }
                dp[i + 1] += add;
                dp[i + 1] %= MOD;
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}
