#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int k, a[12];
    while(~scanf("%d", &k))
    {
        for(int i=0;i<12;++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + 12);
        int ans = 0;
        int i = 11;
        while(k > 0 && i >= 0)
        {
            ++ ans;
            k -= a[i--];
        }
        if(k > 0)
        {
            ans = -1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
