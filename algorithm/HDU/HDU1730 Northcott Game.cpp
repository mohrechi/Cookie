#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, t, j;
    while (~scanf("%d%d", &n, &m))
    {
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &t, &j);
            ans ^= abs(t - j) - 1;
        }
        puts(ans ? "I WIN!" : "BAD LUCK!");
    }
    return 0;
}
