#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, pn[40][9000];
int s, m[40];

int getPN(int pos, int num)
{
    if (num <= 0)
    {
        return true;
    }
    if (pn[pos][num] != -1)
    {
        return pn[pos][num];
    }
    for (int i = 1; i <= m[pos]; ++i)
    {
        if (!getPN((pos + 1) % n, num - i))
        {
            return pn[pos][num] = true;
        }
    }
    return pn[pos][num] = false;
}

int main()
{
    while (scanf("%d", &n), n)
    {
        memset(pn, -1, sizeof(pn));
        scanf("%d", &s);
        n <<= 1;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &m[i]);
        }
        printf("%d\n", getPN(0, s));
    }
    return 0;
}
