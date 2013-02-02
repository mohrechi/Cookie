#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000;

int aNum[MAXN], bNum[MAXN];

bool contain8(long long x)
{
    while(x)
    {
        if(x % 10 == 8)
        {
            return true;
        }
        x /= 10;
    }
    return false;
}

void init()
{
    int a = 0, b = 0;
    for(int i=0;i<=MAXN;i+=8)
    {
        if(i)
        {
            for(int j=i-8;j<i;++j)
            {
                aNum[j] = a;
                bNum[j] = b;
            }
        }
        if(i == MAXN)
        {
            break;
        }
        if(contain8(i))
        {
            ++ a;
        }
        else
        {
            ++ b;
        }
    }
}

long long get8Number(long long x)
{
    long long ans = 0;
    long long highPart = x / 10;
    long long lowPart = x % 10;
    if(contain8(highPart))
    {
        ans += lowPart + 1;
    }
    else
    {
        ans += lowPart >= 8;
    }
    ans += highPart;
    -- highPart;
    if(highPart > 0)
    {
        ans += get8Number(highPart) * 9;
    }
    return ans;
}

long long getNumber(long long x)
{
    long long ans = 0;
    long long highPart = x / 1000;
    long long lowPart = x % 1000;
    if(contain8(highPart))
    {
        ans += aNum[lowPart] + bNum[lowPart];
    }
    else
    {
        ans += aNum[lowPart];
    }
    ans += highPart * aNum[MAXN - 1];
    -- highPart;
    if(highPart > 0)
    {
        ans += get8Number(highPart) * bNum[MAXN - 1];
    }
    return ans;
}

int main()
{
    int t;
    long long a, b;
    init();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld%lld", &a, &b);
        printf("%lld\n", getNumber(b) - getNumber(a - 1));
    }
    return 0;
}
