#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, d;
    while (~scanf("%d%d%d%d", &a, &b, &c, &d))
    {
        if (b - a == c - b && c - b == d - c)
        {
            printf("%d\n", d + d - c);
        }
        else
        {
            if (a * c == b * b && b * d == c * c && (d * d) % c == 0)
            {
                printf("%d\n", d * d / c);
            }
            else
            {
                printf("42\n");
            }
        }
    }
    return 0;
}
