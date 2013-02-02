#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 11;
const int MAXM = 21;
const int INF = 0x7FFFFFFF;

int h, w, n, ans;
struct Point
{
    int x, y;
    inline void input()
    {
        scanf("%d%d", &x, &y);
    }
} start, beeper[MAXN];
bool visit[MAXN];

inline int dist(const Point &a, const Point &b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void dfs(Point pos, int depth, int length)
{
    if(length > ans)
    {
        return;
    }
    if(depth == n)
    {
        length += dist(start, pos);
        ans = min(ans, length);
        return;
    }
    for(int i=0;i<n;++i)
    {
        if(!visit[i])
        {
            visit[i] = true;
            dfs(beeper[i], depth + 1, length + dist(pos, beeper[i]));
            visit[i] = false;
        }
    }
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    while(caseNumber--)
    {
        scanf("%d%d", &w, &h);
        start.input();
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            beeper[i].input();
        }
        ans = INF;
        memset(visit, false, sizeof(visit));
        dfs(start, 0, 0);
        printf("The shortest path has length %d\n", ans);
    }
    return 0;
}
