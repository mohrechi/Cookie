#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int t, y, m, d;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &y, &m, &d);
        if (((m + d) & 1) == 0 || ((m == 9 || m == 11) && d == 30))
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}
