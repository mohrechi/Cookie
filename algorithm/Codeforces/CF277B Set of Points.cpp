#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    while(~scanf("%d%d",&n,&m))
    {
        if(m == 3 && n > 4)
        {
            printf("-1\n");
        }
        else
        {
            for(int i = 0; i < m; ++ i)
            {
                printf("%d %d\n", i, 1000000 + i * i);
            }
            n -= m;
            for(int i = 0; i < n; ++ i)
            {
                printf("%d %d\n", i, - 1000000 - i * i);
            }
        }
    }
    return 0;
}
