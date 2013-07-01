#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 205;

struct Set
{
    __int64 data[MAXN * MAXN];
    int dataNumber;

    inline void clear()
    {
        dataNumber = 0;
    }

    inline void insert(const __int64 &x)
    {
        data[dataNumber++] = x;
    }

    inline void simplify()
    {
        sort(data, data + dataNumber);
        int k = 1;
        for(int i=1;i<dataNumber;++i)
        {
            if(data[i] != data[i-1])
            {
                data[k++] = data[i];
            }
        }
        dataNumber = k;
    }
}set[2];

__int64 a[5][MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for(int i=0;i<5;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%I64d", &a[i][j]);
            }
        }
        set[0].clear();
        set[1].clear();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                set[0].insert(a[0][i] + a[1][j]);
                set[1].insert(a[2][i] + a[3][j]);
            }
        }
        set[0].simplify();
        set[1].simplify();
        bool flag = false;
        for(int k=0;k<n && !flag;++k)
        {
            int i = 0;
            int j = set[1].dataNumber - 1;
            while(i < set[0].dataNumber && j >= 0)
            {
                if(set[0].data[i] + set[1].data[j] + a[4][k] == 0)
                {
                    flag = true;
                    break;
                }
                else if(set[0].data[i] + set[1].data[j] + a[4][k] > 0)
                {
                    -- j;
                }
                else
                {
                    ++ i;
                }
            }
        }
        if(flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
