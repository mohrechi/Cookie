#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
static const int MAXN = 50005;
struct Point
{
    int x, y;
    bool operator < (const Point &p) const
    {
        if(x == p.x)
        {
            return y < p.y;
        }
        return x < p.x;
    }
}point[MAXN];

int main(int argc, char *argv[])
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&point[i].x,&point[i].y);
        }
        sort(point, point + n);
        int ans = 1, m = point[n-1].y;
        for(int i=n-2;i>=0;--i)
        {
            if(m < point[i].y)
            {
                m = point[i].y;
                ++ ans;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
