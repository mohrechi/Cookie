#include <cstdio>
const int MAXN = 300 + 10;

int n;
char s[MAXN][MAXN];

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s[i]);
        }
        bool flag = s[0][0] != s[0][1];
        for (int i = 0; i < n && flag; ++i)
        {
            for (int j = 0; j < n && flag; ++j)
            {
                if (i == j || n - i - 1 == j)
                {
                    flag &= s[i][j] == s[0][0];
                }
                else
                {
                    flag &= s[i][j] == s[0][1];
                }
            }
        }
        puts(flag ? "YES" : "NO");
    }
}
