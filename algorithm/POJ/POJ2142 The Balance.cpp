#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    int g = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

int main()
{
    int a, b, c;
    while (scanf("%d%d%d", &a, &b, &c), a || b || c)
    {
        int g = gcd(a, b);
        if (c % g)
        {
            puts("no solution");
        }
        else
        {
            int x, y, tx, ty, ax = 0x3f3f3f3f, ay = 0x3f3f3f3f;
            a /= g;
            b /= g;
            c /= g;
            exgcd(a, b, x, y);
            tx = (c * x % b + b) % b;
            while (true)
            {
                ty = (c - a * tx) / b;
                if (tx + abs(ty) < ax + ay || (tx + abs(ty) == ax + ay && a * tx + b * abs(ty) < a * ax + b * ay))
                {
                    ax = tx;
                    ay = abs(ty);
                }
                if (ty < 0 && tx + abs(ty) > ax + ay)
                {
                    break;
                }
                tx += b;
            }
            tx = (c * x % b + b) % b - b;
            while (true)
            {
                ty = (c - a * tx) / b;
                if (abs(tx) + ty < ax + ay || (abs(tx) + ty == ax + ay && a * abs(tx) + b * ty < a * ax + b * ay))
                {
                    ax = abs(tx);
                    ay = ty;
                }
                if (abs(tx) + ty > ax + ay)
                {
                    break;
                }
                tx -= b;
            }
            printf("%d %d\n", ax, ay);
        }
    }
    return 0;
}
