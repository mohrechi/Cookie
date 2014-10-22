#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
        {
            printf("%d ", (n << 4) + i);
        }
    }
    return 0;
}
