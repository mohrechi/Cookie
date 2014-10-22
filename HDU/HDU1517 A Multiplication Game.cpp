#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    long long n;
    while (cin >> n)
    {
        int cnt = 0;
        while (n > 1)
        {
            if (cnt & 1)
            {
                n = ceil(n / 2.0);
            }
            else
            {
                n = ceil(n / 9.0);
            }
            ++cnt;
        }
        puts((cnt & 1) ? "Stan wins." : "Ollie wins.");
    }
    return 0;
}
