#include <cstdio>
#include <cstring>
const int MAXN = 35;

int n, a[MAXN][MAXN];
int rsum[MAXN], csum[MAXN], ans;

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d", &a[i][j]);
            }
        }
        memset(rsum, 0, sizeof(rsum));
        memset(csum, 0, sizeof(csum));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                rsum[i] += a[i][j];
                csum[j] += a[i][j];
            }
        }
        ans = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                ans += csum[i] > rsum[j];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
