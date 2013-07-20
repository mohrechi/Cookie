#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 6;

int n;
int set[MAXN * 4], setNum;
map<int, int> index;
bool visit[MAXN * 2][MAXN * 2];

struct Point
{
    int x, y;
    inline void input()
    {
        scanf("%d%d", &x, &y);
    }
    bool operator <(const Point &point) const
    {
        if (y == point.y)
        {
            return x < point.x;
        }
        return y < point.y;
    }
    inline void transfer()
    {
        x = index[x];
        y = index[y];
    }
} point1[MAXN], point2[MAXN], point[MAXN * 2];

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            point1[i].input();
            point2[i].input();
            point[i] = point1[i];
            point[i + n] = point2[i];
        }
        sort(point, point + n + n);
        bool flag = true;
        if (point[n + n - 1].x - point[0].x != point[n + n - 1].y - point[0].y)
        {
            flag = false;
        }
        else
        {
            setNum = 0;
            for (int i = 0; i < n + n; ++i)
            {
                set[setNum++] = point[i].x;
                set[setNum++] = point[i].y;
            }
            sort(set, set + setNum);
            int len = 1;
            for (int i = 1; i < setNum; ++i)
            {
                if (set[i] != set[i - 1])
                {
                    set[len++] = set[i];
                }
            }
            setNum = len;
            for (int i = 1; i < setNum; ++i)
            {
                index[set[i]] = i;
            }
            memset(visit, false, sizeof(visit));
            for (int k = 0; k < n; ++k)
            {
                point1[k].transfer();
                point2[k].transfer();
                for (int i = point1[k].x; i < point2[k].x; ++i)
                {
                    for (int j = point1[k].y; j < point2[k].y; ++j)
                    {
                        visit[i][j] = true;
                    }
                }
            }
            point[0].transfer();
            point[n + n - 1].transfer();
            for (int i = point[0].x; i < point[n + n - 1].x && flag; ++i)
            {
                for (int j = point[0].y; j < point[n + n - 1].y && flag; ++j)
                {
                    if (!visit[i][j])
                    {
                        flag = false;
                    }
                }
            }
        }
        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
