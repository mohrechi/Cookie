#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int a[MAXN];
int b[MAXN];

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int count = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
            if(a[i] % 2 == 0)
            {
                b[count++] = a[i];
            }
        }
        sort(b, b + count);
        printf("%d\n", count);
        for(int i=0;i<count;++i)
        {
            if(i)
            {
                printf(" ");
            }
            printf("%d", b[i]);
        }
        printf("\n");
    }
    return 0;
}
