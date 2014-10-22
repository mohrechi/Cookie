#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = (1 << 21) + 10;

int pn[MAXN];

int getNext(int n, int i)
{
    int next = n;
    for (int j = i; j <= 20; j += i)
    {
        next &= ~(1 << j);
        for (int k = 2; k <= 20; ++k)
        {
            if (j + k <= 20 && !(n & (1 << k)))
            {
                next &= ~(1 << (j + k));
            }
        }
    }
    return next;
}

int getPN(int n)
{
    if (pn[n] != -1)
    {
        return pn[n];
    }
    for (int i = 2; i <= 20; ++i)
    {
        if (n & (1 << i))
        {
            if (!getPN(getNext(n, i)))
            {
                return pn[n] = true;
            }
        }
    }
    return pn[n] = false;
}

int main()
{
    int T, n, a;
    memset(pn, -1, sizeof(pn));
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int state = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            state |= 1 << a;
        }
        printf("Scenario #%d:\n", t);
        if (getPN(state))
        {
            printf("The winning moves are:");
            for (int i = 2; i <= 20; ++i)
            {
                if (state & (1 << i))
                {
                    if (!getPN(getNext(state, i)))
                    {
                        printf(" %d", i);
                    }
                }
            }
            puts(".");
        }
        else
        {
            puts("There is no winning move.");
        }
        putchar('\n');
    }
    return 0;
}
