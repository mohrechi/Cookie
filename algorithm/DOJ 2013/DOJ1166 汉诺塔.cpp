#include <cstdio>

void output(char x, char y)
{
    printf("%c ----> %c\n", x, y);
}

void move(int n, char a, char b, char c)
{
    if (n == 1)
    {
        output(a, c);
    }
    else
    {
        move(n - 1, a, c, b);
        output(a, c);
        move(n - 1, b, a, c);
    }
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        move(n, 'A', 'B', 'C');
        putchar('\n');
    }
    return 0;
}
