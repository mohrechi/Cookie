#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;

int pn[MAXN][MAXN];

int getPN(int a, int b)
{
    if (a < b)
    {
        return getPN(b, a);
    }
    if (pn[a][b] != -1)
    {
        return pn[a][b];
    }
    if (b == 0)
    {
        return pn[a][b] = false;
    }
    for (int i = b; i <= a; i += b)
    {
        if (!getPN(a - i, b))
        {
            return pn[a][b] = true;
        }
    }
    return pn[a][b] = false;
}

int main()
{
    int a, b;
    memset(pn, -1, sizeof(pn));
    while (scanf("%d%d", &a, &b), a || b)
    {
        puts(getPN(a, b) ? "newSolar wins" : "Kousaka kirino wins");
    }
    return 0;
}
