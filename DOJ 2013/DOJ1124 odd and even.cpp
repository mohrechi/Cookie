#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, a;
    while (~scanf("%d%d", &n, &m), n || m)
    {
        map<int, int> cnt;
        if (m != 0)
        {
            m = 1;
        }
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            if ((a & 1) == m)
            {
                ++cnt[a];
            }
        }
        if (cnt.begin() == cnt.end())
        {
            puts("no such number!");
        }
        else
        {
            for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); ++it)
            {
                printf("%d %d\n", it->first, it->second);
            }
        }
        putchar('\n');
    }
    return 0;
}
