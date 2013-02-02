#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int MAXM = 1005;

struct Point
{
    __int64 x, y;
    inline void input()
    {
        scanf("%I64d%I64d", &x, &y);
    }
}house[MAXN], gold[MAXM], center;

int n, m;
int cnt[MAXN][MAXN];

inline int dblcmp(__int64 x)
{
    if(x == 0)
    {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

inline int cross(const Point &a, const Point &b, const Point &o)
{
    return dblcmp((a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x));
}

int main()
{
    int cas = 0;
    center.x = 0.0;
    center.y = 0.0;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=0;i<n;++i)
        {
            house[i].input();
        }
        for(int i=0;i<m;++i)
        {
            gold[i].input();
        }
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                cnt[i][j] = 0;
                int t = cross(center, house[j], house[i]);
                int t1, t2, t3;
                for(int k=0;k<m;++k)
                {
                    t1 = cross(gold[k], house[i], center);
                    t2 = cross(gold[k], house[j], house[i]);
                    t3 =  cross(gold[k], center, house[j]);
                    if(t1 == 0 && t2 * t3 >= 0)
                    {
                        ++ cnt[i][j];
                    }
                    else if(t1 * t2 >= 0 && t3 == 0)
                    {
                        ++ cnt[i][j];
                    }
                    else if(t1 == t2 && t2 == t3)
                    {
                        cnt[i][j] += 2;
                    }
                }
                if(cross(center, house[j], house[i]) > 0)
                {
                    cnt[j][i] = - cnt[i][j];
                }
                else
                {
                    cnt[j][i] = cnt[i][j];
                    cnt[i][j] = - cnt[i][j];
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                for(int k=j+1;k<n;++k)
                {
                    if((cnt[i][j] + cnt[j][k] + cnt[k][i]) & 2)
                    {
                        ++ ans;
                    }
                }
            }
        }
        printf("Case %d: %d\n", ++cas, ans);
    }
    return 0;
}
