#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c))
    {
        if (a == 0)
        {
            printf("0.00\n");
        }
        else
        {
            int idet = b * b - 4 * a * c;
            if (idet <= 0)
            {
                printf("0.00\n");
            }
            else
            {
                double det = sqrt((double)idet);
                double left = (- b - det) / a * 0.5;
                double right = (- b + det) / a * 0.5;
                double upper = a * right * right * right / 3 + b * right * right * 0.5 + c * right;
                double lower = a * left * left * left / 3 + b * left * left * 0.5 + c * left;
                printf("%.2lf\n", fabs(upper - lower));
            }
        }
    }
    return 0;
}
