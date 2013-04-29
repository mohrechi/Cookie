#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int n, a[MAXN];

int main()
{
    while(~scanf("%d", &n))
    {
        int sum = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        sort(a, a + n);
        int ans = sum + 1;
        sum = 0;
        for(int i=0;i<n;++i)
        {
            if(a[i] > sum + 1)
            {
                ans = min(ans, sum + 1);
                break;
            }
            sum += a[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
