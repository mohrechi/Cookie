#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 25;

long long n, k;
long long a[MAXN];

int main()
{
    while (cin >> n >> k)
    {
        long long sum = 0;
        for (int i = 0; i < k; ++i)
        {
            cin >> a[i];
            sum += n - a[i];
        }
        n -= sum;
        if (n < 0)
        {
            n = 0;
        }
        cout << n << endl;
    }
    return 0;
}
