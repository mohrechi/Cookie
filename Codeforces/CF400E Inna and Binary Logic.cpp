#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXL = 18;

int n, m, a;
set<int> s[MAXL];

int main()
{
    int p, v;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < MAXL; ++i)
    {
        s[i].insert(0);
        s[i].insert(n + 1);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a);
        for (int j = 0; j < MAXL; ++j)
        {
            if (!(a & (1 << j)))
            {
                s[j].insert(i);
            }
        }
    }
    __int64 total = 0;
    for (int i = 0; i < MAXL; ++i)
    {
        int last = -1;
        for (auto it = s[i].begin(); it != s[i].end(); ++it)
        {
            __int64 d = *it - last - 1;
            total += ((d * (d + 1)) >> 1) << i;
            last = *it;
        }
    }
    while (m--)
    {
        scanf("%d%d", &p, &v);
        for (int i = 0; i < MAXL; ++i)
        {
            auto it = s[i].find(p);
            if (v & (1 << i))
            {
                if (it != s[i].end())
                {
                    --it;
                    __int64 a = *it;
                    ++++it;
                    __int64 b = *it;
                    --it;
                    total += ((p - a) * (b - p)) << i;
                    s[i].erase(it);
                }
            }
            else
            {
                if (it == s[i].end())
                {
                    it = s[i].upper_bound(p);
                    __int64 b = *it;
                    --it;
                    __int64 a = *it;
                    total -= ((p - a) * (b - p)) << i;
                    s[i].insert(p);
                }
            }
        }
        printf("%I64d\n", total);
    }
    return 0;
}
