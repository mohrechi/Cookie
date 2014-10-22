#include <cstdio>
#include <algorithm>
using namespace std;

int a[100000];

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        int c = 0;
        scanf("%d", &n);
        for (int i = 1; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                a[c++] = i;
                a[c++] = n / i;
            }
        }
        sort(a, a + c);
        printf("%d", a[0]);
        for (int i = 1; i < c; ++i)
        {
            if (a[i] != a[i - 1])
            {
                printf(" %d", a[i]);
            }
        }
        putchar('\n');
    }
    return 0;
}
