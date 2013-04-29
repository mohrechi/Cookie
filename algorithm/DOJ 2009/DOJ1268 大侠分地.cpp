#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int getSec(int x1, int x2, int y1, int y2)
{
    if(y1 >= x1 && y1 < x2)
    {
        return min(y2, x2) - y1;
    }
    else if(y2 > x1 && y2 <= x2)
    {
        return y2 - x1;
    }
    else if(x1 >= y1 && x1 < y2)
    {
        return x2 - x1;
    }
    return 0;
}

int main()
{
    int t;
    int dx1, dy1, dx2, dy2, xx1, xy1, xx2, xy2;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d%d%d%d%d%d", &dx1, &dy1, &dx2, &dy2, &xx1, &xy1, &xx2, &xy2);
        long long len1 = getSec(dx1, dx2, xx1, xx2);
        long long len2 = getSec(dy1, dy2, xy1, xy2);
        printf("%lld\n", len1 * len2);
    }
    return 0;
}
