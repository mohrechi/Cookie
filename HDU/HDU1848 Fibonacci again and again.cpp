#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;

int sg[MAXN];

int getSG(int n)
{
    if (sg[n] != -1)
    {
        return sg[n];
    }
    int a = 1, b = 2;
    bool visit[100] = {false};
    if (a <= n) visit[getSG(n - a)] = true;
    if (b <= n) visit[getSG(n - b)] = true;
    while (a + b <= n)
    {
        int c = a + b;
        visit[getSG(n - c)] = true;
        a = b, b = c;
    }
    for (int i = 0; ; ++i)
    {
        if (!visit[i])
        {
            return sg[n] = i;
        }
    }
}

int main()
{
    int m, n, p;
    memset(sg, -1, sizeof(sg));
    while (scanf("%d%d%d", &m, &n, &p), m || n || p)
    {
        puts(getSG(m) ^ getSG(n) ^ getSG(p) ? "Fibo" : "Nacci");
    }
    return 0;
}
