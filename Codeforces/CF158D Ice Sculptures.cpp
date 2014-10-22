#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 20005;

int n, a[MAXN];

bool isPrime[MAXN];
int prime[MAXN], primeNum;

void init()
{
    memset(isPrime, true, sizeof(isPrime));
    for(int i=4;i<MAXN;i+=2)
    {
        isPrime[i] = false;
    }
    for(int i=3;i<MAXN;i+=2)
    {
        for(int j=3;i*j<MAXN;j+=2)
        {
            isPrime[i*j] = false;
        }
    }
    for(int i=2;i<MAXN;++i)
    {
        if(isPrime[i])
        {
            prime[primeNum++] = i;
        }
    }
}

int factorNum;
int factor[32], factorCnt[32];

void getPrimeFactor(int x)
{
    factorNum = 0;
    for(int i=0;prime[i]<=x;++i)
    {
        if(x % prime[i] == 0)
        {
            factor[factorNum] = prime[i];
            factorCnt[factorNum] = 0;
            while(x % prime[i] == 0)
            {
                x /= prime[i];
                ++ factorCnt[factorNum];
            }
            ++ factorNum;
        }
    }
    if(x > 1)
    {
        factor[factorNum] = x;
        factorCnt[factorNum++] = 1;
    }
}

int factNum;
int fact[MAXN];

void dfs(int pos, int total)
{
    if(pos == factorNum)
    {
        fact[factNum++] = total;
        return;
    }
    for(int i=0;i<=factorCnt[pos];++i)
    {
        dfs(pos + 1, total);
        total *= factor[pos];
    }
}

void getFactor()
{
    factNum = 0;
    dfs(0, 1);
}

int main()
{
    int n;
    init();
    while(~scanf("%d", &n))
    {
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
            ans += a[i];
        }
        getPrimeFactor(n);
        getFactor();
        for(int i=1;i<factNum;++i)
        {
            if(n / fact[i] >= 3)
            {
                for(int j=0;j<fact[i];++j)
                {
                    int cnt = 0;
                    for(int k=j;k<n;k+=fact[i])
                    {
                        cnt += a[k];
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
