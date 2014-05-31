#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200 + 10;

int sg[MAXN][MAXN];

int getSG(int w, int h)
{
    if (sg[w][h] != -1)
    {
        return sg[w][h];
    }
    bool visit[MAXN];
    memset(visit, false, sizeof(visit));
    for (int i = 2; i <= (w >> 1); ++i)
    {
        visit[getSG(i, h) ^ getSG(w - i, h)] = true;
    }
    for (int i = 2; i <= (h >> 1); ++i)
    {
        visit[getSG(w, i) ^ getSG(w, h - i)] = true;
    }
    for (int i = 0; i < MAXN; ++i)
    {
        if (!visit[i])
        {
            return sg[w][h] = i;
        }
    }
}

int main()
{
    int w, h;
    memset(sg, -1, sizeof(sg));
    sg[1][1] = 0;
    while (~scanf("%d%d", &w, &h))
    {
        puts(getSG(w, h) ? "WIN": "LOSE");
    }
    return 0;
}
