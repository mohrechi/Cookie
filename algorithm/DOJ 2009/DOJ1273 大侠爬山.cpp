#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100001;
const int MOD = 100000007;

int num[MAXN];

void init()
{
    num[0] = 1;
    num[1] = 1;
    num[2] = 2;
    for(int i=3;i<MAXN;++i)
    {
        num[i] = (num[i-2] + num[i-3]) % MOD;
        num[i] = (num[i] + num[i-1]) % MOD;
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
        printf("%d\n", num[n]);
    }
    return 0;
}
