#include <cstdio>
#include <cstring>
const int MAXN = 1000 + 10;

int main()
{
    int t, l, n0, n1, m;
    char s[MAXN];
    bool ans[4];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s);
        n0 = n1 = m = 0;
        for (l = 0; s[l]; ++l)
        {
            if (s[l] == '0')
            {
                ++n0;
            }
            else if (s[l] == '1')
            {
                ++n1;
            }
            else
            {
                ++m;
            }
        }
        memset(ans, false, sizeof(ans));
        for (int i = 0; i <= m; ++i)
        {
            if (n0 + i > n1 + (m - i))
            {
                ans[0] = true;
            }
            else if (n1 + (m - i) > n0 + i + 1)
            {
                ans[3] = true;
            }
            else
            {
                if (s[l - 1] == '0')
                {
                    ans[2] = true;
                }
                else if (s[l - 1] == '1')
                {
                    ans[1] = true;
                }
                else
                {
                    if (i < m)
                    {
                        ans[1] = true;
                    }
                    if (i > 0)
                    {
                        ans[2] = true;
                    }
                }
            }
        }
        for (int i = 0; i < 4; ++i)
        {
            if (ans[i])
            {
                printf("%d%d\n", (i & 2) >> 1, i & 1);
            }
        }
        puts("");
    }
    return 0;
}
