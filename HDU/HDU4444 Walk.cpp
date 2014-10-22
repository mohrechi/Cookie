#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 70;
const int INF = 0x3f3f3f3f;
const int dirX[] = {1, 0, -1, 0};
const int dirY[] = {0, 1, 0, -1};

struct NumSet
{
    int num[MAXN * 2];
    int cnt;
    map<int, int> index;
    void init()
    {
        cnt = 0;
    }
    void insert(int x)
    {
        num[cnt++] = x;
    }
    void build()
    {
        int j = 1;
        sort(num, num + cnt);
        index.clear();
        index[num[0]] = 0;
        for (int i = 1; i < cnt; ++i)
        {
            if (num[i] != num[i - 1])
            {
                index[num[i]] = j;
                num[j++] = num[i];
            }
        }
        cnt = j;
    }
    int getIndex(int x)
    {
        return index[x];
    }
} xSet, ySet;

struct Rectangle
{
    int x1, y1, x2, y2;
    inline void input()
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (x1 > x2)
        {
            swap(x1, x2);
        }
        if (y1 > y2)
        {
            swap(y1, y2);
        }
    }
} rect[MAXN];

struct Point
{
    int x, y;
    inline int input()
    {
        return ~scanf("%d%d", &x, &y);
    }
} origin, target;

int n, m;
bool graph[MAXN * 4][MAXN * 4];
bool visit[MAXN * 4][MAXN * 4][4];
int dist[MAXN * 4][MAXN * 4][4];
int qx[MAXN * MAXN * 64];
int qy[MAXN * MAXN * 64];
int qd[MAXN * MAXN * 64];

inline void addToQueue(int &rear, int x, int y, int d)
{
    qx[rear] = x;
    qy[rear] = y;
    qd[rear++] = d;
}

inline void addToQueue(int &rear, int x, int y, int d, int newDist)
{
    if (dist[x][y][d] == -1 || dist[x][y][d] > newDist)
    {
        dist[x][y][d] = newDist;
        if (!visit[x][y][d])
        {
            visit[x][y][d] = true;
            addToQueue(rear, x, y, d);
            if (rear >= MAXN * MAXN * 64)
            {
                rear = 0;
            }
        }
    }
}

inline bool isValid(int x, int y)
{
    if (x < 0 || x >= n)
    {
        return false;
    }
    if (y < 0 || y >= m)
    {
        return false;
    }
    if (!graph[x][y])
    {
        return false;
    }
    return true;
}

void spfa()
{
    int front = 0, rear = 0;
    memset(visit, false, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < 4; ++i)
    {
        int x1 = origin.x * 2;
        int x2 = origin.x * 2 + 1;
        int y1 = origin.y * 2;
        int y2 = origin.y * 2 + 1;
        visit[x1][y1][i] = true;
        visit[x1][y2][i] = true;
        visit[x2][y1][i] = true;
        visit[x2][y2][i] = true;
        dist[x1][y1][i] = 0;
        dist[x1][y2][i] = 0;
        dist[x2][y1][i] = 0;
        dist[x2][y2][i] = 0;
        addToQueue(rear, x1, y1, i);
        addToQueue(rear, x1, y2, i);
        addToQueue(rear, x2, y1, i);
        addToQueue(rear, x2, y2, i);
    }
    while (front != rear)
    {
        int ux = qx[front];
        int uy = qy[front];
        int ud = qd[front];
        if (graph[ux][uy])
        {
            for (int i = 0; i < 4; ++i)
            {
                int tx = ux + dirX[i];
                int ty = uy + dirY[i];
                if (!isValid(tx, ty))
                {
                    continue;
                }
                int tdist = dist[ux][uy][ud] + (ud != i);
                addToQueue(rear, tx, ty, i, tdist);
            }
        }
        int sameX;
        if (ux & 1)
        {
            sameX = ux - 1;
        }
        else
        {
            sameX = ux + 1;
        }
        if (isValid(sameX, uy))
        {
            int tx, ty, tdist;
            tx = sameX;
            ty = uy + 1;
            tdist = dist[ux][uy][ud] + (ud != 1);
            if (isValid(tx, ty))
            {
                addToQueue(rear, tx, ty, 1, tdist);
            }
            tx = sameX;
            ty = uy - 1;
            tdist = dist[ux][uy][ud] + (ud != 3);
            if (isValid(tx, ty))
            {
                addToQueue(rear, tx, ty, 3, tdist);
            }
        }
        int sameY;
        if (uy & 1)
        {
            sameY = uy - 1;
        }
        else
        {
            sameY = uy + 1;
        }
        if (isValid(ux, sameY))
        {
            int tx, ty, tdist;
            tx = ux + 1;
            ty = sameY;
            tdist = dist[ux][uy][ud] + (ud != 0);
            if (isValid(tx, ty))
            {
                addToQueue(rear, tx, ty, 0, tdist);
            }
            tx = ux - 1;
            ty = sameY;
            tdist = dist[ux][uy][ud] + (ud != 2);
            if (isValid(tx, ty))
            {
                addToQueue(rear, tx, ty, 2, tdist);
            }
        }
        visit[ux][uy][ud] = false;
        if (++front >= MAXN * MAXN * 64)
        {
            front = 0;
        }
    }
}

int main()
{
    while (true)
    {
        origin.input();
        target.input();
        if (origin.x == 0 && origin.y == 0 && target.x == 0 && target.y == 0)
        {
            break;
        }
        scanf("%d", &n);
        xSet.init();
        ySet.init();
        xSet.insert(INF);
        xSet.insert(-INF);
        ySet.insert(INF);
        ySet.insert(-INF);
        xSet.insert(origin.x);
        ySet.insert(origin.y);
        xSet.insert(target.x);
        ySet.insert(target.y);
        for (int i = 0; i < n; ++i)
        {
            rect[i].input();
            xSet.insert(rect[i].x1);
            xSet.insert(rect[i].x2);
            ySet.insert(rect[i].y1);
            ySet.insert(rect[i].y2);
        }
        xSet.build();
        ySet.build();
        origin.x = xSet.getIndex(origin.x);
        origin.y = ySet.getIndex(origin.y);
        target.x = xSet.getIndex(target.x);
        target.y = ySet.getIndex(target.y);
        memset(graph, true, sizeof(graph));
        for (int i = 0; i < n; ++i)
        {
            rect[i].x1 = xSet.getIndex(rect[i].x1);
            rect[i].x2 = xSet.getIndex(rect[i].x2);
            rect[i].y1 = ySet.getIndex(rect[i].y1);
            rect[i].y2 = ySet.getIndex(rect[i].y2);
            rect[i].x1 = rect[i].x1 * 2 + 1;
            rect[i].y1 = rect[i].y1 * 2 + 1;
            rect[i].x2 = rect[i].x2 * 2;
            rect[i].y2 = rect[i].y2 * 2;
            for (int j = rect[i].x1; j <= rect[i].x2; ++j)
            {
                graph[j][rect[i].y1] = false;
                graph[j][rect[i].y2] = false;
            }
            for (int j = rect[i].y1; j <= rect[i].y2; ++j)
            {
                graph[rect[i].x1][j] = false;
                graph[rect[i].x2][j] = false;
            }
        }
        n = xSet.cnt * 2;
        m = ySet.cnt * 2;
        spfa();
        bool flag = false;
        int ans = INF;
        for (int i = 0; i < 4; ++i)
        {
            int x1 = target.x * 2;
            int x2 = x1 + 1;
            int y1 = target.y * 2;
            int y2 = y1 + 1;
            if (dist[x1][y1][i] != -1)
            {
                flag = true;
                ans = min(ans, dist[x1][y1][i]);
            }
            if (dist[x1][y2][i] != -1)
            {
                flag = true;
                ans = min(ans, dist[x1][y2][i]);
            }
            if (dist[x2][y1][i] != -1)
            {
                flag = true;
                ans = min(ans, dist[x2][y1][i]);
            }
            if (dist[x2][y2][i] != -1)
            {
                flag = true;
                ans = min(ans, dist[x2][y2][i]);
            }
        }
        if (flag)
        {
            printf("%d\n", ans);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
