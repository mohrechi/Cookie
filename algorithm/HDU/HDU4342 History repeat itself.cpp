#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50000;
__int64 square[MAXN];

void init()
{
    for(__int64 i=0;i<MAXN;++i)
    {
        square[i] = i * i;
    }
}

int main()
{
    init();
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int up;
        for(int i=0;i<MAXN;++i)
        {
            if(n < square[i])
            {
                up = i;
                break;
            }
        }
        int m = n + up - 1;
        if(square[up] <= m)
        {
            ++ m;
        }
        __int64 c = 0;
        if(m <= 3)
        {
            c = m;
        }
        else
        {
            for(int i=2;i<MAXN;++i)
            {
                if(m >= square[i])
                {
                    c += (square[i] - square[i-1]) * (__int64)(i-1);
                }
                else
                {
                    up = i - 1;
                    break;
                }
            }
            c += (m - square[up] + 1) * up;
        }
        printf("%d %I64d\n", m, c);
    }
    return 0;
}
