#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    long long r, b, w, h;
    while (~scanf("%lld%lld", &r, &b))
    {
        long long sum = (r + 4) >> 1;
        for (h = 1; h <= (sum >> 1); ++h)
        {
            w = sum - h;
            if (w * h == r + b)
            {
                break;
            }
        }
        printf("%lld %lld\n", w, h);
    }
    return 0;
}
