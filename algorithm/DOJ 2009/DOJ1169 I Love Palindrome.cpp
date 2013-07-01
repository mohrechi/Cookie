#include <cstdio>
#include <cstring>

char s[1005];
int ans[1005][1005];

inline int min(int x, int y)
{
    return x<y?x:y;
}

int main()
{
    int t, n, i, j;
    scanf("%d\n",&t);
    for(int k=1;k<=t;++k)
    {
        memset(ans, 0, sizeof(ans));
        scanf("%s", s);
        n = strlen(s);
        for (i = n - 1; i >= 0; --i)
        {
            for (j = i; j < n; ++j)
            {
                if (s[i] == s[j]) ans[i][j] = ans[i + 1][j - 1];
                else ans[i][j] = 1 + min(ans[i+1][j-1], min(ans[i][j - 1], ans[i + 1][j]));
            }
        }
        printf("Case #%d: %d\n", k, ans[0][n - 1]);
    }
    return 0;
}
