#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXP = 65536;

int prime[MAXP], primeNum;
bool isPrime[MAXP];

void initPrime()
{
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 4; i < MAXP; i += 2)
    {
        isPrime[i] = false;
    }
    for (int i = 3; i < MAXP; i += 2)
    {
        for (int j = 3; i * j < MAXP; j += 2)
        {
            isPrime[i * j] = false;
        }
    }
    for (int i = 2; i < MAXP; ++i)
    {
        if (isPrime[i])
        {
            prime[primeNum++] = i;
        }
    }
}

int factorNum(int x)
{
    int count = 1;
    for (int i = 0; i < primeNum; ++i)
    {
        if (x % prime[i] == 0)
        {
            int tc = 0;
            while (x % prime[i] == 0)
            {
                x /= prime[i];
                ++tc;
            }
            count *= (tc + 1);
        }
    }
    if (x > 1)
    {
        count *= 2;
    }
    return count;
}

int getBitNum(int x)
{
    int i;
    for (i = 0; (1 << i) <= x; ++i);
    return i;
}

long long ans;
long long ansNum;
int a, b;

void dfs(long long sum, long long num, int depth)
{
    if (depth >= 40)
    {
        return;
    }
    if (prime[depth] > b)
    {
        return;
    }
    if (sum > b)
    {
        return;
    }
    if (sum >= a && sum <= b)
    {
        if (num > ansNum)
        {
            ansNum = num;
            ans = sum;
        }
        else if (num == ansNum)
        {
            ans = min(ans, sum);
        }
    }
    for (int i = 0; i <= 31; ++i)
    {
        dfs(sum, num * (i + 1), depth + 1);
        sum = sum * prime[depth];
        if (sum > b)
        {
            break;
        }
    }
    return;
}

int main()
{
    initPrime();
    while (~scanf("%d%d", &a, &b))
    {
        if (a == 1 && b == 1)
        {
            printf("1 1\n");
        }
        else
        {
            if (a == 1)
            {
                ans = a + 1;
            }
            else
            {
                ans = a;
            }
            ansNum = 2;
            dfs(1, 1, 0);
            printf("%lld %lld\n", ansNum, ans);
        }
    }
    return 0;
}
