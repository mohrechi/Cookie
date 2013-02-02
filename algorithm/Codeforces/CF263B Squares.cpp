#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 55;

int a[MAXN];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0;i<n;++i)
    {
        scanf("%d", &a[i]);
    }
    if(k > n)
    {
        printf("-1\n");
    }
    else
    {
        sort(a, a + n);
        printf("%d %d\n", a[n - k], a[n - k]);
    }
    return 0;
}
