#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        long long ans = n;
        for(int i=1;i<=n;++i)
        {
            ans += i * (n - i);
        }
        cout << ans << endl;
    }
    return 0;
}
