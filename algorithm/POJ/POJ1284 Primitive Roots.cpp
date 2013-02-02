#include <cstdio>
#include <cstring>

int eular(int x)
{
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
    int n;
    while(~scanf("%d", &n))
    {
        printf("%d\n", eular(n - 1));
    }
    return 0;
}
