#include <cstdio>
#include <cstring>

int main()
{
    int T;
    char s[105];
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        int len = strlen(s);
        for (int i = len - 1; i >= 0; --i)
        {
            putchar(s[i]);
        }
        putchar('\n');
    }
    return 0;
}
