#include <cstdio>

int main()
{
    int n, a;
    int c1 = 0, c2 = 0;
    bool flag = true;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &a);
        if (a == 25)
        {
            ++c1;
        }
        else if (a == 50)
        {
            if (c1 > 0)
            {
                --c1;
                ++c2;
            }
            else
            {
                flag = false;
                break;
            }
        }
        else if (a == 100)
        {
            if (c2 > 0)
            {
                if (c1 > 0)
                {
                    --c1;
                    --c2;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                if (c1 > 2)
                {
                    c1 -= 3;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
    }
    if (flag)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
