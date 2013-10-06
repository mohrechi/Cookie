#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    int n, a[10], m, index;
    scanf("%d", &n);
    m = 0x7fffffff;
    for (int i = 1; i <= 9; ++i)
    {
        scanf("%d", &a[i]);
        if (a[i] <= m)
        {
            m = a[i];
            index = i;
        }
    }
    if (n < m)
    {
        printf("-1\n");
    }
    int k = n / m;
    for (int i = k - 1; i >= 0; --i)
    {
        for (int j = 9; j >= 1; --j)
        {
            if (n >= a[j] && (n - a[j]) / m >= i)
            {
                printf("%d", j);
                n -= a[j];
                break;
            }
        }
    }
    printf("\n");
    return 0;
}
