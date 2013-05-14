#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;

int n, a[MAXN];

int main()
{
    while(~scanf("%d", &n))
    {
        int sum = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        int ans = 0;
        if(sum & 1)
        {
            for(int i=0;i<n;++i)
            {
                if(a[i] & 1)
                {
                    ++ ans;
                }
            }
        }
        else
        {
            for(int i=0;i<n;++i)
            {
                if(!(a[i] & 1))
                {
                    ++ ans;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
