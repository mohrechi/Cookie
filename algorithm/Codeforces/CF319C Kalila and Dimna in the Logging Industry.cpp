#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int n;
long long a[MAXN], b[MAXN];
long long dp[MAXN];
int top, head, stack[MAXN];

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            cin >> b[i];
        }
        head = 0;
        top = 1;
        stack[0] = 1;
        dp[1] = 0;
        for (int i = 2; i <= n; ++i)
        {
            while (head < top - 1)
            {
                if (dp[stack[head]] + a[i] * b[stack[head]] < dp[stack[head + 1]] + a[i] * b[stack[head + 1]])
                {
                    break;
                }
                ++head;
            }
            dp[i] = dp[stack[head]] + a[i] * b[stack[head]];
            //cout << i << " " << dp[i] << endl;
            while (top > head + 1)
            {
                int j = stack[top - 1];
                int k = stack[top - 2];
                if ((double)(dp[i] - dp[j]) / (b[i] - b[j]) < (double)(dp[j] - dp[k]) / (b[j] - b[k]))
                {
                    break;
                }
                --top;
            }
            stack[top++] = i;
        }
        cout << dp[n] << endl;
    }
    return 0;
}
