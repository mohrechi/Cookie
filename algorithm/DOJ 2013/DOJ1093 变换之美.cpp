#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 5005;

int n;
int a[MAXN], b[MAXN];

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            a[i] += a[i - 1];
        }
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &b[i]);
            b[i] += b[i - 1];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        bool flag = true;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] != b[i])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
