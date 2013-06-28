#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int n, a[MAXN];
int stack[MAXN], top;
int time[MAXN];

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = n - 1; i >= 0; --i)
        {
            scanf("%d", &a[i]);
        }
        int ans = 0;
        top = 0;
        for (int i = 0; i < n; ++i)
        {
            while (top && a[stack[top - 1]] < a[i])
            {
                --top;
                time[i] = max(time[i] + 1, time[stack[top]]);
            }
            stack[top++] = i;
            ans = max(ans, time[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
