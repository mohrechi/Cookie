#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 501;
const int MOD = 1000000007;

long long I[MAXN];

int main()
{
    int n, x;
    while (~scanf("%d", &n))
    {
        int num1 = 0, num2 = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &x);
            if (x == 1)
            {
                ++num1;
            }
            else
            {
                ++num2;
            }
        }
        I[0] = I[1] = 1;
        for (int i = 2; i <= num1; ++i)
        {
            I[i] = (I[i - 1] + (i - 1) * I[i - 2]) % MOD;
        }
        long long ans = I[num1];
        for (int i = n; i > num1; --i)
        {
            ans = (ans * i) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
