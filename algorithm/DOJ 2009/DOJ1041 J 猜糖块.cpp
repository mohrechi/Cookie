#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;

bool notPrime[MAXN];
int notPrimeNum[MAXN];

void init()
{
    memset(notPrime, false, sizeof(notPrime));
    notPrime[0] = notPrime[1] = true;
    for(int i=4;i<MAXN;i+=2)
    {
        notPrime[i] = true;
    }
    for(int i=3;i<MAXN;i+=2)
    {
        for(int j=3;i*j<MAXN;j+=2)
        {
            notPrime[i * j] = true;
        }
    }
    notPrimeNum[0] = 1;
    for(int i=1;i<MAXN;++i)
    {
        notPrimeNum[i] = notPrimeNum[i - 1] + notPrime[i];
    }
}

int main()
{
    int a, b;
    init();
    while(~scanf("%d%d", &a, &b))
    {
        int num = notPrimeNum[b] - notPrimeNum[a - 1];
        int ans = 0;
        while(num)
        {
            num >>= 1;
            ++ ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
