#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline int abs(int x)
{
    if(x < 0)
    {
        return - x;
    }
    return x;
}

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int caseNumber;
    int x1, y1, x2, y2;
    int x, y;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x = abs(x1 - x2);
        y = abs(y1 - y2);
        int g = gcd(x, y);
        if(g == 0)
        {
            printf("Case %d:1\n\n", cas);
        }
        else
        {
            printf("Case %d:%d\n\n", cas, g + 1);
        }
    }
    return 0;
}
