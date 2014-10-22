#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

bool isNearlyLucky(long long n)
{
    int cnt = 0;
    while(n)
    {
        if(n % 10 == 4 || n % 10 == 7)
        {
            ++ cnt;
        }
        n /= 10;
    }
    return cnt == 4 || cnt == 7;
}

int main()
{
    long long n;
    while(cin >> n)
    {
        if(isNearlyLucky(n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
