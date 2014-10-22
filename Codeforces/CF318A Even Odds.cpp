#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    long long n, k;
    while (cin >> n >> k)
    {
        if (k <= ((n + 1) >> 1))
        {
            k = (k << 1) - 1;
        }
        else
        {
            k -= (n + 1) >> 1;
            k <<= 1;
        }
        cout << k << endl;
    }
    return 0;
}
