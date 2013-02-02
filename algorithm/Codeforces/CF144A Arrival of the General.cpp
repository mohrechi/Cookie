#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 105;

int n, a[MAXN];

int main()
{
    while(~scanf("%d", &n))
    {
        int fv = 0, fp;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
            if(a[i] > fv)
            {
                fv = a[i];
                fp = i;
            }
        }
        int bv = MAXN, bp;
        for(int i=n-1;i>=0;--i)
        {
            if(a[i] < bv)
            {
                bv = a[i];
                bp = i;
            }
        }
        int ans = fp + n - bp - 1;
        if(fp > bp)
        {
            -- ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
