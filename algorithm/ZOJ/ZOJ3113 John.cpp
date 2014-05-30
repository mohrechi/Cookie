#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int a, cnt = 0, sg = 0;
        while (n--)
        {
            scanf("%d", &a);
            cnt += a > 1;
            sg ^= a;
        }
        if (sg > 0 == cnt > 0)
        {
            puts("John");
        }
        else
        {
            puts("Brother");
        }
    }
    return 0;
}
