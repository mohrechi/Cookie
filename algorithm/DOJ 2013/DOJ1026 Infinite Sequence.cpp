#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long fib[200];
int fibNum;

void init()
{
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; ; ++i)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        if (fib[i] < 0)
        {
            fibNum = i;
            break;
        }
    }
}

long long get(long long n)
{
    if (n <= 0)
    {
        return 0;
    }
    int i;
    for (i = 1; i < fibNum; ++i)
    {
        if (n < fib[i])
        {
            break;
        }
    }
    return fib[i - 2] + get(n - fib[i - 1]);
}

int main()
{
    int t;
    long long a, b;
    init();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld", &a, &b);
        printf("%lld\n", get(b) - get(a - 1));
    }
    return 0;
}
