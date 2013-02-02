#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 101;

int n;
int a[MAXN];

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
        sort(a, a + n);
        sum >>= 1;
        int cnt = 0;
        int take = 0;
        for(int i=n-1;i>=0;--i)
        {
            take += a[i];
            ++ cnt;
            if(take > sum)
            {
                break;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
