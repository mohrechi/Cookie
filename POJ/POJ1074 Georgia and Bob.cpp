#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int a[MAXN];

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        int s = 0;
        for (int i = n; i > 0; i -= 2)
        {
            s ^= a[i] - a[i - 1] - 1;
        }
        if (s)
        {
            puts("Georgia will win");
        }
        else
        {
            puts("Bob will win");
        }
    }
    return 0;
}
