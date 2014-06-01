#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000000;

int a[MAXN], b[MAXN];

int main()
{
    int T, n, k;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int i = 0, j = 0;
        a[0] = b[0] = 1;
        scanf("%d%d", &n, &k);
        while (n > a[i])
        {
            ++i;
            a[i] = b[i - 1] + 1;
            while (k * a[j + 1] < a[i])
            {
                ++j;
            }
            if (k * a[j] < a[i])
            {
                b[i] = b[j] + a[i];
            }
            else
            {
                b[i] = a[i];
            }
        }
        printf("Case %d: ", t);
        if (n == a[i])
        {
            puts("lose");
        }
        else
        {
            int ans;
            while (n)
            {
                if (n >= a[i])
                {
                    n -=a[i];
                    ans = a[i];
                }
                --i;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
