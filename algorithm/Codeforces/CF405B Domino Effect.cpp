#include <cstdio>

int main()
{
    int n, ans = 0, cnt = 0;
    char ch;
    bool isRight = false;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i)
    {
        ch = getchar();
        ++cnt;
        if ('L' == ch)
        {
            if (isRight)
            {
                ans += (cnt - 1) & 1;
            }
            cnt = 0;
            isRight = false;
        }
        else if ('R' == ch)
        {
            if (!isRight)
            {
                ans += cnt - 1;
            }
            cnt = 0;
            isRight = true;
        }
    }
    if (!isRight)
    {
        ans += cnt;
    }
    printf("%d\n", ans);
    return 0;
}
