#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 105;

int a[MAXN];

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for (int i = 0; i < n; ++i)
        {
            if (i)
            {
                putchar(' ');
            }
            printf("%d", a[i]);
        }
        putchar('\n');
    }
    return 0;
}
