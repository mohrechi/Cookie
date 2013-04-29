#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;

long long sum1[MAXN];
long long sum2[MAXN];

void init()
{
    for(int i=1;i<MAXN;++i)
    {
        for(int j=i;j<MAXN;j+=i)
        {
            sum1[j] += i;
        }
    }
    for(int i=1;i<MAXN;++i)
    {
        sum2[i] = sum1[i] + sum2[i - 1];
    }
}

int main()
{
    int t, n;
    init();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%lld\n", sum2[n]);
    }
    return 0;
}
