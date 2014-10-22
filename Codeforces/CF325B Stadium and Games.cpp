#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const long long MAXN = 1500000000LL;

int main()
{
    long long n, ans[10], ansNum;
    while (cin >> n)
    {
        ansNum = 0;
        for (int i = 0; (1LL << i) - 1 <= n; ++i)
        {
            long long mul = (1LL << i) - 1;
            long long left = 1;
            long long right = mul ? min(MAXN, n / mul + 1) : MAXN;
            long long mid;
            while (left <= right)
            {
                mid = (left + right) >> 1;
                unsigned long long x = ((mid * (mid - 1)) >> 1) + mid * mul;
                if (x < n)
                {
                    left = mid + 1;
                }
                else if (x > n)
                {
                    right = mid - 1;
                }
                else
                {
                    break;
                }
            }
            long long x = ((mid * (mid - 1)) >> 1) + mid * mul;
            if (x == n && (mid & 1))
            {
                ans[ansNum++] = mid << i;
            }
        }
        if (ansNum)
        {
            for (int i = 0; i < ansNum; ++i)
            {
                cout << ans[i] << endl;
            }
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
