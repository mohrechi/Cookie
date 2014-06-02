#include <cstdio>
#include <algorithm>
using namespace std;

int getMini(int n)
{
    int a = 0, b = 1;
    int remain = n;
    while (a + b < n)
    {
        remain = min(remain, n - a - b);
        int c = a + b;
        a = b, b = c;
    }
    if (a + b == n)
    {
        return n;
    }
    return getMini(remain);
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int a = 0, b = 1;
        while (a + b < n)
        {
            int c = a + b;
            a = b, b = c;
        }
        if (a + b == n)
        {
            puts("lose");
        }
        else
        {
            printf("%d\n", getMini(n));
        }
    }
    return 0;
}
