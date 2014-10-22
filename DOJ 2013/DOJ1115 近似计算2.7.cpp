#include <cstdio>
const double EPS = 1e-6;

int main()
{
    double pi = 0.0;
    for (int i = 0; ; ++i)
    {
        double a = 1.0 / ((i << 1) + 1);
        if (a < EPS)
        {
            break;
        }
        if (i & 1)
        {
            pi -= a;
        }
        else
        {
            pi += a;
        }
    }
    printf("%.6lf\n", pi);
    return 0;
}
