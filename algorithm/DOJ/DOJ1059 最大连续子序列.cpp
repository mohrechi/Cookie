#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000001;

int main()
{
    int t, n, a;
    scanf("%d", &t);
    while(t--)
    {
        int ans = 0;
        int sum = 0;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &a);
            sum = a + max(0, sum);
            ans = max(ans, sum);
        }
        printf("%d\n", ans);
    }
    return 0;
}
