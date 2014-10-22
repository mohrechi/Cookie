#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 500005;

int len[MAXN];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &len[i]);
        }
        sort(len, len + n);
        int ans = 0;
        long long sum = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            sum += len[i];
            if (sum > n - i - 2)
            {
                ans = n - i - 1;
                break;
            }
            else if (sum == n - i - 2)
            {
                ans = n - i - 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
