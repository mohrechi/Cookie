#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, p, k;
    while (~scanf("%d%d%d", &n, &p, &k))
    {
        if (p - k > 1)
            printf("<< ");
        for (int i = k; i > 0; --i)
            if (p - i > 0)
                printf("%d ", p - i);
        printf("(%d) ", p);
        for (int i = 1; i <= k; ++i)
            if (p + i <= n)
                printf("%d ", p + i);
        if (n > p + k)
            printf(">>");
        putchar('\n');
    }
    return 0;
}
