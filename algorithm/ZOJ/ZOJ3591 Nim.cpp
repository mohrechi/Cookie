#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;

int a[MAXN], sg[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, s, w, ans = 0;
        scanf("%d%d%d", &n, &s, &w);
        int g = s;
        for (int i = 0; i < n; ++i)
        {
            a[i] = g;
            if (a[i] == 0)
            {
                a[i] = g = w;
            }
            if (g & 1)
            {
                g = (g >> 1) ^ w;
            }
            else
            {
                g >>= 1;
            }
            ans ^= a[i];
            sg[i] = ans;
        }
        sort(sg, sg + n);
        long long sum = 1LL * n * (n + 1) / 2;
        int len = 1;
        for (int i = 1; i < n; ++i)
        {
            if (sg[i] == sg[i - 1])
            {
                ++len;
            }
            else
            {
                if (sg[i - 1] == 0)
                {
                    sum -= len;
                }
                sum -= 1LL * len * (len - 1) / 2;
                len = 1;
            }
        }
        sum -= 1LL * len * (len - 1) / 2;
        cout << sum << endl;
    }
    return 0;
}
