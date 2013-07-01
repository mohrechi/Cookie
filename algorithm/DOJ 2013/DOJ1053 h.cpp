#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int SHIFT = 100000;
const int dirX[] = {0, 0, 1, -1};
const int dirY[] = {1, -1, 0, 0};

struct Point
{
    int x, y;
}point[MAXN];

int maxX[MAXN * 2], maxY[MAXN * 2];
int minX[MAXN * 2], minY[MAXN * 2];

inline int max(int x, int y)
{
    return x > y ? x : y;
}

inline int min(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0;i<=SHIFT * 2;++i)
        {
            maxX[i] = -MAXN;
            maxY[i] = -MAXN;
            minX[i] = MAXN;
            minY[i] = MAXN;
        }
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &point[i].x, &point[i].y);
            maxX[point[i].x + SHIFT] = max(maxX[point[i].x + SHIFT], point[i].y);
            maxY[point[i].y + SHIFT] = max(maxY[point[i].y + SHIFT], point[i].x);
            minX[point[i].x + SHIFT] = min(minX[point[i].x + SHIFT], point[i].y);
            minY[point[i].y + SHIFT] = min(minY[point[i].y + SHIFT], point[i].x);
        }
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            if(point[i].x > minY[point[i].y + SHIFT])
                if(point[i].x < maxY[point[i].y + SHIFT])
                    if(point[i].y > minX[point[i].x + SHIFT])
                        if(point[i].y < maxX[point[i].x + SHIFT])
                            ++ ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
