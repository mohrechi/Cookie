#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;

int a[MAXN];

int main()
{
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        printf("%d\n", a[n - k]);
    }
    return 0;
}
