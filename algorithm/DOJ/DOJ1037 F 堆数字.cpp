#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long n, ans;

void dfs(long long num)
{
    if(num > n)
    {
        return;
    }
    if(n % num == 0)
    {
        ans = min(ans, n / num);
    }
    dfs(num * 10);
    dfs(num * 10 + 1);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        ans = n;
        dfs(1);
        printf("%lld\n", ans);
    }
    return 0;
}
