#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, cap, a, b, num;
    while(~scanf("%d", &n))
    {
        cap = num = 0;
        while(n--)
        {
            scanf("%d%d", &a, &b);
            num += b - a;
            cap = max(cap, num);
        }
        printf("%d\n", cap);
    }
    return 0;
}
