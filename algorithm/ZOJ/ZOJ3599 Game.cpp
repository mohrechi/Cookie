#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1000000;

long long a[MAXN], b[MAXN];

int main()
{
    int t, k, n;
    cin >> t;
    while (t--)
    {
        cin >> k >> n;
        int i = 0, j = 0;
        a[0] = 1, b[0] = 1;
        while (a[i] < n)
        {
            ++i;
            a[i] = b[i - 1] + 1;
            while (a[j + 1] * k < a[i])
            {
                ++j;
            }
            if (a[j] * k < a[i])
            {
                b[i] = b[j] + a[i];
            }
            else
            {
                b[i] = a[i];
            }
        }
        cout <<  n - i - (a[i] == n) << endl;
    }
    return 0;
}
