#include <cstdio>
#include <algorithm>
using namespace std;

char s[1000024];

int main()
{
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        if ((n > 1 && k == 1) || k > n)
        {
            printf("-1\n");
            continue;
        }
        for (int i = 0; i < n; ++i)
        {
            if (i & 1)
            {
                s[i] = 'b';
            }
            else
            {
                s[i] = 'a';
            }
        }
        for (int i = 0; i < k; ++i)
        {
            s[n - i - 1] = k - i - 1 + 'a';
        }
        if (n - k - 1 >= 0)
        {
            if (s[n - k - 1] == 'a')
            {
                if (n - k + 1 < n)
                {
                    swap(s[n - k], s[n - k + 1]);
                }
            }
        }
        s[n] = 0;
        printf("%s\n", s);
    }
    return 0;
}
