#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int getJoy(int k, int f, int t)
{
    if(t <= k)
    {
        return f;
    }
    return f - (t - k);
}

int main()
{
    int n, k, f, t;
    while(~scanf("%d%d", &n, &k))
    {
        scanf("%d%d", &f, &t);
        int ans = getJoy(k, f, t);
        for(int i=1;i<n;++i)
        {
            scanf("%d%d", &f, &t);
            ans = max(ans, getJoy(k, f, t));
        }
        printf("%d\n", ans);
    }
    return 0;
}
