#include <cstdio>

char s[1000];

int main()
{
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c))
    {
        s[0] = 0;
        sprintf(s + 1, "%d", a / b);
        int index;
        for (index = 1; s[index]; ++index);
        if (c != 0)
        {
            s[index++] = '.';
            a %= b;
            for (int i = 0; i <= c; ++i)
            {
                a *= 10;
                s[index++] = a / b + '0';
                a %= b;
            }
            if (s[index - 1] >= '5')
            {
                for (int i = index - 2; i >= 0; --i)
                {
                    if (s[i] == '.')
                    {
                        continue;
                    }
                    if (++s[i] > '9')
                    {
                        s[i] -= 10;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            s[--index] = 0;
        }
        if (s[0] != 0)
        {
            s[0] = '1';
            printf("%s\n", s);
        }
        else
        {
            printf("%s\n", s + 1);
        }
    }
    return 0;
}
