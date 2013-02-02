#include <cstdio>
#include <cstring>
const int MAXN = 100005;

int n, a;
int count[5];

int main()
{
    while(~scanf("%d", &n))
    {
        memset(count, 0, sizeof(count));
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a);
            ++ count[a];
        }
        int ans = count[4] + count[3] + (count[2] >> 1);
        if(count[3] <= count[1])
        {
            count[1] -= count[3];
        }
        else
        {
            count[1] = 0;
        }
        if(count[2] & 1)
        {
            ++ ans;
            count[1] -= 2;
        }
        if(count[1] > 0)
        {
            ans += (count[1] + 3) / 4;
        }
        printf("%d\n", ans);
    }
    return 0;
}
