#include <cstdio>
#include <cstring>
const int MAXN = 1000 + 10;

int pn[MAXN];

int getPN(int n)
{
    if (pn[n] != -1)
    {
        return pn[n];
    }
    for (int i = 0; (1 << i) <= n; ++i)
    {
        if (!getPN(n - (1 << i)))
        {
            return pn[n] = true;
        }
    }
    return pn[n] = false;
}

int main()
{
    int n;
    memset(pn, -1, sizeof(pn));
    pn[0] = false;
    while (~scanf("%d", &n))
    {
        puts(getPN(n) ? "Kiki" : "Cici");
    }
    return 0;
}
