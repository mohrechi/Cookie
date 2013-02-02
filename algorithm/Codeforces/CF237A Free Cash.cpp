#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int h[2], m[2], cnt = 1, ans = 1;
        scanf("%d%d", &h[0], &m[0]);
        for(int i=1;i<n;++i)
        {
            int now = i & 1;
            int pre = 1 - now;
            scanf("%d%d", &h[now], &m[now]);
            if(h[now] == h[pre] && m[now] == m[pre])
            {
                ++ cnt;
                ans = max(ans, cnt);
            }
            else
            {
                cnt = 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
