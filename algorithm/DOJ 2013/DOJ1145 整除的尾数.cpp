#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    while (~scanf("%d%d", &a, &b), a || b)
    {
        a *= 100;
        bool flag = true;
        for (int i = 0; i < 100; ++i)
        {
            if ((a + i) % b == 0)
            {
                if (flag)
                {
                    flag = false;
                }
                else
                {
                    putchar(' ');
                }
                printf("%d%d", i / 10, i % 10);
            }
        }
        putchar('\n');
    }
    return 0;
}
