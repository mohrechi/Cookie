#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int T, n, a;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        int sg = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a);
            if (i % 6 == 0 || i % 6 == 2 || i % 6 == 5)
            {
                sg ^= a;
            }
        }
        printf("Case %d: ", t);
        if (sg)
        {
            puts("Alice");
        }
        else
        {
            puts("Bob");
        }
    }
    return 0;
}
