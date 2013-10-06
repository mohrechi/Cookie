#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, a;
    long long top = 0;
    long long sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a);
        sum += a;
        if (a > top)
        {
            top = a;
        }
    }
    long long ans = max(top, (sum - 1) / (n - 1) + 1);
    cout << ans << endl;
    return 0;
}
