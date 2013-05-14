#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void printBit(int x)
{
    for (int i = 7; i >= 0; --i)
    {
        if (x & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}

int main()
{
    int a, b, c, d;
    while (~scanf("%d.%d.%d.%d", &a, &b, &c, &d))
    {
        printBit(a);
        printf(".");
        printBit(b);
        printf(".");
        printBit(c);
        printf(".");
        printBit(d);
        printf("\n");
    }
    return 0;
}
