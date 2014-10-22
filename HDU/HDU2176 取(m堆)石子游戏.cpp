#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;

int a[MAXN];

int main()
{
    int n, b, c;
    while (scanf("%d", &n), n)
    {
        b = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            b ^= a[i];
        }
        sort(a, a + n);
        if (b)
        {
            puts("Yes");
            for (int i = 0; i < n; ++i)
            {
                if (i == 0 || a[i] != a[i - 1])
                {
                    if (a[i] >= (b ^ a[i]))
                    {
                        printf("%d %d\n", a[i], b ^ a[i]);
                    }
                }
            }
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}
