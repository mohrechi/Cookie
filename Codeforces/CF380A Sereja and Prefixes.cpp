#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXL = 1e5;

int m, n;
long long a[MAXL + 10];
struct Operation
{
    int type;
    long long x, l, c;
    inline int input()
    {
        scanf("%d", &type);
        if (1 == type)
        {
            scanf("%I64d", &x);
        }
        else
        {
            scanf("%I64d%I64d", &l, &c);
        }
    }
}operation[MAXL];
long long q[MAXL];

int main()
{
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        operation[i].input();
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%I64d", &q[i]);
    }
    long long pos = 0;
    for (int i = 0, j = 0; i < n; ++i)
    {
        while (q[i] > pos)
        {
            if (1 == operation[j].type)
            {
                if (q[i] == pos + 1)
                {
                    printf("%I64d ", operation[j].x);
                }
                if (++pos <= MAXL)
                {
                    a[pos] = operation[j].x;
                }
            }
            else
            {
                while (i < n && pos + operation[j].c * operation[j].l >= q[i])
                {
                    q[i] -= pos + 1;
                    q[i] %= operation[j].l;
                    printf("%I64d ", a[q[i] + 1]);
                    ++i;
                }
                bool flag = true;
                long long t = pos;
                for (int k = 0; k < operation[j].c && flag; ++k)
                {
                    for (int l = 1; l <= operation[j].l && flag; ++l)
                    {
                        if (++t > MAXL)
                        {
                            flag = false;
                            break;
                        }
                        a[t] = a[l];
                    }
                }
                pos += operation[j].c * operation[j].l;
            }
            ++j;
        }
    }
    return 0;
}
