#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 35;

int n, host[MAXN], guest[MAXN];

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &host[i], &guest[i]);
        }
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i == j)
                {
                    continue;
                }
                if(host[i] == guest[j])
                {
                    ++ ans;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
