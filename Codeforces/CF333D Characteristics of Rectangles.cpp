#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int n, m;
int a[MAXN][MAXN];

bool visit[MAXN][MAXN];
int set[MAXN], setNum;

bool judge(int mid)
{
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < n; ++i)
    {
        setNum = 0;
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] >= mid)
            {
                set[setNum++] = j;
            }
        }
        for (int j = 0; j < setNum; ++j)
        {
            for (int k = j + 1; k < setNum; ++k)
            {
                if (visit[set[j]][set[k]])
                {
                    return true;
                }
                visit[set[j]][set[k]] = true;
            }
        }
    }
    return false;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        int maxValue = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &a[i][j]);
                maxValue = max(maxValue, a[i][j]);
            }
        }
        int left = 0, right = maxValue;
        int ans = 0;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (judge(mid))
            {
                left = mid + 1;
                ans = max(ans, mid);
            }
            else
            {
                right = mid - 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
