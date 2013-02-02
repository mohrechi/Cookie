#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 100010;

int ans[MAXN];

int main()
{
    int n, caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%d", &n);
        printf("Case #%d: %d\n", cas, n - (int)sqrt(n + 0.5));
        int c = (int)sqrt(n + 0.5);
        for(int i=1;i<=n;++i)
        {
            ans[i] = i;
        }
        int index = 1;
        for(int i=c-1; i<=c;++i)
        {
            for(int j=1;j<=i;++j)
            {
                reverse(ans + index, ans + index + j);
                index += j;
            }
        }
        for(int i=1;i<n;++i)
        {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[n]);
    }
    return 0;
}
