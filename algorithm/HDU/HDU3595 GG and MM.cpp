#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

bool p[MAXN][MAXN];
int step[MAXN][MAXN];

int getStep(int a, int b)
{
    if (step[a][b] != -1)
    {
        return step[a][b];
    }
    if (a < b)
    {
        return getStep(b, a);
    }
    if (b == 0)
    {
        p[a][b] = p[b][a] = true;
        return step[a][b] = step[b][a] = 0;
    }
    p[a][b] = true;
    for (int i = 1; a >= i * b; ++i)
    {
        getStep(a - i * b, b);
        if (p[a - i * b][b])
        {
            p[a][b] = false;
        }
    }
    p[b][a] = p[a][b];
    step[a][b] = -1;
    if (p[a][b])
    {
        for (int i = 1; a >= i * b; ++i)
        {
            if (step[a][b] == -1 || step[a - i * b][b] < step[a][b])
            {
                step[a][b] = step[a - i * b][b];
            }
        }
    }
    else
    {
        for (int i = 1; a >= i * b; ++i)
        {
            if (p[a - i * b][b])
            {
                if (step[a][b] == -1 || step[a - i * b][b] > step[a][b])
                {
                    step[a][b] = step[a - i * b][b];
                }
            }
        }
    }
    step[b][a] = ++step[a][b];
    return step[a][b];
}

int main()
{
    int n, a, b;
    memset(step, -1, sizeof(step));
    while (~scanf("%d", &n))
    {
        int ans = 0;
        while (n--)
        {
            scanf("%d%d", &a, &b);
            ans = max(ans, getStep(a, b));
        }
        puts(ans & 1 ? "MM" : "GG");
    }
    return 0;
}
