#include <cstdio>

int main()
{
    char s[1024];
    while (gets(s))
    {
        for (int i = 0; s[i]; i += 8)
        {
            int ch = 0;
            for (int j = 0; j < 8; ++j)
            {
                ch = (ch << 1) + (s[i + j] == '\t');
            }
            putchar(ch);
        }
        putchar('\n');
    }
    return 0;
}
