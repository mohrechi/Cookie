#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 40 * 1000 + 10;

int q, n;
int a[50], b[50], aNum, bNum;
bool va[MAXN], vb[MAXN];

int main()
{
    int t;
    scanf("%d", &q);
    while (q--)
    {
        bool flag = false;
        scanf("%d", &n);
        aNum = bNum = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &t);
            if (t > 0)
            {
                a[aNum++] = t;
            }
            else if (t < 0)
            {
                b[bNum++] = -t;
            }
            else
            {
                flag = true;
            }
        }
        memset(va, false, sizeof(va));
        memset(vb, false, sizeof(vb));
        va[0] = vb[0] = true;
        for (int i = 0; i < aNum; ++i)
        {
            for (int j = MAXN - 1; j >= 0; --j)
            {
                if (va[j] && j + a[i] < MAXN)
                {
                    va[j + a[i]] = true;
                }
            }
        }
        for (int i = 0; i < bNum; ++i)
        {
            for (int j = MAXN - 1; j >= 0; --j)
            {
                if (vb[j] && j + b[i] < MAXN)
                {
                    vb[j + b[i]] = true;
                }
            }
        }
        for (int i = 1; i < MAXN; ++i)
        {
            if (va[i] & vb[i])
            {
                flag = true;
            }
        }
        if (flag)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}
