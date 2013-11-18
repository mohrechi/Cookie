#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int T, n, a;
    scanf("%d", &T);
    while (T--)
    {
        int m = 0x7fffffff;
        int c = 0, sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n * 2 - 1; ++i)
        {
            scanf("%d", &a);
            c += a < 0;
            m = min(m, abs(a));
            sum += abs(a);
        }
        if ((n & 1) == 0 && (c & 1) == 1)
        {
            sum -= m << 1;
        }
        printf("%d\n", sum);
    }
    return 0;
}
