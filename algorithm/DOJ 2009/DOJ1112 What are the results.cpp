#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int r99[] = {45,900,13500,180000,2250000,27000000,14999979,99999755};

int func1(int n)
{
    int sum = (n / 9 * 45) % 100000007;
    int t;
    for(int i = n / 9 * 9 + 1; i<=n;++i)
    {
        t = i % 9;
        if(t == 0)
        {
            t = 9;
        }
        sum += t;
        sum %= 100000007;
    }
    return sum % 100000007;
}

int func2(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n < 10)
    {
        return (1 + n) * n / 2;
    }
    int sum = 0;
    int lowten, r=0;
    for(lowten = 10;lowten <= n; lowten *= 10)
    {
        ++r;
    }
    lowten /= 10;
    sum = r99[--r];
    for(int i=1;i<=9;++i)
    {
        if(i * lowten <= n && (i + 1) * lowten > n)
        {
            sum += ((n % lowten) + 1) * i;
            sum %= 100000007;
            break;
        }
        else
        {
            sum += lowten * i + r99[r];
            sum %= 100000007;
        }
    }
    sum += func2(n % lowten) % 100000007;
    return sum % 100000007;
}

int main(int argc, char *argv[])
{
    int k, n;
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&n);
        printf("%d %d\n", func1(n), func2(n));
    }
    return 0;
}
