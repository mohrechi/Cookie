#include <cstdio>

void solve(int n, int m, int p)
{
    if (n > (m << 1) + 1)
    {
        int t = n - (m << 1);
        if ((t & (t - 1)) == 0)
        {
            puts("0");
        }
        else
        {
            int i = 0;
            while (t)
            {
                t >>= 1;
                ++i;
            }
            if((1 << (i - 1)) + (m << 1) < p)
            {
                puts("Thrown");
            }
            else
            {
                puts("0");
            }
        }
    }
    else if (n == (m << 1) + 1)
    {
        if ((p & 1) && p != n)
        {
            puts("1");
        }
        else
        {
            puts("0");
        }
    }
    else
    {
        if (n == 1)
        {
            printf("%d\n",m);
        }
        else if (n == 2)
        {
            printf("%d\n", p == 1 ? 0 : m);
        }
        else if (n & 1)
        {
            if (p == n)
            {
                printf("%d\n",m - ((n - 1) >> 1));
            }
            else
            {
                printf("%d\n", p & 1 ? 1 : 0);
            }
        }
        else
        {
            if (p == n)
            {
                printf("%d\n",m - ((n - 2) >> 1));
            }
            else
            {
                printf("%d\n", p & 1 ? 0 : 1);
            }
        }
    }
}

int main()
{
    int T, n, m, p;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &p);
        solve(n, m, p);
    }
    return 0;
}
