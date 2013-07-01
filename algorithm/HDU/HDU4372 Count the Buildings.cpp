#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2001;
const int MOD = 1000000007;

int c[MAXN][MAXN];
int s[MAXN][MAXN];
bool vc[MAXN][MAXN];
bool vs[MAXN][MAXN];

int C(int n, int m)
{
    if(vc[n][m])
    {
        return c[n][m];
    }
    if(m > (n >> 1))
    {
        return C(n, n - m);
    }
    vc[n][m] = true;
    if(m == 0)
    {
        return c[n][m] = 1;
    }
    if(m == 1)
    {
        return c[n][m] = n;
    }
    return c[n][m] = (C(n - 1, m - 1) + C(n - 1, m)) % MOD;
}

int S(int n, int m)
{
    if(vs[n][m])
    {
        return s[n][m];
    }
    if(n < m || m == 0)
    {
        return 0;
    }
    vs[n][m] = true;
    if(n == 1 && m == 1)
    {
        return s[n][m] = 1;
    }
    return s[n][m] = ( S(n-1, m-1) + ( (__int64)S(n-1, m) * (n - 1) ) % MOD ) % MOD;
}

int solve(int n, int f, int b)
{
    if(f + b - 1 > n)
    {
        return 0;
    }
    return ( (__int64)C(f + b - 2, f - 1) * S(n - 1, f + b - 2) ) % MOD;
}

int main()
{
    int n, f, b;
    int caseNumber;
    scanf("%d", &caseNumber);
    while(caseNumber--)
    {
        scanf("%d%d%d", &n, &f, &b);
        printf("%d\n", solve(n, f, b));
    }
    return 0;
}
