#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        bool existZero = false;
        int prev = 0;
        int count = 0;
        for(int i=0;(1LL<<i)<=n;++i)
        {
            if(n & (1LL << i))
            {
                if(prev == 0)
                {
                    ++ count;
                    prev = 1;
                }
            }
            else
            {
                existZero = true;
                prev = 0;
            }
        }
        if(existZero)
        {
            if(n & 1)
            {
                -- count;
            }
            printf("%d\n", count);
        }
        else
        {
            printf("%d\n", min(count, 1));
        }
    }
    return 0;
}
