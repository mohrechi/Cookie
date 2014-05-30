#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    double p = (sqrt(5.0) + 1.0) * 0.5;
    int a, b;
    while (~scanf("%d%d", &a, &b))
    {
        if (a > b)
        {
            swap(a, b);
        }
        printf("%d\n", a != (int)(p * (b - a)));
    }
    return 0;
}
