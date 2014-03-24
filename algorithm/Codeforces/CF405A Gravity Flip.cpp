#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;


int main()
{
    int n, a[MAXN];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        if (i)
        {
            putchar(' ');
        }
        printf("%d", a[i]);
    }
    putchar('\n');
    return 0;
}
