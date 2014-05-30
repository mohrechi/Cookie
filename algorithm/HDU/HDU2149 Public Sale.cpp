#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        if (n % (m + 1) == 0)
        {
            puts("none");
        }
        else
        {
            bool first = true;
            for (int i = 1; i <= m; ++i)
            {
                if ((n - i) % (m + 1) == 0 || i >= n)
                {
                    if (first)
                    {
                        first = false;
                    }
                    else
                    {
                        putchar(' ');
                    }
                    printf("%d", i);
                }
            }
            putchar('\n');
        }
    }
    return 0;
}
