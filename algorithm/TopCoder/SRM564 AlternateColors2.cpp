#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

class AlternateColors2
{
public:
    long long countWays(int n, int k)
    {
        long long ans = 0;
        if((k - 1) % 3 == 0)
        {
            int remain = n - k;
            ans += (long long)(remain + 2) * (remain + 1) / 2;
        }
        for(int i=0;i*3<(k-1);++i)
        {
            int remain = k - 1 - i * 3;
            ans += (remain - 1) / 2 * 2 + 1;
            if(remain % 2 == 0)
            {
                ans += n - k + 1;
                ans += n - k + 1;
            }
        }
        return ans;
    }
}; //392.99
