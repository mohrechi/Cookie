#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

bool able[2][MAXN][MAXN];
int num[2][MAXN];

int main()
{
    int n, m, k, p, a, b;
    char s[2][16];
    while(scanf("%d%d%d", &n, &m, &k), n || m || k)
    {
        memset(able, true, sizeof(able));
        for(int i=1;i<=m;++i)
        {
            num[0][i] = n;
            num[1][i] = k;
        }
        scanf("%d", &p);
        while(p--)
        {
            scanf("%s%d%s%d", s[0], &a, s[1], &b);
            if('c' == s[0][0])
            {
                if(able[0][a][b])
                {
                    able[0][a][b] = false;
                    -- num[0][b];
                }
            }
            else
            {
                if(able[1][a][b])
                {
                    able[1][a][b] = false;
                    -- num[1][a];
                }
            }
        }
        long long ans = 0;
        for(int i=1;i<=m;++i)
        {
            ans += num[0][i] * num[1][i];
        }
        cout << ans << endl;
    }
    return 0;
}
