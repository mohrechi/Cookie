#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        long long a = n >> 1;
        long long b = n - a;
        long long ans = 0;
        while (gcd(a, b) != 1)
        {
            ans = max(ans, a * b / gcd(a, b));
            --a;
            ++b;
        }
        ans = max(ans, a * b);
        cout << ans << endl;
    }
    return 0;
}
