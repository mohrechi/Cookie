#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n, x, y, ansX, ansY;
    while (~scanf("%d%d", &ansX, &ansY))
    {
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d%d", &x, &y);
            if (x * ansY < ansX * y)
            {
                ansX = x;
                ansY = y;
            }
        }
        printf("%.2lf\n", 1000.0 * ansX / ansY);
    }
    return 0;
}
