#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int index;
    double a, b, c, d;
    double value, temp;
    while (~scanf("%lf%lf%lf%lf", &a, &b, &c, &d))
    {
        index = 0;
        value = a / c + b / d;
        temp = c / d + a / b;
        if (temp > value)
        {
            index = 1;
            value = temp;
        }
        temp = d / b + c / a;
        if (temp > value)
        {
            index = 2;
            value = temp;
        }
        temp = b / a + d / c;
        if (temp > value)
        {
            index = 3;
        }
        printf("%d\n", index);
    }
    return 0;
}
