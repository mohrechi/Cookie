#include <cstdio>
#include <cstring>

int main()
{
    char ch;
    while (~(ch = getchar()))
    {
        if (ch >= 'A' && ch <= 'Z')
        {
            putchar((((ch - 'A') + 21) % 26) + 'A');
        }
        else
        {
            putchar(ch);
        }
    }
    return 0;
}
