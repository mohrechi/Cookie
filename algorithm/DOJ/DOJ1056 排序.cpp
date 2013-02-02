#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;

int a[MAXN];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for(int i=0;i<n;++i)
        {
            if(i)
            {
                printf(" ");
            }
            printf("%d", a[i]);
        }
        printf("\n");
    }
    return 0;
}
