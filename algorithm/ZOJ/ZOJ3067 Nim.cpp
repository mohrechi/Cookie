#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, a[1005], b, c;
    while (scanf("%d", &n), n)
    {
        b = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
            b ^= a[i];
        }
        if (b)
        {
            c = 0;
            for (int i = 0; i < n; ++i)
            {
                if (a[i] >= (b ^ a[i]))
                {
                    ++c;
                }
            }
            printf("%d\n", c);
        }
        else
        {
            puts("0");
        }
    }
    return 0;
}
