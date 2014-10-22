#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXK = 43;

int strength[MAXK];
long long accLcm[MAXK];

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}

long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}

void init()
{
    for (int i = 0; i < MAXK; ++i)
    {
        strength[i] = 1;
        for (int j = 1; j < i; ++j)
        {
            if (i % j != 0)
            {
                strength[i] = strength[j] + 1;
                break;
            }
        }
    }
    accLcm[0] = 1;
    for (int i = 1; i < MAXK; ++i)
    {
        accLcm[i] = lcm(accLcm[i - 1], i);
    }
}

long long getStrengthSum(long long x)
{
    if (x == 0)
    {
        return 0;
    }
    long long res = 0;
    long long last = x;
    int i;
    for (i = 2; i < MAXK && accLcm[i] <= x; ++i)
    {
        long long num = x / accLcm[i];
        res += (last - num) * (strength[i] + 1);
        printf("%lld %lld %lld %d\n", last, num, last - num, strength[i] + 1);
        last = num;
    }
    res += last * (strength[i] + 1);
    return res;
}

int main()
{
    long long a, b;
    init();
    while (~scanf("%lld%lld", &a, &b))
    {
        printf("%lld\n", getStrengthSum(b) - getStrengthSum(a - 1));
    }
    return 0;
}
