#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long T, G, L;
    cin >> T;
    while (T--)
    {
        cin >> G >> L;
        if (L % G)
        {
            cout << 0 << endl;
        }
        else
        {
            L /= G;
            long long ans = 1;
            for (long long i = 2; i * i <= L; ++i)
            {
                if (L % i == 0)
                {
                    int cnt = 0;
                    while (L % i == 0)
                    {
                        ++cnt;
                        L /= i;
                    }
                    ans *= cnt * 6;
                }
            }
            if (L != 1)
            {
                ans *= 6;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
