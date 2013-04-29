#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, a[500];
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        printf("%d\n", a[n >> 1]);
    }
    return 0;
}
