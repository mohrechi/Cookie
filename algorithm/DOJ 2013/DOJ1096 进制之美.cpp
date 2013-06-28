#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int sum(int x, int b)
{
    int res = 0;
    while (x)
    {
        res += x % b;
        x /= b;
    }
    return res;
}

int sum(int x)
{
    int res = 0;
    for (int i = 2; i < x; ++i)
    {
        res += sum(x, i);
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int a = sum(n);
        int b = n - 2;
        int g = gcd(a, b);
        printf("%d/%d\n", a / g, b / g);
    }
    return 0;
}
