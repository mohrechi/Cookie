#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXM = 100005;
const int MAXN = 105;

int a[MAXM], num[MAXN];

int main()
{
    int t, n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &m, &n);
        int ans = m;
        int l = 0;
        memset(num, 0, sizeof(num));
        int count = 0;
        for(int i=0;i<m;++i)
        {
            scanf("%d", &a[i]);
            if(num[a[i]] == 0)
            {
                ++ count;
            }
            ++ num[a[i]];
            while(count == n)
            {
                ans = min(ans, i - l + 1);
                if(num[a[l]] == 1)
                {
                    -- count;
                }
                -- num[a[l]];
                ++ l;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
