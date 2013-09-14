#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;

int possion_rand(double lambda)
{
    int x = 0;
    double b = 1.0;
    double c = exp(-lambda);
    do
    {
        double u = ((rand() % 10000) + 1) / 10000.0;
        b *= u;
        if (b >= c)
        {
            ++x;
        }
    }
    while (b >= c);
    return x;
}

int main()
{
    srand(time(0));
    for (int i = 0; i < 100; ++i)
    {
        printf("%d\t", possion_rand(10));
    }
    return 0;
}
