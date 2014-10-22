#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

unsigned __int64 factor[100005];
unsigned __int64 factorNumber;
unsigned __int64 factorCount[100005];

unsigned __int64 gcd(unsigned __int64 a,unsigned __int64 b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}
unsigned __int64 mul_mod(unsigned __int64 a,unsigned __int64 b,unsigned __int64 n)
{
    unsigned __int64 exp = a % n;
    unsigned __int64 res = 0;
    while(b)
    {
        if(b&1)
        {
            res += exp;
            if(res > n)
            {
                res -= n;
            }
        }
        exp <<= 1;
        if(exp>n)
        {
            exp -= n;
        }
        b >>= 1;
    }
    return res;
}

unsigned __int64 exp_mod(unsigned __int64 a,unsigned __int64 b,unsigned __int64 c)
{
    unsigned __int64 k = 1;
    while(b)
    {
        if(b & 1)
        {
            k = mul_mod(k, a, c);
        }
        a = mul_mod(a, a, c);
        b >>= 1;
    }
    return k;
}

bool miller_rabbin(unsigned __int64 n, unsigned __int64 times)
{
    if(n == 2)
    {
        return 1;
    }
    if(n < 2 || !(n & 1))
    {
        return 0;
    }
    unsigned __int64 a, u = n - 1, x, y;
    int t = 0;
    while((u&1) == 0)
    {
        ++ t;
        u >>= 1;
    }
    for(int i=0;i<times;i++)
    {
        a = rand() % (n-1) + 1;
        x = exp_mod(a, u, n);
        for(int j=0;j<t;j++)
        {
            y = mul_mod(x, x, n);
            if(y == 1 && x != 1 && x != n-1)
            {
                return false;
            }
            x = y;
        }
        if(y != 1)
        {
            return false;
        }
    }
    return true;
}

unsigned __int64 pollard_rho(unsigned __int64 n,unsigned __int64 c)
{
    unsigned __int64 x,y,d,i=1,k=2;
    y = x = rand() % (n-1) + 1;
    while(true)
    {
        ++ i;
        x = (mul_mod(x, x, n) + c) % n;
        d = gcd((x - y + n) % n, n);
        if(d > 1 && d < n)
        {
            return d;
        }
        if(x == y)
        {
            return n;
        }
        if(i == k)
        {
            k <<= 1;
            y = x;
        }
    }
}

void find_factor(unsigned __int64 n,unsigned __int64 c)
{
    if(n == 1)
    {
        return;
    }
    if(miller_rabbin(n, 6))
    {
        factor[factorNumber++] = n;
        return;
    }
    unsigned __int64 p = n;
    unsigned __int64 k = c;
    while(p>=n)
    {
        p = pollard_rho(p, c--);
    }
    find_factor(p, k);
    find_factor(n / p, k);
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    while(caseNumber--)
    {
        unsigned __int64 n;
        scanf("%I64u", &n);
        factorNumber = 0;
        find_factor(n, 120);
        sort(factor, factor + factorNumber);
        factorCount[0] = 1;
        int k = 1;
        for(int i=1;i<factorNumber;++i)
        {
            if(factor[i] == factor[i-1])
            {
                ++ factorCount[k - 1];
            }
            else
            {
                factorCount[k] = 1;
                factor[k++] = factor[i];
            }
        }
        factorNumber = k;
        printf("%d ", k);
        unsigned __int64 sum = 0;
        for(int i=0;i<factorNumber;++i)
        {
            unsigned __int64 temp = 1;
            for(int j=0;j<factorCount[i];++j)
            {
                temp *= factor[i];
            }
            sum += temp;
        }
        if(factorNumber == 1)
        {
            sum /= factor[0];
        }
        printf("%I64u\n", sum);
    }
    return 0;
}
