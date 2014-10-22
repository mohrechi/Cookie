#include <cstdio>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if (m < n - 1 || m > n * 2 + 2)
    {
        puts("-1");
    }
    else
    {
        int last = 1, cnt = 0;
        while (n || m)
        {
            if (last == 0 || (m > n && cnt < 2))
            {
                --m;
                ++cnt;
                last = 1;
                putchar('1');
            }
            else
            {
                --n;
                cnt = 0;
                last = 0;
                putchar('0');
            }
        }
    }
    return 0;
}
