#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXM = 300005;

int n, m;
int num[MAXM];

bool judge(int mid)
{
    int sum = 0;
    for (int i = 0; i < m; ++i)
    {
        if (num[i] % mid == 0)
        {
            sum += num[i] / mid;
        }
        else
        {
            sum += num[i] / mid + 1;
        }
    }
    return sum <= n;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &num[i]);
            ans = max(ans, num[i]);
        }
        int left = 1, right = ans;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (judge(mid))
            {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
