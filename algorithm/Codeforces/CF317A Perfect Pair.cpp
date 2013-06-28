#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    long long x, y, m;
    while (cin >> x >> y >> m)
    {
        long long ans = 0;
        if (x < m && y < m && x <= 0 && y <= 0)
        {
            ans = -1;
        }
        else
        {
            while (x < m && y < m)
            {
                if (x > y)
                {
                    if (x + y < 0)
                    {
                        ans -= y / x;
                        y -= y / x * x;
                    }
                    else
                    {
                        ++ans;
                        y += x;
                    }
                }
                else
                {
                    if (x + y < 0)
                    {
                        ans -= x / y;
                        x -= x / y * y;
                    }
                    else
                    {
                        ++ans;
                        x += y;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
