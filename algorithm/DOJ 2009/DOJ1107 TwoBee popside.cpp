#include <cstdio>

long long n,k,m;

int main(int argc, char *argv[])
{
    while(~scanf("%lld%lld%lld",&n,&k,&m))
    {
        printf("%lld\n", n/(k-m)*m);
    }
    return 0;
}
