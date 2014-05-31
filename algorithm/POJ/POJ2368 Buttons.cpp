#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int a = -1;
        for (int i = 1; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                if ((a == -1 || i < a) && i > 2)
                {
                    a = i;
                }
                if ((a == -1 || n / i < a) && n / i > 2)
                {
                    a = n / i;
                }
            }
        }
        if (a == -1)
        {
            a = 1;
        }
        printf("%d\n", a - 1);
    }
    return 0;
}
