#include <cstdio>
#include <cstring>

const int MAXN = 100005;

int n, k, a[MAXN];
int b[MAXN];

int main()
{
    while(~scanf("%d%d", &n, &k))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
        }
        memset(b, 0, sizeof(b));
        int last = a[0], pos = 0;
        for(int i=1;i<n;++i)
        {
            if(a[i] != a[i-1])
            {
                if(pos != 0)
                {
                    if(a[pos-1] == a[i])
                    {
                        b[last] += 2;
                    }
                    else
                    {
                        b[last] += 1;
                    }
                }
                else
                {
                    ++ b[last];
                }
                last = a[i];
                pos = i;
            }
        }
        ++ b[a[n-1]];
        int ans = 1;
        for(int i=2;i<=k;++i)
        {
            if(b[i] > b[ans])
            {
                ans = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
