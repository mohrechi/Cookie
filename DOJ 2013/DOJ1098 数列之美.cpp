#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100001;

int fib[MAXN];

int main()
{
    int n, m;
    fib[1] = 1;
    fib[2] = 1;
    for (int i = 3; i < MAXN; ++i)
    {
        fib[i] = (fib[i - 1] + fib[i - 2]) % 100;
    }
    for (int i = 1; i < MAXN; ++i)
    {
        fib[i] /= 10;
    }
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &m);
        printf("%d\n", fib[m]);
    }
    return 0;
}
