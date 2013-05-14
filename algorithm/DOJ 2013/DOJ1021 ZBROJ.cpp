#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline int lower(int x)
{
    int res = 0;
    int coe = 1;
    while (x)
    {
        int temp = x % 10;
        if (temp == 6)
        {
            temp = 5;
        }
        res += coe * temp;
        coe *= 10;
        x /= 10;
    }
    return res;
}

inline int upper(int x)
{
    int res = 0;
    int coe = 1;
    while (x)
    {
        int temp = x % 10;
        if (temp == 5)
        {
            temp = 6;
        }
        res += coe * temp;
        coe *= 10;
        x /= 10;
    }
    return res;
}

int main()
{
    int a, b;
    while (~scanf("%d%d", &a, &b))
    {
        printf("%d %d\n", lower(a) + lower(b), upper(a) + upper(b));
    }
    return 0;
}
