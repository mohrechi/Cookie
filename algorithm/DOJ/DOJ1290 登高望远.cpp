#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50005;
const int MOD = 1000000007;

int step[20];
int num[MAXN];

void init()
{
    step[0] = 1;
    for(int i=1;i<20;++i)
    {
        step[i] = step[i - 1] * 2;
    }
    num[0] = 1;
    for(int i=1;i<MAXN;++i)
    {
        for(int j=0;step[j]<=i;++j)
        {
            num[i] = (num[i] + num[i - step[j]]) % MOD;
        }
    }
}

int main()
{
    int n;
    init();
    while(~scanf("%d", &n))
    {
        printf("%d\n", num[n]);
    }
    return 0;
}
