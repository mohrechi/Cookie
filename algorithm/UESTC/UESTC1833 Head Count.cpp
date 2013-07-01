#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;

struct Change
{
    int time, num;
    bool isIn;
    bool operator <(const Change &change) const
    {
        if (time == change.time)
        {
            return  change.isIn < isIn;
        }
        return time < change.time;
    }
} change[MAXN * 2];

int main()
{
    int T, n;
    int u, v, w;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            change[i].time = u;
            change[i].num = w;
            change[i].isIn = true;
            change[i + n].time = v;
            change[i + n].num = w;
            change[i + n].isIn = false;
        }
        n <<= 1;
        sort(change, change + n);
        int ans = 0;
        int num = 0;
        for (int i = 0; i < n; ++i)
        {
            if (change[i].isIn)
            {
                num += change[i].num;
                ans = max(ans, num);
            }
            else
            {
                num -= change[i].num;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
