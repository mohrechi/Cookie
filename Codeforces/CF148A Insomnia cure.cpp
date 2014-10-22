#include <cstdio>
#include <cstring>

bool visit[100001];

int main()
{
    int n, a[4];
    scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &n);
    for(int i=0;i<4;++i)
    {
        for(int j=a[i];j<=n;j+=a[i])
        {
            visit[j] = true;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;++i)
    {
        ans += visit[i];
    }
    printf("%d\n", ans);
    return 0;
}
