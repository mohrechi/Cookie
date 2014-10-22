#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 24;
const int MAXK = 2;
const int MOD = 1e9 + 7;

int n, k;
int a[MAXN + 5], b[MAXK + 5];
int dp[(1 << MAXN) + 5];
long long sum[(1 << MAXN) + 5];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
        sum[1 << i] = a[i];
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &b[i]);
    }
    dp[0] = 1;
    for (int i = 1; i < (1 << n); ++i)
    {
        if (i & (i - 1))
        {
            sum[i] = sum[i & (i - 1)] + sum[(i & (i - 1)) ^ i];
        }
        bool flag = true;
        for (int j = 0; j < k; ++j)
        {
            if (sum[i] == b[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int j = 0; j < n; ++j)
            {
                if ((1 << j) & i)
                {
                    dp[i] += dp[i ^ (1 << j)];
                    if (dp[i] >= MOD)
                    {
                        dp[i] -= MOD;
                    }
                }
            }
        }
    }
    printf("%d\n", dp[(1 << n) - 1]);
    return 0;
}
