#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

long long get(long long x)
{
    if(x < 6)
    {
        return 0;
    }
    long long xx = (long long)sqrt(x * 1.0);
    if(xx & 1)
    {
        return ((x - 4) >> 1) + 1;
    }
    else
    {
        return ((x - 4) >> 1);
    }
}

int main()
{
    int caseNumber;
    long long a, b;
    scanf("%d", &caseNumber);
    while(caseNumber--)
    {
        cin>>a>>b;
        if(a > b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        cout<<get(b) - get(a - 1)<<endl;
    }
    return 0;
}
