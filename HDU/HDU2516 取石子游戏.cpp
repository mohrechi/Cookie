#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    long long n;
    while (cin >> n, n)
    {
        bool ans = true;
        if (n == 1 || n == 2)
        {
            ans = false;
        }
        int a = 1, b = 2;
        while (a + b <= n)
        {
            int c = a + b;
            if (c == n)
            {
                ans = false;
            }
            a = b, b = c;
        }
        puts(ans ? "First win" : "Second win");
    }
    return 0;
}
