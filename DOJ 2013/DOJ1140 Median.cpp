#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int main()
{
    int T;
    int n, a[MAXN];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        if (n & 1)
        {
            printf("%d\n", a[n >> 1]);
        }
        else
        {
            int temp = a[n >> 1] + a[(n >> 1) - 1];
            if (temp % 2 == 0)
            {
                printf("%d\n", temp / 2);
            }
            else
            {
                printf("%.1lf\n", temp * 0.5);
            }
        }
    }
    return 0;
}
