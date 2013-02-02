#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 55;

int n, k;
int a[MAXN];

int main()
{
    while(~scanf("%d%d", &n, &k))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &a[i]);
        }
        int cnt = 0;
        for(int i=1;i<=n;++i)
        {
            if(a[i] > 0 && a[i] >= a[k])
            {
                ++ cnt;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
