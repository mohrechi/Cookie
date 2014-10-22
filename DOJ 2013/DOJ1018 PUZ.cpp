#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, v;
    while (~scanf("%d%d%d", &a, &b, &v))
    {
        int ans = (v - a - 1) / (a - b);
        v -= ans * (a - b);
        while (v > 0)
        {
            ++ans;
            v -= a;
            if (v <= 0)
            {
                break;
            }
            v += b;
        }
        printf("%d\n", ans);
    }
    return 0;
}
