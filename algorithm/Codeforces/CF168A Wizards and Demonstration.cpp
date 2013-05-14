#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int n, x, y;
    while(~scanf("%d%d%d", &n, &x, &y))
    {
        printf("%d\n", max(0, (int)ceil(n * y * 0.01) - x));
    }
    return 0;
}
