#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 105;

int main()
{
    int t, n, a[MAXN];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        printf("%d\n", a[n - 2]);
    }
    return 0;
}
