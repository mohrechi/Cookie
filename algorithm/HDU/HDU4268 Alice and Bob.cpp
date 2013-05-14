#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int n;
struct Node
{
    int w, h;
    inline void input()
    {
        scanf("%d%d", &w, &h);
    }
    bool operator <(const Node &node) const
    {
        if (w == node.w)
        {
            return h < node.h;
        }
        return w < node.w;
    }
} a[MAXN], b[MAXN];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            a[i].input();
        }
        for (int i = 0; i < n; ++i)
        {
            b[i].input();
        }
        sort(a, a + n);
        sort(b, b + n);
        int ans = 0;
        multiset<int> s;
        for (int i = 0, j = 0; i < n; ++i)
        {
            while (j < n && b[j].w <= a[i].w)
            {
                s.insert(b[j].h);
                ++j;
            }
            if (s.size() == 0)
            {
                continue;
            }
            multiset<int>::iterator it = s.upper_bound(a[i].h);
            if (it != s.begin())
            {
                ++ans;
                --it;
                s.erase(it);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
