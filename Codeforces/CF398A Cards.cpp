#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    __int64 a, b;
    while (~scanf("%I64d%I64d", &a, &b))
    {
        if (a == 0)
        {
            printf("%I64d\n", - b * b);
            while (b--)
            {
                putchar('x');
            }
            putchar('\n');
        }
        else if (b == 0)
        {
            printf("%I64d\n", a * a);
            while (a--)
            {
                putchar('o');
            }
            putchar('\n');
        }
        else if (b == 1)
        {
            printf("%I64d\n", a * a - 1);
            while (a--)
            {
                putchar('o');
            }
            puts("x");
        }
        else
        {
            __int64 ans = -0x7fffffffffffffffLL;
            __int64 ansNum1, ansNum2;
            __int64 ansK, ansBlock;
            for (int k = 0; k <= min(a - 1, b - 2); ++k)
            {
                __int64 scoreA = (a - k) * (a - k) + k;
                __int64 block = b / (k + 2);
                __int64 num2 = b % (k + 2);
                __int64 num1 = k + 2 - num2;
                __int64 scoreB = num1 * block * block + num2 * (block + 1) * (block + 1);
                __int64 score = scoreA - scoreB;
                if (score > ans)
                {
                    ans = score;
                    ansNum1 = num1;
                    ansNum2 = num2;
                    ansK = k;
                    ansBlock = block;
                }
            }
            printf("%I64d\n", ans);
            for (int i = 0; i < ansBlock; ++i)
            {
                putchar('x');
            }
            --ansNum1;
            for (int i = 0; i < (a - ansK); ++i)
            {
                putchar('o');
            }
            while (ansNum1--)
            {
                for (int i = 0; i < ansBlock; ++i)
                {
                    putchar('x');
                }
                if (ansNum1 || ansNum2)
                {
                    putchar('o');
                }
            }
            while (ansNum2--)
            {
                for (int i = 0; i < ansBlock + 1; ++i)
                {
                    putchar('x');
                }
                if (ansNum2)
                {
                    putchar('o');
                }
            }
            putchar('\n');
        }
    }
    return 0;
}
