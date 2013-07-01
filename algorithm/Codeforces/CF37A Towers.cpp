#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int n, a[MAXN];

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int height = 1, number = 1;
        int count = 1;
        for(int i=1;i<n;++i)
        {
            if(a[i] == a[i - 1])
            {
                ++ count;
                height = max(height, count);
            }
            else
            {
                count = 1;
                ++ number;
            }
        }
        printf("%d %d\n", height, number);
    }
    return 0;
}
