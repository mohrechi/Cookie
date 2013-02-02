#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int getOneNumber(int x)
{
    int cnt = 0;
    for(int i=0;(1<<i)<=x;++i)
    {
        if(x & (1<<i))
        {
            ++ cnt;
        }
    }
    return cnt;
}

int getPow2(int x)
{
    int res = 1;
    for(int i=1;i<=x;++i)
    {
        res *= 2;
    }
    return res;
}

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        printf("%d\n", getPow2(getOneNumber(n)));
    }
    return 0;
}
