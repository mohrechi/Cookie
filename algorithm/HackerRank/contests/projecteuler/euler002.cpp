#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    long long N;
    long long fibs[100] = {1, 1};
    for (int i = 2; i < 100; ++i)
    {
        fibs[i] = fibs[i - 1] + fibs[i - 2];
    }
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &N);
        long long ans = 0;
        for (int i = 1; i < 100; ++i)
        {
            if (fibs[i] > N)
            {
                break;
            }
            if (!(fibs[i] & 1))
            {
                ans += fibs[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}