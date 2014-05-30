#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    double p = (sqrt(5.0) + 1.0) * 0.5;
    int a, b, ta, tb;
    while (~scanf("%d%d", &a, &b), a || b)
    {
        int t = b - a;
        if (a == (int)(p * t))
        {
            puts("0");
        }
        else
        {
            puts("1");
            for (int i = 0; (int)(p * i) <= a; ++i)
            {
                ta = (int)(p * i);
                tb = ta + i;
                if (a - ta == b - tb)
                {
                    printf("%d %d\n", ta, tb);
                }
            }
            for (int i = 0; (int)(p * i) <= a; ++i)
            {
                ta = (int)(p * i);
                tb = ta + i;
                if (a == ta || b == tb || a == tb || b == ta)
                {
                    printf("%d %d\n", ta, tb);
                }
            }
        }
    }
    return 0;
}
