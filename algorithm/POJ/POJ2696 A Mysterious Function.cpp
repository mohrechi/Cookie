#include <cstdio>
#include <cstring>
const int MAXN = 1005;

bool visit[MAXN];
int value[MAXN];
int a, b, c, d, e, f, g, h, i;

int mod(int x, int y)
{
    if(x < 0)
    {
        x += (- x / y + 1) * y;
    }
    return x % y;
}

int phi(int x)
{
    if(visit[x])
    {
        return value[x];
    }
    visit[x] = true;
    if(x==0)
    {
        return value[x] = a;
    }
    if(x==1)
    {
        return value[x] = b;
    }
    if(x==2)
    {
        return value[x] = c;
    }
    else if(x & 1)
    {
        return value[x] = mod(d * phi(x-1) + e * phi(x-2) - f * phi(x-3), g);
    }
    else
    {
        return value[x] = mod(f * phi(x-1) - d * phi(x-2) + e * phi(x-3), h);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h, &i);
        memset(visit, false, sizeof(visit));
        printf("%d\n", phi(i));
    }
    return 0;
}
