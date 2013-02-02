#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int phi(int x)
{
    if(x == 1)
    {
        return 0;
    }
    int sum = 1;
    for(int i=2;i*i<=x;++i)
    {
        if(x % i == 0)
        {
            sum *= i - 1;
            x /= i;
        }
        while(x % i == 0)
        {
            sum *= i;
            x /= i;
        }
    }
    if(x > 1)
    {
        sum *= x - 1;
    }
    return sum;
}

int main()
{
    int k, n;
    scanf("%d", &k);
    while(k--)
    {
        scanf("%d", &n);
        if(n & 1)
        {
            printf("%d\n", phi(n + 1) + phi((n + 1) / 2) - 1);
        }
        else
        {
            printf("%d\n", phi(n + 1) - 1);
        }
    }
    return 0;
}
