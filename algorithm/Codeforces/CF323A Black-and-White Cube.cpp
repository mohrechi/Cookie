#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        if (n & 1)
        {
            printf("-1\n");
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    for (int k = 0; k < n; ++k)
                    {
                        printf("%c", (min(min(j, n - j - 1), min(k, n - k - 1)) + i) & 1 ? 'b' : 'w');
                    }
                    printf("\n");
                }
                printf("\n");
            }
        }
    }
    return 0;
}
