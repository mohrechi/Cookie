#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
    int n, a;
    while(scanf("%d", &n), n)
    {
        int count = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a);
            count += a * a;
        }
        printf("%d\n", count);
    }
    return 0;
}
