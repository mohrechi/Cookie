#include <cstdio>
#include <cstring>

int pn[60][60000];

int getPN(int a, int b)
{
    if (pn[a][b] != -1) return pn[a][b];
    if (b == 1) return pn[a][b] = getPN(a + 1, 0);
    if (a >= 1)
    {
        if (!getPN(a - 1, b)) return pn[a][b] = true;
        if (b > 0 && !getPN(a - 1, b + 1)) return pn[a][b] = true;
    }
    if (a >= 2)
    {
        if (b > 0 && !getPN(a - 2, b + 3)) return pn[a][b] = true;
        if (b == 0 && !getPN(a - 2, 2)) return pn[a][b] = true;
    }
    if (b >= 2 && !getPN(a, b - 1)) return pn[a][b] = true;
    return pn[a][b] = false;
}

int main()
{
    int T, n, c;
    memset(pn, -1, sizeof(pn));
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int a = 0, b = 0;
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d", &c);
            a += c == 1;
            b += c == 1 ? 0 : c + 1;
        }
        b -= b > 0;
        printf("Case #%d: %s\n", t, getPN(a, b) ? "Alice" : "Bob");
    }
    return 0;
}
