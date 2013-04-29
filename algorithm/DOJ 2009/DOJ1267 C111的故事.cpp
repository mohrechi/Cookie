#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int sum[MAXN];

int main()
{
    int n, m, q, a;
    while(~scanf("%d%d", &m, &n))
    {
        memset(sum, 0, sizeof(sum));
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a);
            ++ sum[a];
        }
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d", &a);
            printf("%d\n", sum[a]);
        }
    }
    return 0;
}
