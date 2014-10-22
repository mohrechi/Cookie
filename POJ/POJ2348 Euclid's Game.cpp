#include <cstdio>

int n(int a, int b)
{
    if (a < b) return n(b, a);
    if (a % b == 0 || a / b > 1) return true;
    return !n(b, a - b);
}

int main()
{
    int a, b;
    while (scanf("%d%d", &a, &b), a || b)
    {
        puts(n(a, b) ? "Stan wins" : "Ollie wins");
    }
    return 0;
}
