#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

long long getSum(int num, int times)
{
    return ((num + (long long)num * times) * times) >> 1;
}

int main()
{
    int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
        --N;
        cout << getSum(3, N / 3) + getSum(5, N / 5) - getSum(15, N / 15) << endl;
    }
    return 0;
}
