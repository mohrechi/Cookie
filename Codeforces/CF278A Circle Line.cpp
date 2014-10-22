#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, d[105];

int main()
{
    int s, t;
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &d[i]);
        }
        scanf("%d%d", &s, &t);
        int d1 = 0, d2 = 0;
        if(s != t)
        {
            int i = s;
            while(true)
            {
                -- i;
                if(0 == i)
                {
                    i = n;
                }
                d1 += d[i];
                if(i == t)
                {
                    break;
                }
            }
            i = s;
            while(true)
            {
                d2 += d[i];
                if(++ i > n)
                {
                    i = 1;
                }
                if(i == t)
                {
                    break;
                }
            }
        }
        printf("%d\n", min(d1, d2));
    }
    return 0;
}
