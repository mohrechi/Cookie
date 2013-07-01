#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int r, g, b;
    while (~scanf("%d%d%d", &r, &g, &b))
    {
        int ans = 0;
        for (int i = 0; i < 3; ++i)
        {
            if (r >= i && g >= i && b >= i)
            {
                ans = max(ans, i + (r - i) / 3 + (g - i) / 3 + (b - i) / 3);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
