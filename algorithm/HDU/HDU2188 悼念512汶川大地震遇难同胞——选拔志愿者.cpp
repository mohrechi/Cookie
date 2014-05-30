#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int c, n, m;
    scanf("%d", &c);
    while (c--)
    {
        scanf("%d%d", &n, &m);
        if (n % (m + 1))
        {
            puts("Grass");
        }
        else
        {
            puts("Rabbit");
        }
    }
    return 0;
}
